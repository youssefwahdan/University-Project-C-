#pragma once
#using <System.Configuration.dll>
#include "Database.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Configuration;

namespace UniversityProject {
    public ref class ProfessorGradesControl : public UserControl
    {
    public:
        ProfessorGradesControl(int professorID)
        {
            InitializeComponent();
            db = gcnew Database(GetConnectionString());
            currentProfessorID = professorID;
            LoadProfessorCourses(professorID);
        }

    private:
        ComboBox^ cbCourse;
        DataGridView^ dgvGrades;
        Button^ btnSaveGrades;
        int currentProfessorID;
        Database^ db;
        int CourseID;

        void InitializeComponent()
        {

            this->cbCourse = gcnew ComboBox();
            this->cbCourse->Location = Point(20, 20);
            this->cbCourse->Size = Drawing::Size(300, 25);
            this->cbCourse->DropDownStyle = ComboBoxStyle::DropDownList;
            this->cbCourse->SelectedIndexChanged += gcnew EventHandler(this, &ProfessorGradesControl::CourseChanged);
            
            this->btnSaveGrades = gcnew Button();
            this->btnSaveGrades->Text = "Save Grades";
            this->btnSaveGrades->Location = Point(340, 20);
            this->btnSaveGrades->Size = Drawing::Size(120, 25);
            this->btnSaveGrades->Click += gcnew EventHandler(this, &ProfessorGradesControl::SaveGrades);
            
            this->dgvGrades = gcnew DataGridView();
            this->dgvGrades->Location = Point(20, 60);
            this->dgvGrades->Size = Drawing::Size(900, 400);
            this->dgvGrades->AllowUserToAddRows = false;
            this->dgvGrades->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->dgvGrades->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

            this->Controls->Add(cbCourse);
            this->Controls->Add(btnSaveGrades);
            this->Controls->Add(dgvGrades);
            this->Padding = System::Windows::Forms::Padding(10);
        }

        // Load professor's offered courses
        void LoadProfessorCourses(int professorID)
        {
            cbCourse->Items->Clear();

            SqlConnection^ conn = gcnew SqlConnection(db->connectionString);

            try
            {
                conn->Open();
                SqlDataAdapter^ adapter = gcnew SqlDataAdapter(
                    "SELECT OfferingID, CourseID FROM CourseOffering WHERE ProfessorID = @pid", conn);
                adapter->SelectCommand->Parameters->AddWithValue("@pid", professorID);



                DataTable^ dt = gcnew DataTable();
                adapter->Fill(dt);


                for each (DataRow ^ row in dt->Rows)
                {
                    this->CourseID = Convert::ToInt32(row["CourseID"]);
                    SqlDataAdapter^ adapter2 = gcnew SqlDataAdapter(
                        "SELECT Name FROM Course WHERE CourseID = @cid", conn);
                    adapter2->SelectCommand->Parameters->AddWithValue("@cid", CourseID );
                    DataTable^ dt2 = gcnew DataTable();
                    adapter2->Fill(dt2);
                    for each (DataRow ^ row2 in dt2->Rows)
                    {
                        this->cbCourse->Items->Add(row["OfferingID"]->ToString() + " - " + row2["Name"]->ToString());
                    }

                }
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

        // When course changes, load students
        void CourseChanged(Object^ sender, EventArgs^ e)
        {
            if (cbCourse->SelectedItem != nullptr)
            {
                int offeredCourseID = Convert::ToInt32(cbCourse->SelectedItem->ToString()->Split('-')[0]->Trim());
                LoadStudentsForCourse(offeredCourseID);
            }
        }

        // Load students enrolled in course (NO JOIN)
        void LoadStudentsForCourse(int offeringID)
        {
            dgvGrades->Columns->Clear();
            dgvGrades->Rows->Clear();

            dgvGrades->Columns->Add("StudentID", "Student ID");
            dgvGrades->Columns->Add("StudentName", "Student Name");
            dgvGrades->Columns->Add("Ass1", "Ass1");
            dgvGrades->Columns->Add("Ass2", "Ass2");
            dgvGrades->Columns->Add("CW", "CW");
            dgvGrades->Columns->Add("Final Exam", "Final Exam");

            SqlConnection^ conn = gcnew SqlConnection(db->connectionString);

            try
            {
                conn->Open();

                // Step 1: Get enrolled student IDs
                SqlDataAdapter^ adapterStudent = gcnew SqlDataAdapter(
                    "SELECT StudentID FROM StudentCourses WHERE CourseID = @cid", conn);
                adapterStudent->SelectCommand->Parameters->AddWithValue("@cid", this->CourseID);

                DataTable^ dtEnroll = gcnew DataTable();
                adapterStudent->Fill(dtEnroll);

                // Step 2: For each student, fetch their name separately
                for each (DataRow ^ row in dtEnroll->Rows)
                {
                    int studentID = Convert::ToInt32(row["StudentID"]);
                    String^ studentName = "";
                    String^ Ass1 = "";
                    String^ Ass2 = "";
                    String^ CW = "";
                    String^ FinalExam = "";
                    int StudentCourseID;
                    int BreakdownID;

                    // Get student name
                    SqlCommand^ cmdStudent = gcnew SqlCommand("SELECT FirstName, LastName FROM Student WHERE StudentID = @sid", conn);
                    cmdStudent->Parameters->AddWithValue("@sid", studentID);

                    SqlDataReader^ reader = cmdStudent->ExecuteReader();
                    if (reader->Read())
                    {
                        studentName = reader["FirstName"]->ToString() + " " + reader["LastName"]->ToString();
                    }
                    reader->Close();

                    // Get StudentCourseID To get GradeID From Grades Table 

                    SqlCommand^ cmdStudentCourse = gcnew SqlCommand("SELECT StudentCourseID FROM StudentCourses WHERE CourseID = @cid AND StudentID = @sid", conn);
                    cmdStudentCourse->Parameters->AddWithValue("@cid", CourseID);
                    cmdStudentCourse->Parameters->AddWithValue("@sid", studentID);

                    SqlDataReader^ StudentCourseReader = cmdStudentCourse->ExecuteReader();
                    if (StudentCourseReader->Read()) {
                        StudentCourseID = Convert::ToInt32(StudentCourseReader["StudentCourseID"]);
                    }
                    StudentCourseReader->Close();

                    // Get GradeID to Get student grades breakdown from GradeBreakdown Table

                    SqlCommand^ cmdBreakdown = gcnew SqlCommand("SELECT BreakdownID FROM Grades WHERE StudentCourseID = @scid", conn);
                    cmdBreakdown->Parameters->AddWithValue("@scid", StudentCourseID);

                    SqlDataReader^ BreakdownReader = cmdBreakdown->ExecuteReader();
                    if (BreakdownReader->Read()) {
                        BreakdownID = Convert::ToInt32(BreakdownReader["BreakdownID"]);
                    }
                    BreakdownReader->Close();

                    // Get data from GradeBreakdown table by gradeID
                    SqlCommand^ cmdGradeBreakdown = gcnew SqlCommand("SELECT * FROM GradeBreakdown WHERE BreakdownID = @bdid", conn);
                    cmdGradeBreakdown->Parameters->AddWithValue("@bdid", BreakdownID);

                    SqlDataReader^ GradeBreakdownReader = cmdGradeBreakdown->ExecuteReader();
                    if (GradeBreakdownReader->Read()) {
                        Ass1 = GradeBreakdownReader["Ass1"]->ToString();
                        Ass2 = GradeBreakdownReader["Ass2"]->ToString();
                        CW = GradeBreakdownReader["CW"]->ToString();
                        FinalExam = GradeBreakdownReader["FinalExam"]->ToString();
                    }
                    GradeBreakdownReader->Close();
                    this->dgvGrades->Rows->Add(studentID.ToString(), studentName, Ass1, Ass2, CW, FinalExam);
                }
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error loading students: " + ex->Message);
            }
            finally
            {
                conn->Close();
            }
        }

        // Save grades to database
        void SaveGrades(Object^ sender, EventArgs^ e)
        {
            if (cbCourse->SelectedItem == nullptr)
            {
                MessageBox::Show("Select a course first.");
                return;
            }

            int offeredCourseID = Convert::ToInt32(cbCourse->SelectedItem->ToString()->Split('-')[0]->Trim());
            SqlConnection^ conn = gcnew SqlConnection(db->connectionString);

            try
            {
                conn->Open();

                for each (DataGridViewRow ^ row in dgvGrades->Rows)
                {
                    if (row->IsNewRow) continue;

                    int studentID = Convert::ToInt32(row->Cells["StudentID"]->Value);
                    double Ass1 = row->Cells["Ass1"]->Value == nullptr ? 0 : Convert::ToDouble(row->Cells["Ass1"]->Value);
                    double Ass2 = row->Cells["Ass2"]->Value == nullptr ? 0 : Convert::ToDouble(row->Cells["Ass2"]->Value);
                    double CW = row->Cells["CW"]->Value == nullptr ? 0 : Convert::ToDouble(row->Cells["CW"]->Value);
                    double FinalExam = row->Cells["Final Exam"]->Value == nullptr ? 0 : Convert::ToDouble(row->Cells["Final Exam"]->Value);
                    int StudentCourseID;
                    int GradeID;
                    int BreakdownID;
                    // Get StudentCourseID To get GradeID From Grades Table 

                    SqlCommand^ cmdStudentCourse = gcnew SqlCommand("SELECT StudentCourseID FROM StudentCourses WHERE StudentID = @cid", conn);
                    cmdStudentCourse->Parameters->AddWithValue("@cid", studentID);

                    SqlDataReader^ StudentCourseReader = cmdStudentCourse->ExecuteReader();
                    if (StudentCourseReader->Read()) {
                        StudentCourseID = Convert::ToInt32(StudentCourseReader["StudentCourseID"]);
                    }
                    StudentCourseReader->Close();

                    // Get BreakdownID from Grade Table

                    SqlCommand^ cmdBreakdown = gcnew SqlCommand("SELECT BreakdownID, GradeID FROM Grades WHERE StudentCourseID = @scid", conn);
                    cmdBreakdown->Parameters->AddWithValue("@scid", StudentCourseID);

                    SqlDataReader^ BreakdownReader = cmdBreakdown->ExecuteReader();
                    if (BreakdownReader->Read()) {
                        BreakdownID = Convert::ToInt32(BreakdownReader["BreakdownID"]);
                        GradeID = Convert::ToInt32(BreakdownReader["GradeID"]);
                    }
                    BreakdownReader->Close();

                    SqlCommand^ cmd = gcnew SqlCommand("UPDATE GradeBreakdown SET GradeID = @gid, Ass1 = @ass1, Ass2 = @ass2, CW = @cw, FinalExam = @final WHERE BreakdownID = @bdid", conn);

                    cmd->Parameters->AddWithValue("@gid", GradeID);
                    cmd->Parameters->AddWithValue("@ass1", Ass1);
                    cmd->Parameters->AddWithValue("@ass2", Ass2);
                    cmd->Parameters->AddWithValue("@cw", CW);
                    cmd->Parameters->AddWithValue("@final", FinalExam);
                    cmd->Parameters->AddWithValue("@bdid", BreakdownID);

                    cmd->ExecuteNonQuery();
                }

                MessageBox::Show("Grades saved successfully!");
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error saving grades: " + ex->Message);
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
