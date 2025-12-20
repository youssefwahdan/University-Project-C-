#using <System.Configuration.dll>
#include "Database.h"
#pragma once
#include "DetailedGradesForm.h"
using namespace System::Configuration;
public ref class CoursesGradesControl : public System::Windows::Forms::UserControl
{
private:
    System::Windows::Forms::DataGridView^ dgvCourses;
    System::Windows::Forms::DataGridViewTextBoxColumn^ dgvtbcCourseCode;
    System::Windows::Forms::DataGridViewTextBoxColumn^ dgvtbcGradeID;
    System::Windows::Forms::DataGridViewTextBoxColumn^ dgvtbcCourseName;
    System::Windows::Forms::DataGridViewTextBoxColumn^ dgvtbcSection;
    System::Windows::Forms::DataGridViewTextBoxColumn^ dgvtbcGroup;
    System::Windows::Forms::DataGridViewTextBoxColumn^ dgvtbcSchedule;
    System::Windows::Forms::DataGridViewTextBoxColumn^ dgvtbcFinalGrade;
    System::Windows::Forms::DataGridViewTextBoxColumn^ dgvtbcEvaluation;
    System::Windows::Forms::DataGridViewTextBoxColumn^ dgvtbcGPA;
    System::Windows::Forms::Button^ btnViewDetails;
    Database^ db;
    int StudentID;
    int CourseID;
    int StudentCourseID;
    String^ Section;
    String^ Group;
    String^ Schedule;
    String^ CourseName;
    String^ CourseCode;
    int GradeID;
    String^ FinalGrade;
    String^ Evaluation;
    String^ GPA;

public:
    CoursesGradesControl(int SID)
    {
        InitializeComponent();
        db = gcnew Database(GetConnectionString());
        StudentID = SID;
        LoadStudentCourses();
        LoadCourses();
        LoadGrades();
    }

private:
    void InitializeComponent()
    {
        this->dgvCourses = (gcnew System::Windows::Forms::DataGridView());
        this->btnViewDetails = (gcnew System::Windows::Forms::Button());
        this->dgvtbcCourseCode = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dgvtbcGradeID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dgvtbcCourseName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dgvtbcSection = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dgvtbcGroup = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dgvtbcSchedule = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dgvtbcFinalGrade = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dgvtbcEvaluation = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dgvtbcGPA = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCourses))->BeginInit();
        this->SuspendLayout();
        // 
        // dgvCourses
        // 
        this->dgvCourses->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
        this->dgvCourses->ColumnHeadersHeight = 29;
        this->dgvCourses->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
            this->dgvtbcCourseCode,
            this->dgvtbcGradeID,
            this->dgvtbcCourseName, 
            this->dgvtbcSection, 
            this->dgvtbcGroup, 
            this->dgvtbcSchedule,
            this->dgvtbcFinalGrade, 
            this->dgvtbcEvaluation, 
            this->dgvtbcGPA
        });
        this->dgvCourses->Dock = System::Windows::Forms::DockStyle::Top;
        this->dgvCourses->Location = System::Drawing::Point(0, 0);
        this->dgvCourses->Name = L"dgvCourses";
        this->dgvCourses->RowHeadersWidth = 51;
        this->dgvCourses->Size = System::Drawing::Size(749, 250);
        this->dgvCourses->TabIndex = 0;
        // 
        // btnViewDetails
        // 
        this->btnViewDetails->Dock = System::Windows::Forms::DockStyle::Bottom;
        this->btnViewDetails->Location = System::Drawing::Point(0, 291);
        this->btnViewDetails->Name = L"btnViewDetails";
        this->btnViewDetails->Size = System::Drawing::Size(749, 40);
        this->btnViewDetails->TabIndex = 1;
        this->btnViewDetails->Text = L"View Detailed Grades";
        this->btnViewDetails->Click += gcnew System::EventHandler(this, &CoursesGradesControl::btnViewDetails_Click);
        // 
        // dgvtbcCourseCode
        // 
        this->dgvtbcCourseCode->HeaderText = L"Course Code";
        this->dgvtbcCourseCode->MinimumWidth = 6;
        this->dgvtbcCourseCode->Name = L"CourseCode";
        //
        // dgvtbcGradeID
        //
        this->dgvtbcGradeID->HeaderText = L"Grade ID";
        this->dgvtbcGradeID->MinimumWidth = 6;
        this->dgvtbcGradeID->Name = L"GradeID";
        // 
        // dgvtbcCourseName
        // 
        this->dgvtbcCourseName->HeaderText = L"Course Name";
        this->dgvtbcCourseName->MinimumWidth = 6;
        this->dgvtbcCourseName->Name = L"CourseName";
        // 
        // dgvtbcSection
        // 
        this->dgvtbcSection->HeaderText = L"Section";
        this->dgvtbcSection->MinimumWidth = 6;
        this->dgvtbcSection->Name = L"Section";
        // 
        // dgvtbcGroup
        // 
        this->dgvtbcGroup->HeaderText = L"Group";
        this->dgvtbcGroup->MinimumWidth = 6;
        this->dgvtbcGroup->Name = L"Group";
        // 
        // dgvtbcSchedule
        // 
        this->dgvtbcSchedule->HeaderText = L"Schedule";
        this->dgvtbcSchedule->MinimumWidth = 6;
        this->dgvtbcSchedule->Name = L"Schedule";
        // 
        // dgvtbcFinalGrade
        // 
        this->dgvtbcFinalGrade->HeaderText = L"Final Grade (%)";
        this->dgvtbcFinalGrade->MinimumWidth = 6;
        this->dgvtbcFinalGrade->Name = L"FinalGrade";
        // 
        // dgvtbcEvaluation
        // 
        this->dgvtbcEvaluation->HeaderText = L"Evaluation";
        this->dgvtbcEvaluation->MinimumWidth = 6;
        this->dgvtbcEvaluation->Name = L"Evaluation";
        // 
        // dgvtbcGPA
        // 
        this->dgvtbcGPA->HeaderText = L"GPA";
        this->dgvtbcGPA->MinimumWidth = 6;
        this->dgvtbcGPA->Name = L"GPA";
        // 
        // CoursesGradesControl
        // 
        this->Controls->Add(this->dgvCourses);
        this->Controls->Add(this->btnViewDetails);
        this->Name = L"CoursesGradesControl";
        this->Size = System::Drawing::Size(749, 331);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCourses))->EndInit();
        this->ResumeLayout(false);

    }

    // Event handler for button click
    void btnViewDetails_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (dgvCourses->CurrentRow != nullptr)
        {
            int gradeID = Convert::ToInt32(dgvCourses->CurrentRow->Cells["GradeID"]->Value);
            String^ courseCode = dgvCourses->CurrentRow->Cells["CourseCode"]->Value->ToString();
            DetailedGradesForm^ details = gcnew DetailedGradesForm(gradeID, courseCode);
            details->ShowDialog();
        }
    }
    void LoadStudentCourses() {
        try {
        SqlDataReader^ reader = db->LoadStudentCourses(StudentID);
            if (reader->Read()) {
                CourseID = Convert::ToInt32(reader["CourseID"]);
                StudentCourseID = Convert::ToInt32(reader["StudentCourseID"]);
                Section = reader["Section"]->ToString();
                Group = reader["Group"]->ToString();
                Schedule = reader["Schedule"]->ToString();
            }
            reader->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message);
        }
    }
    void LoadCourses() {
        try {
        SqlDataReader^ reader = db->LoadCourse(CourseID);
            if (reader->Read()) {
                CourseCode = reader["Code"]->ToString(); 
                CourseName = reader["Name"]->ToString();
            }
            reader->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message);
        }
    }
    void LoadGrades() {
        try {
        SqlDataReader^ reader = db->LoadGrades(StudentCourseID);
            if (reader->Read()) {
                GradeID = Convert::ToInt32(reader["GradeID"]);
                FinalGrade = reader["FinalGrade"]->ToString(); 
                Evaluation = reader["Evaluation"]->ToString();
                GPA = reader["GPA"]->ToString();
                this->dgvCourses->Rows->Add(this->CourseCode, this->GradeID, this->CourseName, this->Section, this->Group, this->Schedule, this->FinalGrade, this->Evaluation, this->GPA);

            }
            reader->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message);
        }
    }
    String^ GetConnectionString()
    {
        // Use System::Configuration::ConfigurationManager to access connection strings
        return System::Configuration::ConfigurationManager::ConnectionStrings["UniversityDb"]->ConnectionString;
    }
};
