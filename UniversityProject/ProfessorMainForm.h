
#using <System.Configuration.dll>
#include "GPAControl.h"
#include "ProfessorAttendanceControl.h"
#include "ProfessorCoursesControl.h"
#include "ProfessorProfileControl.h"


#pragma once
using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Windows::Forms;
using namespace System::Configuration;


namespace UniversityProject {
    public ref class ProfessorMainForm : public System::Windows::Forms::Form
    {
    public:
        ProfessorMainForm(int id)
        {
            InitializeComponent();
            db = gcnew Database(GetConnectionString());
            ProfessorID = id;
            LoadProfessorData();

        }

    protected:
        ~ProfessorMainForm()
        {
            if (components)
                delete components;
        }

    private:
        Database^ db;
        System::Windows::Forms::Button^ btnCourses;
        System::Windows::Forms::Button^ btnProfile;
        System::Windows::Forms::Button^ btnAttendance;
        System::Windows::Forms::Button^ btnLogout;
        System::Windows::Forms::Label^ welcomeLabel;
        System::Windows::Forms::Panel^ sidebarPanel;
        System::Windows::Forms::Panel^ sectionsPanel;
        System::Windows::Forms::Panel^ navbar;
        System::ComponentModel::IContainer^ components;
    public:
        int ProfessorID;
        String^ Code;
        String^ FirstName;
        String^ LastName;
        String^ Gender;
        DateTime BirthDate;
        String^ Email;
        String^ Phone;
        int DepartmentID;
        String^ DepartmentName;
        int FacultyID;
        String^ FacultyName;
        DateTime HireDate;
        int AcademicLevelID;

        String^ AcademicLevelName;



        void InitializeComponent()
        {
            this->btnCourses = (gcnew System::Windows::Forms::Button());
            this->btnProfile = (gcnew System::Windows::Forms::Button());
            this->btnAttendance = (gcnew System::Windows::Forms::Button());
            this->welcomeLabel = (gcnew System::Windows::Forms::Label());
            this->btnLogout = (gcnew System::Windows::Forms::Button());
            this->sidebarPanel = (gcnew System::Windows::Forms::Panel());
            this->sectionsPanel = (gcnew System::Windows::Forms::Panel());
            this->navbar = (gcnew System::Windows::Forms::Panel());
            this->sidebarPanel->SuspendLayout();
            this->navbar->SuspendLayout();
            this->SuspendLayout();
            // 
            // btnCourses
            // 
            this->btnCourses->BackColor = System::Drawing::Color::OliveDrab;
            this->btnCourses->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnCourses->Dock = System::Windows::Forms::DockStyle::Top;
            this->btnCourses->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnCourses->Location = System::Drawing::Point(10, 70);
            this->btnCourses->Name = L"btnCourses";
            this->btnCourses->Size = System::Drawing::Size(180, 50);
            this->btnCourses->TabIndex = 1;
            this->btnCourses->Text = L"Courses";
            this->btnCourses->UseVisualStyleBackColor = false;
            this->btnCourses->Click += gcnew System::EventHandler(this, &ProfessorMainForm::btnCourses_Click);
            // 
            // btnProfile
            // 
            this->btnProfile->BackColor = System::Drawing::Color::DarkSlateGray;
            this->btnProfile->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnProfile->Dock = System::Windows::Forms::DockStyle::Top;
            this->btnProfile->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnProfile->Location = System::Drawing::Point(10, 20);
            this->btnProfile->Name = L"btnProfile";
            this->btnProfile->Size = System::Drawing::Size(180, 50);
            this->btnProfile->TabIndex = 2;
            this->btnProfile->Text = L"Profile";
            this->btnProfile->UseVisualStyleBackColor = false;
            this->btnProfile->Click += gcnew System::EventHandler(this, &ProfessorMainForm::btnProfile_Click);
            // 
            // btnAttendance
            // 
            this->btnAttendance->BackColor = System::Drawing::Color::Orange;
            this->btnAttendance->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnAttendance->Dock = System::Windows::Forms::DockStyle::Top;
            this->btnAttendance->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnAttendance->Location = System::Drawing::Point(10, 120);
            this->btnAttendance->Name = L"btnAttendance";
            this->btnAttendance->Size = System::Drawing::Size(180, 50);
            this->btnAttendance->TabIndex = 0;
            this->btnAttendance->Text = L"Attendance";
            this->btnAttendance->UseVisualStyleBackColor = false;
            this->btnAttendance->Click += gcnew System::EventHandler(this, &ProfessorMainForm::btnAttendance_Click);
            // 
            // welcomeLabel
            // 
            this->welcomeLabel->AutoSize = true;
            this->welcomeLabel->BackColor = System::Drawing::Color::Transparent;
            this->welcomeLabel->Dock = System::Windows::Forms::DockStyle::Left;
            this->welcomeLabel->Font = (gcnew System::Drawing::Font(L"Segoe Script", 12, System::Drawing::FontStyle::Bold));
            this->welcomeLabel->ForeColor = System::Drawing::Color::Black;
            this->welcomeLabel->Location = System::Drawing::Point(0, 0);
            this->welcomeLabel->Name = L"welcomeLabel";
            this->welcomeLabel->Size = System::Drawing::Size(0, 33);
            this->welcomeLabel->TabIndex = 3;
            // 
            // btnLogout
            // 
            this->btnLogout->BackColor = System::Drawing::Color::Red;
            this->btnLogout->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnLogout->Dock = System::Windows::Forms::DockStyle::Right;
            this->btnLogout->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnLogout->Location = System::Drawing::Point(643, 0);
            this->btnLogout->Name = L"btnLogout";
            this->btnLogout->Size = System::Drawing::Size(75, 40);
            this->btnLogout->TabIndex = 4;
            this->btnLogout->Text = L"Logout";
            this->btnLogout->UseVisualStyleBackColor = false;
            this->btnLogout->Click += gcnew System::EventHandler(this, &ProfessorMainForm::btnLogout_Click);
            // 
            // sidebarPanel
            // 
            this->sidebarPanel->BackColor = System::Drawing::Color::DarkGray;
            this->sidebarPanel->Controls->Add(this->btnAttendance);
            this->sidebarPanel->Controls->Add(this->btnCourses);
            this->sidebarPanel->Controls->Add(this->btnProfile);
            this->sidebarPanel->Dock = System::Windows::Forms::DockStyle::Left;
            this->sidebarPanel->Location = System::Drawing::Point(0, 0);
            this->sidebarPanel->Name = L"sidebarPanel";
            this->sidebarPanel->Padding = System::Windows::Forms::Padding(10, 20, 10, 0);
            this->sidebarPanel->Size = System::Drawing::Size(200, 561);
            this->sidebarPanel->TabIndex = 5;
            // 
            // sectionsPanel
            // 
            this->sectionsPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->sectionsPanel->ForeColor = System::Drawing::Color::Black;
            this->sectionsPanel->Location = System::Drawing::Point(200, 40);
            this->sectionsPanel->Name = L"sectionsPanel";
            this->sectionsPanel->Size = System::Drawing::Size(718, 521);
            this->sectionsPanel->TabIndex = 6;
            // 
            // navbar
            // 
            this->navbar->Controls->Add(this->btnLogout);
            this->navbar->Controls->Add(this->welcomeLabel);
            this->navbar->Dock = System::Windows::Forms::DockStyle::Top;
            this->navbar->Location = System::Drawing::Point(200, 0);
            this->navbar->Name = L"navbar";
            this->navbar->Size = System::Drawing::Size(718, 40);
            this->navbar->TabIndex = 6;
            // 
            // ProfessorMainForm
            // 
            this->ClientSize = System::Drawing::Size(918, 561);
            this->Controls->Add(this->sectionsPanel);
            this->Controls->Add(this->navbar);
            this->Controls->Add(this->sidebarPanel);
            this->ForeColor = System::Drawing::Color::WhiteSmoke;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
            this->Name = L"ProfessorMainForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->sidebarPanel->ResumeLayout(false);
            this->navbar->ResumeLayout(false);
            this->navbar->PerformLayout();
            this->ResumeLayout(false);

        }

        void btnGPA_Click(System::Object^ sender, System::EventArgs^ e) {
            sectionsPanel->Controls->Clear();
            GPAControl^ control = gcnew GPAControl(ProfessorID);
            control->Dock = DockStyle::Fill;
            sectionsPanel->Controls->Add(control);
        }
        void btnAttendance_Click(System::Object^ sender, System::EventArgs^ e)
        {
            sectionsPanel->Controls->Clear();
            ProfessorAttendanceControl^ control = gcnew ProfessorAttendanceControl(ProfessorID);
            control->Dock = DockStyle::Fill;
            sectionsPanel->Controls->Add(control);
        }

        void btnCourses_Click(System::Object^ sender, System::EventArgs^ e)
        {

            sectionsPanel->Controls->Clear();

            ProfessorCoursesControl^ control = gcnew ProfessorCoursesControl(ProfessorID);
            control->Dock = DockStyle::Fill;
            sectionsPanel->Controls->Add(control);
        }

        void btnProfile_Click(System::Object^ sender, System::EventArgs^ e)
        {
            LoadDepartmentData();
            LoadFacultyData();
            sectionsPanel->Controls->Clear();
            ProfessorProfileControl^ control = gcnew ProfessorProfileControl(FirstName, LastName, DepartmentName, FacultyName, Code, HireDate);
            control->Dock = DockStyle::Fill;
            sectionsPanel->Controls->Add(control);

        }
        String^ GetConnectionString()
        {
            // Use System::Configuration::ConfigurationManager to access connection strings
            return System::Configuration::ConfigurationManager::ConnectionStrings["UniversityDb"]->ConnectionString;
        }

        System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {
            Application::Restart();
        }
        void LoadProfessorData()
        {
            try {
                SqlDataReader^ reader = db->LoadProfessorData(ProfessorID);
                if (reader->Read()) {
                    Code = reader["Code"]->ToString();
                    FirstName = reader["FirstName"]->ToString();
                    LastName = reader["LastName"]->ToString();
                    Email = reader["Email"]->ToString();
                    Phone = reader["Phone"]->ToString();
                    HireDate = Convert::ToDateTime(reader["HireDate"]);
                    DepartmentID = Convert::ToInt32(reader["DepartmentID"]);
                    FacultyID = Convert::ToInt32(reader["FacultyID"]);
                    this->welcomeLabel->Text = "Welcome, " + FirstName + " " + LastName + "!";
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message);
            }
        }
        void LoadDepartmentData()
        {
            try {
                SqlDataReader^ reader = db->LoadDepartmentData(DepartmentID);

                if (reader->Read()) {
                    DepartmentName = reader["Name"]->ToString();
                    // Use departmentName as needed
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message);
            }
        }
        void LoadFacultyData() {
            try {
                SqlDataReader^ reader = db->LoadFacultyData(FacultyID);
                if (reader->Read()) {
                    FacultyName = reader["Name"]->ToString();
                    // Use departmentName as needed
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message);
            }
        }



    };
}