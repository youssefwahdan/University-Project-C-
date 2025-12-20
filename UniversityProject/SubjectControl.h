#using <System.Configuration.dll>

#pragma once

#include "Database.h"
using namespace System::Configuration;

namespace UniversityProject {

    public ref class SubjectControl : public System::Windows::Forms::UserControl
    {
    public:
        SubjectControl()
        {
            InitializeComponent();
            db = gcnew Database(GetConnectionString());
            LoadSubjects();
            //mainForm = form;
        }

    protected:
        ~SubjectControl()
        {
            if (components)
                delete components;
        }

    private:
        Database^ db;
        System::Windows::Forms::DataGridView^ dgvSubjects;
        System::Windows::Forms::TextBox^ txtSubjectName;
        System::Windows::Forms::ComboBox^ cmbYearOffered;
        System::Windows::Forms::Button^ btnAdd;
        System::Windows::Forms::Button^ btnUpdate;
        System::Windows::Forms::Button^ btnDelete;
        System::ComponentModel::IContainer^ components;
        //Form^ mainForm;



        void InitializeComponent(void)
        {
            this->btnAdd = (gcnew System::Windows::Forms::Button());
            this->btnUpdate = (gcnew System::Windows::Forms::Button());
            this->btnDelete = (gcnew System::Windows::Forms::Button());
            this->dgvSubjects = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSubjects))->BeginInit();
            this->SuspendLayout();
            // 
            // btnAdd
            // 
            this->btnAdd->Location = System::Drawing::Point(210, 89);
            this->btnAdd->Name = L"btnAdd";
            this->btnAdd->Size = System::Drawing::Size(75, 23);
            this->btnAdd->TabIndex = 0;
            this->btnAdd->Click += gcnew System::EventHandler(this, &SubjectControl::btnAdd_Click);
            // 
            // btnUpdate
            // 
            this->btnUpdate->Location = System::Drawing::Point(192, 29);
            this->btnUpdate->Name = L"btnUpdate";
            this->btnUpdate->Size = System::Drawing::Size(75, 23);
            this->btnUpdate->TabIndex = 0;
            this->btnUpdate->Click += gcnew System::EventHandler(this, &SubjectControl::btnUpdate_Click);
            // 
            // btnDelete
            // 
            this->btnDelete->Location = System::Drawing::Point(129, 108);
            this->btnDelete->Name = L"btnDelete";
            this->btnDelete->Size = System::Drawing::Size(75, 23);
            this->btnDelete->TabIndex = 0;
            this->btnDelete->Click += gcnew System::EventHandler(this, &SubjectControl::btnDelete_Click);
            // 
            // dgvSubjects
            // 
            this->dgvSubjects->AllowUserToAddRows = false;
            this->dgvSubjects->ColumnHeadersHeight = 29;
            this->dgvSubjects->Location = System::Drawing::Point(12, 199);
            this->dgvSubjects->Name = L"dgvSubjects";
            this->dgvSubjects->RowHeadersWidth = 51;
            this->dgvSubjects->Size = System::Drawing::Size(758, 340);
            this->dgvSubjects->TabIndex = 0;
            this->dgvSubjects->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->dgvSubjects->SelectionChanged += gcnew System::EventHandler(this, &SubjectControl::dgvSubjects_SelectionChanged);
            // 
            // SubjectControl
            // 
            this->ClientSize = System::Drawing::Size(782, 553);
            this->Controls->Add(this->dgvSubjects);
            this->Controls->Add(this->btnDelete);
            this->Controls->Add(this->btnUpdate);
            this->Controls->Add(this->btnAdd);
			this->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Padding = System::Windows::Forms::Padding(10);

            //this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
            this->Name = L"SubjectControl";
            //this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSubjects))->EndInit();
            this->ResumeLayout(false);

        }

        void LoadSubjects()
        {
            dgvSubjects->DataSource = db->GetSubjects();
        }

        void btnAdd_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (ValidateInput()) {
                db->AddSubject(txtSubjectName->Text, Convert::ToInt32(cmbYearOffered->SelectedItem));
                LoadSubjects();
            }
        }

        void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Similar to StudentForm
        }

        void btnDelete_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Similar to StudentForm
        }

        void dgvSubjects_SelectionChanged(System::Object^ sender, System::EventArgs^ e)
        {
            // Populate text boxes with selected row data
        }

        bool ValidateInput()
        {
            // Implement validation logic
            return true;
        }

        String^ GetConnectionString()
        {
            // Use System::Configuration::ConfigurationManager to access connection strings
            return System::Configuration::ConfigurationManager::ConnectionStrings["UniversityDb"]->ConnectionString;

        }
    };
}