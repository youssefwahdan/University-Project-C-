#include "Database.h"
#using <System.Configuration.dll>
#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Configuration;
using namespace System::Drawing;

namespace UniversityProject {
    public ref class ProfessorCoursesControl : public System::Windows::Forms::UserControl
    {
    public:
        ProfessorCoursesControl(int ProfessorID) { 
            InitializeComponent();
			db = gcnew Database(GetConnectionString());
            this->ProfessorID = ProfessorID;
            LoadCoursesAndFilter(ProfessorID);
        }

    private:
        DataGridView^ dgvCourses;
        ComboBox^ cbAcademicYear;
        ComboBox^ cbAcademicLevel;
        Button^ btnExport;
        DataTable^ courseTable;
		Database^ db;
        int ProfessorID;

        void InitializeComponent(void)
        {
            // Create DataTable
            this->courseTable = gcnew DataTable();
            this->courseTable->Columns->Add("CourseID", Int32::typeid);
            this->courseTable->Columns->Add("CourseName", String::typeid);
            this->courseTable->Columns->Add("Section", String::typeid);
            this->courseTable->Columns->Add("Group", String::typeid);
            this->courseTable->Columns->Add("Schedule", String::typeid);
            this->courseTable->Columns->Add("AcademicYear", String::typeid);
            this->courseTable->Columns->Add("AcademicLevel", String::typeid);
            // --- DataGridView ---
            this->dgvCourses = gcnew DataGridView();
            this->dgvCourses->Location = Point(20, 60);
            this->dgvCourses->Size = System::Drawing::Size(800, 300);
            this->dgvCourses->AllowUserToAddRows = false;
            this->dgvCourses->ReadOnly = true;
            this->dgvCourses->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            this->dgvCourses->DataSource = courseTable;


            // --- Filters ---
            this->cbAcademicYear = gcnew ComboBox();
            this->cbAcademicYear->Location = Point(20, 20);
            this->cbAcademicYear->Size = System::Drawing::Size(150, 25);
            this->cbAcademicYear->DropDownStyle = ComboBoxStyle::DropDownList;
            this->cbAcademicYear->Items->Add("All Years");
            this->cbAcademicYear->SelectedIndex = 0;
            //this->cbAcademicYear->SelectedIndexChanged += gcnew EventHandler(this, &ProfessorCoursesControl::LoadCoursesAndFilter);

            this->cbAcademicLevel = gcnew ComboBox();
            this->cbAcademicLevel->Location = Point(200, 20);
            this->cbAcademicLevel->Size = System::Drawing::Size(150, 25);
            this->cbAcademicLevel->DropDownStyle = ComboBoxStyle::DropDownList;
            this->cbAcademicLevel->Items->Add("All Levels");
            this->cbAcademicLevel->SelectedIndex = 0;
            //this->cbAcademicLevel->SelectedIndexChanged += gcnew EventHandler(this, &ProfessorCoursesControl::LoadCoursesAndFilter);

            // --- Export Button ---
            this->btnExport = gcnew Button();
            this->btnExport->Location = Point(380, 20);
            this->btnExport->Size = System::Drawing::Size(120, 25);
            this->btnExport->Text = "Export Roster";
            this->btnExport->Click += gcnew EventHandler(this, &ProfessorCoursesControl::ExportRoster);

            // --- Add controls ---
            this->Controls->Add(this->dgvCourses);
            this->Controls->Add(this->cbAcademicYear);
            this->Controls->Add(this->cbAcademicLevel);
            this->Controls->Add(this->btnExport);
            this->Size = System::Drawing::Size(860, 400);
        }

        void FilterData(Object^ sender, EventArgs^ e)
        {
            String^ levelFilter = Convert::ToString(this->cbAcademicLevel->SelectedItem);
            String^ yearFilter = Convert::ToString(this->cbAcademicYear->SelectedItem);

            String^ filter = "";

            if (yearFilter != "All Years")
                filter += "AcademicYear = '" + yearFilter + "'";

            if (levelFilter != "All Levels")
            {
                if (filter != "") filter += " AND ";
                filter += "AcademicLevel = '" + levelFilter + "'";
            }

            (safe_cast<DataTable^>(this->dgvCourses->DataSource))->DefaultView->RowFilter = filter;
        }

        void ExportRoster(Object^ sender, EventArgs^ e)
        {
            MessageBox::Show("Export roster clicked! (Implement CSV/PDF export here)");
        }


        void LoadCoursesAndFilter(int professorID)
        {
            SqlConnection^ conn = gcnew SqlConnection(db->connectionString);

            try
            {
                conn->Open();

                // 1) Get offerings for professor
                SqlCommand^ cmdOfferings = gcnew SqlCommand(
                    "SELECT * FROM CourseOffering WHERE ProfessorID=@pid", conn);
                cmdOfferings->Parameters->AddWithValue("@pid", professorID);

                SqlDataAdapter^ adapter = gcnew SqlDataAdapter(cmdOfferings);
                DataTable^ dtOfferings = gcnew DataTable();
                adapter->Fill(dtOfferings);

                this->cbAcademicYear->Items->Clear();
                this->cbAcademicLevel->Items->Clear();

                this->cbAcademicYear->Items->Add("All Years");
                this->cbAcademicLevel->Items->Add("All Levels");

                for each (DataRow ^ row in dtOfferings->Rows)
                {
                    int courseID = Convert::ToInt32(row["CourseID"]);
                    String^ section = row["SectionNumber"]->ToString();
                    String^ group = row["GroupNumber"]->ToString();
                    String^ schedule = row["ScheduleDescription"]->ToString();
                    int yearID = Convert::ToInt32(row["AcademicYearID"]);
                    int levelID = Convert::ToInt32(row["AcademicLevelID"]);


                    // 2) Course name
                    SqlCommand^ cmdCourse = gcnew SqlCommand("SELECT Name FROM Course WHERE CourseID=@cid", conn);
                    cmdCourse->Parameters->AddWithValue("@cid", courseID);
                    String^ courseName = "";
                    SqlDataReader^ rCourse = cmdCourse->ExecuteReader();
                    if (rCourse->Read()) courseName = rCourse["Name"]->ToString();
                    rCourse->Close();

                    // 3) Academic year
                    SqlCommand^ cmdYear = gcnew SqlCommand("SELECT YearName FROM AcademicYear WHERE AcademicYearID=@yid", conn);
                    cmdYear->Parameters->AddWithValue("@yid", yearID);
                    String^ yearName = "";
                    SqlDataReader^ rYear = cmdYear->ExecuteReader();
                    if (rYear->Read()) yearName = rYear["YearName"]->ToString();
                    rYear->Close();

                    // 4) Academic level
                    SqlCommand^ cmdLevel = gcnew SqlCommand("SELECT LevelName FROM AcademicLevel WHERE AcademicLevelID=@lid", conn);
                    cmdLevel->Parameters->AddWithValue("@lid", levelID);
                    String^ levelName = "";
                    SqlDataReader^ rLevel = cmdLevel->ExecuteReader();
                    if (rLevel->Read()) levelName = rLevel["LevelName"]->ToString();
                    rLevel->Close();

                    // 5) Add row to DataGridView
                    courseTable->Rows->Add(courseID, courseName, section, group, schedule, yearName, levelName);

                    // 6) Populate filters (distinct values)
                    if (!this->cbAcademicYear->Items->Contains(yearName))
                        this->cbAcademicYear->Items->Add(yearName);
                    if (!this->cbAcademicLevel->Items->Contains(levelName))
                        this->cbAcademicLevel->Items->Add(levelName);

                }


                this->dgvCourses->DataSource = courseTable;
                this->cbAcademicYear->SelectedIndex = 0;
                this->cbAcademicLevel->SelectedIndex = 0;
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error loading courses: " + ex->Message);
            }
            finally
            {
                conn->Close();
            }
        }
        String^ GetConnectionString()
        {
            // Use System::Configuration::ConfigurationManager to access connection strings
            return System::Configuration::ConfigurationManager::ConnectionStrings["UniversityDb"]->ConnectionString;
        }
    };
}
