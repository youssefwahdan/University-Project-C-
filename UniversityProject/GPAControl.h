#include "Database.h"
#using <System.Configuration.dll>
#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Windows::Forms::DataVisualization::Charting;
using namespace System::Data::SqlClient;
using namespace System::Configuration;

public ref class GPAControl : public System::Windows::Forms::UserControl
{
public:
    GPAControl(int StudentID)
    {
        InitializeComponent();
        LoadGPA(StudentID);
    }

private:
    DataGridView^ dgvGPA;
    Chart^ chartGPA;
	Database^ db;

    void InitializeComponent(void)
    {
        this->dgvGPA = gcnew DataGridView();
        this->chartGPA = gcnew Chart();


        // --- Chart ---
        ChartArea^ chartArea1 = gcnew ChartArea();
        this->chartGPA->ChartAreas->Add(chartArea1);
        this->chartGPA->Location = Point(450, 20);
        this->chartGPA->Size = System::Drawing::Size(400, 250);
		this->chartGPA->Titles->Add("GPA Trend Over Academic Years");
		this->chartGPA->Dock = DockStyle::Bottom;
		this->chartGPA->Visible = true;
        Series^ series1 = gcnew Series("GPA Trend");
        series1->ChartType = SeriesChartType::Line;

        this->chartGPA->Series->Add(series1);

        // --- DataGridView ---
        this->dgvGPA->Location = Point(20, 20);
        this->dgvGPA->Size = System::Drawing::Size(400, 250);
        this->dgvGPA->AllowUserToAddRows = false;
        this->dgvGPA->ReadOnly = true;
        this->dgvGPA->ColumnCount = 2;
        this->dgvGPA->Columns[0]->Name = "Academic Year";
        this->dgvGPA->Columns[1]->Name = "GPA";
		this->dgvGPA->Dock = DockStyle::Top;

        // --- Add controls ---
        this->Controls->Add(this->dgvGPA);
        this->Controls->Add(this->chartGPA);

        this->Size = System::Drawing::Size(880, 300);
    }
public: void LoadGPA(int studentID)
{
    // Map: YearName -> list of GPA doubles
    auto gpaMap = gcnew System::Collections::Generic::Dictionary<String^, System::Collections::Generic::List<double>^>();

    // 1) Get all StudentCourses rows for this student
    SqlDataReader^ scReader = db->ExecuteReader(
        "SELECT StudentCourseID, CourseID, Section, [Group], Schedule FROM StudentCourses WHERE StudentID=@sid",
        gcnew array<SqlParameter^>{ gcnew SqlParameter("@sid", studentID) });

    while (scReader->Read())
    {
        int studentCourseID = Convert::ToInt32(scReader["StudentCourseID"]);
        int courseID = scReader["CourseID"] == DBNull::Value ? 0 : Convert::ToInt32(scReader["CourseID"]);
        String^ section = scReader["Section"] == DBNull::Value ? "" : scReader["Section"]->ToString();
        String^ group = scReader["Group"] == DBNull::Value ? "" : scReader["Group"]->ToString();
        String^ schedule = scReader["Schedule"] == DBNull::Value ? "" : scReader["Schedule"]->ToString();

        if (courseID == 0) continue; // skip invalid

        // 2) Resolve matching CourseOffering to get AcademicYearID
        int academicYearID = 0;
        SqlDataReader^ coReader = db->ExecuteReader(
            "SELECT AcademicYearID FROM CourseOffering WHERE CourseID=@cid AND SectionNumber=@sec AND GroupNumber=@grp AND ScheduleDescription=@sched",
            gcnew array<SqlParameter^>{
            gcnew SqlParameter("@cid", courseID),
                gcnew SqlParameter("@sec", section),
                gcnew SqlParameter("@grp", group),
                gcnew SqlParameter("@sched", schedule)
        });
        if (coReader->Read())
            academicYearID = Convert::ToInt32(coReader["AcademicYearID"]);
        coReader->Close();
        if (academicYearID == 0) continue;

        // 3) Get Academic Year name
        String^ yearName = "Unknown";
        SqlDataReader^ ayReader = db->ExecuteReader(
            "SELECT YearName FROM AcademicYear WHERE AcademicYearID=@yid",
            gcnew array<SqlParameter^>{ gcnew SqlParameter("@yid", academicYearID) });
        if (ayReader->Read() && ayReader["YearName"] != DBNull::Value)
            yearName = ayReader["YearName"]->ToString();
        ayReader->Close();

        // 4) Get GPA from Grades using StudentCourseID
        SqlDataReader^ gradeReader = db->ExecuteReader(
            "SELECT GPA FROM Grades WHERE StudentCourseID=@scid",
            gcnew array<SqlParameter^>{ gcnew SqlParameter("@scid", studentCourseID) });

        while (gradeReader->Read())
        {
            if (gradeReader["GPA"] == DBNull::Value) continue;
            double gpa = Convert::ToDouble(gradeReader["GPA"]);
            if (!gpaMap->ContainsKey(yearName))
                gpaMap[yearName] = gcnew System::Collections::Generic::List<double>();
            gpaMap[yearName]->Add(gpa);
        }
        gradeReader->Close();
    }
    scReader->Close();

    // 5) Populate UI (average per year)
    this->dgvGPA->Rows->Clear();
    this->chartGPA->Series["GPA Trend"]->Points->Clear();

    // Order by year name if your YearName is sortable; otherwise, you can fetch AcademicYear table separately to order.
    for each (auto kvp in gpaMap)
    {
        auto list = kvp.Value;
        if (list->Count == 0) continue;

        double sum = 0; for each (double v in list) sum += v;
        double avg = sum / list->Count;

        this->dgvGPA->Rows->Add(kvp.Key, avg.ToString("F2"));
        this->chartGPA->Series["GPA Trend"]->Points->AddXY(kvp.Key, avg);
    }
}


};
