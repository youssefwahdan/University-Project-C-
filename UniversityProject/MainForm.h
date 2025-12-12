
#using <System.Configuration.dll>
#include "SubjectForm.h"
#include "GradeForm.h"
#include "StudentForm.h"
#pragma once
using namespace System::Windows::Forms;
using namespace System::Configuration;
namespace UniversityProject {
    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(void)
        {
            InitializeComponent();
            db = gcnew Database(GetConnectionString());

        }

    protected:
        ~MainForm()
        {
            if (components)
                delete components;
        }

    private:
        Database^ db;
        System::Windows::Forms::Button^ btnSubjects;
        System::Windows::Forms::Button^ btnGrades;
        System::Windows::Forms::Button^ btnStudents;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Button^ btnLogout;
        System::ComponentModel::IContainer^ components;


        void InitializeComponent(void)
        {
            this->btnSubjects = (gcnew System::Windows::Forms::Button());
            this->btnGrades = (gcnew System::Windows::Forms::Button());
            this->btnStudents = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->btnLogout = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // btnSubjects
            // 
            this->btnSubjects->BackColor = System::Drawing::Color::OliveDrab;
            this->btnSubjects->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnSubjects->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnSubjects->Location = System::Drawing::Point(12, 252);
            this->btnSubjects->Name = L"btnSubjects";
            this->btnSubjects->Padding = System::Windows::Forms::Padding(16, 0, 0, 0);
            this->btnSubjects->Size = System::Drawing::Size(677, 120);
            this->btnSubjects->TabIndex = 1;
            this->btnSubjects->Text = L"Manage Subjects";
            this->btnSubjects->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnSubjects->UseVisualStyleBackColor = false;
            this->btnSubjects->Click += gcnew System::EventHandler(this, &MainForm::btnSubjects_Click);
            // 
            // btnGrades
            // 
            this->btnGrades->BackColor = System::Drawing::Color::DarkSlateGray;
            this->btnGrades->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnGrades->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnGrades->Location = System::Drawing::Point(12, 378);
            this->btnGrades->Name = L"btnGrades";
            this->btnGrades->Padding = System::Windows::Forms::Padding(16, 0, 0, 0);
            this->btnGrades->Size = System::Drawing::Size(677, 120);
            this->btnGrades->TabIndex = 2;
            this->btnGrades->Text = L"Manage Grades";
            this->btnGrades->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnGrades->UseVisualStyleBackColor = false;
            this->btnGrades->Click += gcnew System::EventHandler(this, &MainForm::btnGrades_Click);
            // 
            // btnStudents
            // 
            this->btnStudents->BackColor = System::Drawing::Color::Orange;
            this->btnStudents->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnStudents->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnStudents->Location = System::Drawing::Point(12, 126);
            this->btnStudents->Name = L"btnStudents";
            this->btnStudents->Padding = System::Windows::Forms::Padding(16, 0, 0, 0);
            this->btnStudents->Size = System::Drawing::Size(677, 120);
            this->btnStudents->TabIndex = 0;
            this->btnStudents->Text = L"Manage Students";
            this->btnStudents->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->btnStudents->UseVisualStyleBackColor = false;
            this->btnStudents->Click += gcnew System::EventHandler(this, &MainForm::btnStudents_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Transparent;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe Script", 24, System::Drawing::FontStyle::Bold));
            this->label1->ForeColor = System::Drawing::Color::Black;
            this->label1->Location = System::Drawing::Point(12, 23);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(398, 67);
            this->label1->TabIndex = 3;
            this->label1->Text = L"Welcome, Admin";
            // 
            // btnLogout
            // 
            this->btnLogout->BackColor = System::Drawing::Color::Red;
            this->btnLogout->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnLogout->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnLogout->Location = System::Drawing::Point(670, 12);
            this->btnLogout->Name = L"btnLogout";
            this->btnLogout->Size = System::Drawing::Size(100, 40);
            this->btnLogout->TabIndex = 4;
            this->btnLogout->Text = L"Logout";
            this->btnLogout->UseVisualStyleBackColor = false;
            this->btnLogout->Click += gcnew System::EventHandler(this, &MainForm::btnLogout_Click);
            // 
            // MainForm
            // 
            this->ClientSize = System::Drawing::Size(782, 553);
            this->Controls->Add(this->btnLogout);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->btnStudents);
            this->Controls->Add(this->btnSubjects);
            this->Controls->Add(this->btnGrades);
            this->ForeColor = System::Drawing::Color::WhiteSmoke;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
            this->Name = L"MainForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        void btnStudents_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->Hide();
            StudentForm^ form = gcnew StudentForm(this);
            form->ShowDialog();
        }

        void btnSubjects_Click(System::Object^ sender, System::EventArgs^ e)
        {
        
            this->Hide();
            SubjectForm^ form = gcnew SubjectForm(this);
            form->ShowDialog();
        }

        void btnGrades_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->Hide();
            GradeForm^ form = gcnew GradeForm(this);
            form->ShowDialog();
        }
        //void btnGrades_Click(System::Object^ sender, System::EventArgs^ e)
        //{
        //    try
        //    {
        //        SqlConnection^ conn = gcnew SqlConnection(Database::connectionString);

        //        conn->Open();
        //        conn->Close();

        //        MessageBox::Show("Database connection succeed: " + Database::connectionString);

        //    }
        //    catch (Exception^ ex)
        //    {
        //        MessageBox::Show("Database connection failed: " + ex->Message);
        //    }
        //}
        String^ GetConnectionString()
        {
            // Use System::Configuration::ConfigurationManager to access connection strings
            return System::Configuration::ConfigurationManager::ConnectionStrings["UniversityDb"]->ConnectionString;
        }

        System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {
         //   // Hide main window
         //   this->Hide();
         //   // Show login form
         //   login->ShowDialog();
         //   // Close main form after login form ends
	        //this->Close();
	        Application::Restart();
        }
};
}