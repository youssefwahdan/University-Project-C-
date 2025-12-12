#using <System.Configuration.dll>

#pragma once

#include "Database.h"
using namespace System::Configuration;

namespace UniversityProject {

    public ref class GradeForm : public System::Windows::Forms::Form
    {
    public:
        GradeForm(Form^ form)
        {
            InitializeComponent();
            db = gcnew Database(GetConnectionString());
            LoadStudents();
            LoadSubjects();
            LoadGrades();
            mainForm = form;

        }

    protected:
        ~GradeForm()
        {
            if (components)
                delete components;
        }

    private:
        Database^ db;
        System::Windows::Forms::ComboBox^ cmbStudent;
        System::Windows::Forms::ComboBox^ cmbSubject;
        System::Windows::Forms::ComboBox^ cmbAssignment1;
        System::Windows::Forms::ComboBox^ cmbAssignment2;
        System::Windows::Forms::TextBox^ txtFinalGrade;
        System::Windows::Forms::Button^ btnSave;
        System::Windows::Forms::DataGridView^ dgvGrades;
        System::ComponentModel::IContainer^ components;
		DataTable^ gradesTable;
		DataTable^ studentsTable;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::Label^ label5;
        System::Windows::Forms::Button^ button1;
        DataTable^ subjectsTable;
        Form^ mainForm;


        void InitializeComponent(void)
        {
            this->btnSave = (gcnew System::Windows::Forms::Button());
            this->cmbStudent = (gcnew System::Windows::Forms::ComboBox());
            this->cmbSubject = (gcnew System::Windows::Forms::ComboBox());
            this->cmbAssignment1 = (gcnew System::Windows::Forms::ComboBox());
            this->cmbAssignment2 = (gcnew System::Windows::Forms::ComboBox());
            this->txtFinalGrade = (gcnew System::Windows::Forms::TextBox());
            this->dgvGrades = (gcnew System::Windows::Forms::DataGridView());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvGrades))->BeginInit();
            this->SuspendLayout();
            // 
            // btnSave
            // 
            this->btnSave->BackColor = System::Drawing::Color::MediumSeaGreen;
            this->btnSave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnSave->ForeColor = System::Drawing::Color::White;
            this->btnSave->Location = System::Drawing::Point(670, 150);
            this->btnSave->Name = L"btnSave";
            this->btnSave->Size = System::Drawing::Size(100, 40);
            this->btnSave->TabIndex = 0;
            this->btnSave->Text = L"Save";
            this->btnSave->UseVisualStyleBackColor = false;
            this->btnSave->Click += gcnew System::EventHandler(this, &GradeForm::btnSave_Click);
            // 
            // cmbStudent
            // 
            this->cmbStudent->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbStudent->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->cmbStudent->Location = System::Drawing::Point(195, 49);
            this->cmbStudent->Name = L"cmbStudent";
            this->cmbStudent->Size = System::Drawing::Size(250, 31);
            this->cmbStudent->TabIndex = 0;
            // 
            // cmbSubject
            // 
            this->cmbSubject->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbSubject->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->cmbSubject->Location = System::Drawing::Point(195, 12);
            this->cmbSubject->Name = L"cmbSubject";
            this->cmbSubject->Size = System::Drawing::Size(250, 31);
            this->cmbSubject->TabIndex = 0;
            // 
            // cmbAssignment1
            // 
            this->cmbAssignment1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbAssignment1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->cmbAssignment1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"P", L"M", L"D" });
            this->cmbAssignment1->Location = System::Drawing::Point(195, 86);
            this->cmbAssignment1->Name = L"cmbAssignment1";
            this->cmbAssignment1->Size = System::Drawing::Size(250, 31);
            this->cmbAssignment1->TabIndex = 0;
            // 
            // cmbAssignment2
            // 
            this->cmbAssignment2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbAssignment2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->cmbAssignment2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"P", L"M", L"D" });
            this->cmbAssignment2->Location = System::Drawing::Point(195, 123);
            this->cmbAssignment2->Name = L"cmbAssignment2";
            this->cmbAssignment2->Size = System::Drawing::Size(250, 31);
            this->cmbAssignment2->TabIndex = 0;
            // 
            // txtFinalGrade
            // 
            this->txtFinalGrade->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txtFinalGrade->Location = System::Drawing::Point(195, 160);
            this->txtFinalGrade->Name = L"txtFinalGrade";
            this->txtFinalGrade->Size = System::Drawing::Size(250, 30);
            this->txtFinalGrade->TabIndex = 0;
            // 
            // dgvGrades
            // 
            this->dgvGrades->ColumnHeadersHeight = 29;
            this->dgvGrades->Location = System::Drawing::Point(12, 196);
            this->dgvGrades->Name = L"dgvGrades";
            this->dgvGrades->RowHeadersWidth = 51;
            this->dgvGrades->Size = System::Drawing::Size(758, 345);
            this->dgvGrades->TabIndex = 0;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->label1->Location = System::Drawing::Point(7, 15);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(68, 28);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Name";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->label2->Location = System::Drawing::Point(7, 52);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(82, 28);
            this->label2->TabIndex = 2;
            this->label2->Text = L"Subject";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->label3->Location = System::Drawing::Point(7, 89);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(141, 28);
            this->label3->TabIndex = 3;
            this->label3->Text = L"Assignment 1";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->label4->Location = System::Drawing::Point(12, 126);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(141, 28);
            this->label4->TabIndex = 4;
            this->label4->Text = L"Assignment 2";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->label5->Location = System::Drawing::Point(7, 162);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(57, 28);
            this->label5->TabIndex = 5;
            this->label5->Text = L"Final";
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::CornflowerBlue;
            this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->button1->ForeColor = System::Drawing::Color::White;
            this->button1->Location = System::Drawing::Point(670, 3);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(100, 40);
            this->button1->TabIndex = 6;
            this->button1->Text = L"Back";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &GradeForm::button1_Click);
            // 
            // GradeForm
            // 
            this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
            this->ClientSize = System::Drawing::Size(782, 553);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->dgvGrades);
            this->Controls->Add(this->txtFinalGrade);
            this->Controls->Add(this->cmbAssignment2);
            this->Controls->Add(this->cmbAssignment1);
            this->Controls->Add(this->cmbSubject);
            this->Controls->Add(this->cmbStudent);
            this->Controls->Add(this->btnSave);
            this->Name = L"GradeForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvGrades))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        void LoadStudents()
        {
            // Populate cmbStudent with student names/IDs from db->GetStudents()
			studentsTable = db->GetStudents();
            this->cmbStudent->DataSource = studentsTable;
            this->cmbStudent->DisplayMember = "Name"; // Adjust based on your DataTable columns
            this->cmbStudent->ValueMember = "StudentID"; // Adjust based on your DataTable columns
        }

        void LoadSubjects()
        {
            // Populate cmbSubject with subject names/IDs from db->GetSubjects()
            subjectsTable = db->GetSubjects();
			this->cmbSubject->DataSource = subjectsTable;
            this->cmbSubject->DisplayMember = "Name"; // Adjust based on your DataTable columns
			this->cmbSubject->ValueMember = "SubjectID"; // Adjust based on your DataTable columns
        }

        void LoadGrades()
        {
            // Populate dgvGrades with grades from db
            gradesTable = db->GetGrades();
			dgvGrades->DataSource = gradesTable;
        }

        void btnSave_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Validate input
            int studentId = 2 /* get from cmbStudent */;
            int subjectId = 2 /* get from cmbSubject */;
            String^ a1 = cmbAssignment1->SelectedItem->ToString();
            String^ a2 = cmbAssignment2->SelectedItem->ToString();
            double finalGrade = Convert::ToDouble(txtFinalGrade->Text);

            // Save to database
            db->AddOrUpdateGrade(studentId, subjectId, a1, a2, finalGrade);
            LoadGrades();
        }

        String^ GetConnectionString()
        {
            // System::Configuration::ConfigurationManager is in System.Configuration.dll
            return System::Configuration::ConfigurationManager::ConnectionStrings["UniversityDb"]->ConnectionString;
        }
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	        this->Hide();
	        mainForm->Show();
            this->Close();
        }
};
}