#using <System.Configuration.dll>
#include "Database.h"
#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Windows::Forms::DataVisualization::Charting;
using namespace System::Configuration;

public ref class AttendanceControl : public System::Windows::Forms::UserControl
{
public:
    AttendanceControl(int StudentID)
    {
        InitializeComponent();
        db = gcnew Database(GetConnectionString());
        LoadAttendance(StudentID);
    }

private:
    DataGridView^ dgvAttendance;
    ProgressBar^ progressBarAttendance;
    Label^ lblPercent;
    Chart^ chartAttendance;
    Database^ db;
public:
    void InitializeComponent(void)
    {
        this->dgvAttendance = gcnew DataGridView();
        this->progressBarAttendance = gcnew ProgressBar();
        this->lblPercent = gcnew Label();
        this->chartAttendance = gcnew Chart();

        // --- DataGridView ---
        this->dgvAttendance->Location = Point(20, 20);
        this->dgvAttendance->Size = System::Drawing::Size(600, 250);
        this->dgvAttendance->AllowUserToAddRows = false;
        this->dgvAttendance->ReadOnly = true;
        this->dgvAttendance->ColumnCount = 3;
        this->dgvAttendance->Columns[0]->Name = "Course";
        this->dgvAttendance->Columns[1]->Name = "Lecture Date";
        this->dgvAttendance->Columns[2]->Name = "Status";

        // --- ProgressBar ---
        this->progressBarAttendance->Location = Point(20, 290);
        this->progressBarAttendance->Size = System::Drawing::Size(300, 25);
        this->progressBarAttendance->Minimum = 0;
        this->progressBarAttendance->Maximum = 100;

        // --- Label for percentage ---
        this->lblPercent->Location = Point(330, 290);
        this->lblPercent->Size = System::Drawing::Size(100, 25);
        this->lblPercent->Text = "0%";

        // --- Pie Chart ---
        ChartArea^ chartArea1 = gcnew ChartArea();
        this->chartAttendance->ChartAreas->Add(chartArea1);
        this->chartAttendance->Location = Point(450, 290);
        this->chartAttendance->Size = System::Drawing::Size(300, 200);

        Series^ series1 = gcnew Series("Attendance");
        series1->ChartType = SeriesChartType::Pie;
        this->chartAttendance->Series->Add(series1);

        // --- Add controls ---
        this->Controls->Add(this->dgvAttendance);
        this->Controls->Add(this->progressBarAttendance);
        this->Controls->Add(this->lblPercent);
        this->Controls->Add(this->chartAttendance);

        this->Size = System::Drawing::Size(800, 520);
    }

public:
    // Method to update progress bar and chart
    void UpdateAttendanceStats(int attended, int total)
    {
        if (total == 0) return;
        double percent = (double)attended / total * 100;

        this->progressBarAttendance->Value = (int)percent;
        this->lblPercent->Text = percent.ToString("F1") + "%";

        this->chartAttendance->Series["Attendance"]->Points->Clear();
        this->chartAttendance->Series["Attendance"]->Points->AddXY("Present", attended);
        this->chartAttendance->Series["Attendance"]->Points->AddXY("Absent", total - attended);
    };
public: void LoadAttendance(int studentID)
{

    // 1. Get all StudentCourses for this student
    SqlDataReader^ scReader = db->ExecuteReader(
        "SELECT * FROM StudentCourses WHERE StudentID=@sid",
        gcnew array<SqlParameter^>{ gcnew SqlParameter("@sid", studentID) });

    while (scReader->Read())
    {
        int courseID = scReader["CourseID"] == DBNull::Value ? 0 : Convert::ToInt32(scReader["CourseID"]);
        String^ section = scReader["Section"]->ToString();
        String^ group = scReader["Group"]->ToString();
        String^ schedule = scReader["Schedule"]->ToString();

        // 2. Match to CourseOffering to get OfferingID
        SqlDataReader^ offeringReader = db->ExecuteReader(
            "SELECT OfferingID FROM CourseOffering WHERE CourseID=@cid AND SectionNumber=@sec AND GroupNumber=@grp AND ScheduleDescription=@sched",
            gcnew array<SqlParameter^>{
                gcnew SqlParameter("@cid", courseID),
                gcnew SqlParameter("@sec", section),
                gcnew SqlParameter("@grp", group),
                gcnew SqlParameter("@sched", schedule)
        });

        int offeringID = 0;
        if (offeringReader->Read())
            offeringID = Convert::ToInt32(offeringReader["OfferingID"]);
        offeringReader->Close();

        if (offeringID == 0) continue; // skip if no match

        // 3. Get course name
        SqlDataReader^ courseReader = db->ExecuteReader(
            "SELECT Name FROM Course WHERE CourseID=@cid",
            gcnew array<SqlParameter^>{ gcnew SqlParameter("@cid", courseID) });

        String^ courseName = "";
        if (courseReader->Read())
            courseName = courseReader["Name"]->ToString();
        courseReader->Close();

        // 4. Get lectures for this offering
        SqlDataReader^ lectureReader = db->ExecuteReader(
            "SELECT * FROM Lecture WHERE OfferingID=@oid",
            gcnew array<SqlParameter^>{ gcnew SqlParameter("@oid", offeringID) });

        int totalLectures = 0;
        int attendedLectures = 0;

        while (lectureReader->Read())
        {
            int lectureID = Convert::ToInt32(lectureReader["LectureID"]);
            DateTime lectureDate = Convert::ToDateTime(lectureReader["LectureDate"]);

            // 5. Get attendance for this lecture
            SqlDataReader^ attReader = db->ExecuteReader(
                "SELECT Status FROM Attendance WHERE LectureID=@lid AND StudentID=@sid",
                gcnew array<SqlParameter^>{
                gcnew SqlParameter("@lid", lectureID),
                    gcnew SqlParameter("@sid", studentID)
            });

            String^ status = "Absent";
            if (attReader->Read())
                status = attReader["Status"]->ToString();
            attReader->Close();

            // Count totals
            totalLectures++;
            if (status == "Present") attendedLectures++;

            // 6. Add row to DataGridView
            this->dgvAttendance->Rows->Add(courseName, lectureDate.ToShortDateString(), status);
        }
        lectureReader->Close();

        // 7. Update progress bar and chart
        UpdateAttendanceStats(attendedLectures, totalLectures);
    }
    scReader->Close();
}

      String^ GetConnectionString()
      {
          // Use System::Configuration::ConfigurationManager to access connection strings
          return System::Configuration::ConfigurationManager::ConnectionStrings["UniversityDb"]->ConnectionString;
      }
};