
#using <System.Configuration.dll>
#include "SubjectControl.h"
#include "GradeControl.h"
#include "StudentControl.h"
#pragma once
using namespace System::Windows::Forms;
using namespace System::Configuration;
namespace UniversityProject {
    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(int id)
        {
            InitializeComponent();
            db = gcnew Database(GetConnectionString());
            AdminID = id;

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
        System::Windows::Forms::Label^ welcomeLabel;
        System::Windows::Forms::Button^ btnLogout;
    private: System::Windows::Forms::Panel^ sidebarPanel;
    private: System::Windows::Forms::Panel^ sectionsPanel;
    private: System::Windows::Forms::Panel^ navbar;
		   int AdminID;
           System::ComponentModel::IContainer^ components;


        void InitializeComponent()
        {
            this->btnSubjects = (gcnew System::Windows::Forms::Button());
            this->btnGrades = (gcnew System::Windows::Forms::Button());
            this->btnStudents = (gcnew System::Windows::Forms::Button());
            this->welcomeLabel = (gcnew System::Windows::Forms::Label());
            this->btnLogout = (gcnew System::Windows::Forms::Button());
            this->sidebarPanel = (gcnew System::Windows::Forms::Panel());
            this->sectionsPanel = (gcnew System::Windows::Forms::Panel());
            this->navbar = (gcnew System::Windows::Forms::Panel());
            this->sidebarPanel->SuspendLayout();
            this->navbar->SuspendLayout();
            this->SuspendLayout();
            // 
            // btnSubjects
            // 
            this->btnSubjects->BackColor = System::Drawing::Color::OliveDrab;
            this->btnSubjects->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnSubjects->Dock = System::Windows::Forms::DockStyle::Top;
            this->btnSubjects->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnSubjects->Location = System::Drawing::Point(10, 72);
            this->btnSubjects->Name = L"btnSubjects";
            this->btnSubjects->Size = System::Drawing::Size(180, 52);
            this->btnSubjects->TabIndex = 1;
            this->btnSubjects->Text = L"Subjects";
            this->btnSubjects->UseVisualStyleBackColor = false;
            this->btnSubjects->Click += gcnew System::EventHandler(this, &MainForm::btnSubjects_Click);
            // 
            // btnGrades
            // 
            this->btnGrades->BackColor = System::Drawing::Color::DarkSlateGray;
            this->btnGrades->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnGrades->Dock = System::Windows::Forms::DockStyle::Top;
            this->btnGrades->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnGrades->Location = System::Drawing::Point(10, 20);
            this->btnGrades->Name = L"btnGrades";
            this->btnGrades->Size = System::Drawing::Size(180, 52);
            this->btnGrades->TabIndex = 2;
            this->btnGrades->Text = L"Grades";
            this->btnGrades->UseVisualStyleBackColor = false;
            this->btnGrades->Click += gcnew System::EventHandler(this, &MainForm::btnGrades_Click);
            // 
            // btnStudents
            // 
            this->btnStudents->BackColor = System::Drawing::Color::Orange;
            this->btnStudents->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnStudents->Dock = System::Windows::Forms::DockStyle::Top;
            this->btnStudents->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnStudents->Location = System::Drawing::Point(10, 124);
            this->btnStudents->Name = L"btnStudents";
            this->btnStudents->Size = System::Drawing::Size(180, 52);
            this->btnStudents->TabIndex = 0;
            this->btnStudents->Text = L"Students";
            this->btnStudents->UseVisualStyleBackColor = false;
            this->btnStudents->Click += gcnew System::EventHandler(this, &MainForm::btnStudents_Click);
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
            this->btnLogout->Click += gcnew System::EventHandler(this, &MainForm::btnLogout_Click);
            // 
            // sidebarPanel
            // 
            this->sidebarPanel->BackColor = System::Drawing::Color::DarkGray;
            this->sidebarPanel->Controls->Add(this->btnStudents);
            this->sidebarPanel->Controls->Add(this->btnSubjects);
            this->sidebarPanel->Controls->Add(this->btnGrades);
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
            // MainForm
            // 
            this->ClientSize = System::Drawing::Size(918, 561);
            this->Controls->Add(this->sectionsPanel);
            this->Controls->Add(this->navbar);
            this->Controls->Add(this->sidebarPanel);
            this->ForeColor = System::Drawing::Color::WhiteSmoke;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
            this->Name = L"MainForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->sidebarPanel->ResumeLayout(false);
            this->navbar->ResumeLayout(false);
            this->navbar->PerformLayout();
            this->ResumeLayout(false);

        }

        void btnStudents_Click(System::Object^ sender, System::EventArgs^ e)
        {
			sectionsPanel->Controls->Clear();
            StudentControl^ form = gcnew StudentControl();
			form->Dock = DockStyle::Fill;
			sectionsPanel->Controls->Add(form);
        }

        void btnSubjects_Click(System::Object^ sender, System::EventArgs^ e)
        {
        
            sectionsPanel->Controls->Clear();
            SubjectControl^ form = gcnew SubjectControl();
            form->Dock = DockStyle::Fill;
            sectionsPanel->Controls->Add(form);
        }

        void btnGrades_Click(System::Object^ sender, System::EventArgs^ e)
        {
            sectionsPanel->Controls->Clear();
            GradeControl^ form = gcnew GradeControl();
            form->Dock = DockStyle::Fill;
            sectionsPanel->Controls->Add(form);
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