#pragma once
#using <System.Configuration.dll>

#include "Database.h"
using namespace System::Configuration;
using namespace System::Windows::Forms;

	ref class MainForm;
namespace UniversityProject {
    public ref class StudentForm : public System::Windows::Forms::Form
    {
    public:
        StudentForm(Form^ form)
        {
            InitializeComponent();
            db = gcnew Database(GetConnectionString());
            LoadStudents();
            mainForm = form;
        }

    protected:
        ~StudentForm()
        {
            if (components)
                delete components;
        }

    private:
        Database^ db;
        System::Windows::Forms::DataGridView^ dgvStudents;
        System::Windows::Forms::TextBox^ txtName;
        System::Windows::Forms::TextBox^ txtSection;
        System::Windows::Forms::ComboBox^ cmbYear;
        System::Windows::Forms::Button^ btnAdd;
        System::Windows::Forms::Button^ btnUpdate;
        System::Windows::Forms::Button^ btnDelete;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;
        System::ComponentModel::IContainer^ components;
        SqlDataAdapter^ adapter;
        System::Windows::Forms::Button^ button1;
        BindingSource^ bindingSource1;
        Form^ mainForm;


        void InitializeComponent(void)
        {
            this->btnAdd = (gcnew System::Windows::Forms::Button());
            this->btnUpdate = (gcnew System::Windows::Forms::Button());
            this->btnDelete = (gcnew System::Windows::Forms::Button());
            this->dgvStudents = (gcnew System::Windows::Forms::DataGridView());
            this->txtName = (gcnew System::Windows::Forms::TextBox());
            this->txtSection = (gcnew System::Windows::Forms::TextBox());
            this->cmbYear = (gcnew System::Windows::Forms::ComboBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvStudents))->BeginInit();
            this->SuspendLayout();
            // 
            // btnAdd
            // 
            this->btnAdd->BackColor = System::Drawing::Color::MediumSeaGreen;
            this->btnAdd->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnAdd->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnAdd->ForeColor = System::Drawing::Color::White;
            this->btnAdd->Location = System::Drawing::Point(426, 96);
            this->btnAdd->Name = L"btnAdd";
            this->btnAdd->Size = System::Drawing::Size(100, 40);
            this->btnAdd->TabIndex = 0;
            this->btnAdd->Text = L"Add";
            this->btnAdd->UseVisualStyleBackColor = false;
            this->btnAdd->Click += gcnew System::EventHandler(this, &StudentForm::btnAdd_Click);
            // 
            // btnUpdate
            // 
            this->btnUpdate->BackColor = System::Drawing::Color::RoyalBlue;
            this->btnUpdate->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnUpdate->ForeColor = System::Drawing::Color::White;
            this->btnUpdate->Location = System::Drawing::Point(532, 96);
            this->btnUpdate->Name = L"btnUpdate";
            this->btnUpdate->Size = System::Drawing::Size(100, 40);
            this->btnUpdate->TabIndex = 0;
            this->btnUpdate->Text = L"Update";
            this->btnUpdate->UseVisualStyleBackColor = false;
            this->btnUpdate->Click += gcnew System::EventHandler(this, &StudentForm::btnUpdate_Click);
            // 
            // btnDelete
            // 
            this->btnDelete->BackColor = System::Drawing::Color::Red;
            this->btnDelete->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnDelete->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnDelete->ForeColor = System::Drawing::Color::White;
            this->btnDelete->Location = System::Drawing::Point(638, 96);
            this->btnDelete->Name = L"btnDelete";
            this->btnDelete->Size = System::Drawing::Size(100, 40);
            this->btnDelete->TabIndex = 0;
            this->btnDelete->Text = L"Delete";
            this->btnDelete->UseVisualStyleBackColor = false;
            this->btnDelete->Click += gcnew System::EventHandler(this, &StudentForm::btnDelete_Click);
            // 
            // dgvStudents
            // 
            this->dgvStudents->AllowUserToAddRows = false;
            this->dgvStudents->BackgroundColor = System::Drawing::Color::Gainsboro;
            this->dgvStudents->ColumnHeadersHeight = 29;
            this->dgvStudents->Location = System::Drawing::Point(12, 166);
            this->dgvStudents->Name = L"dgvStudents";
            this->dgvStudents->RowHeadersWidth = 100;
            this->dgvStudents->Size = System::Drawing::Size(758, 375);
            this->dgvStudents->TabIndex = 0;
            this->dgvStudents->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &StudentForm::dgvStudents_CellEndEdit);
            this->dgvStudents->SelectionChanged += gcnew System::EventHandler(this, &StudentForm::dgvStudents_SelectionChanged);
            // 
            // txtName
            // 
            this->txtName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txtName->ForeColor = System::Drawing::Color::Gray;
            this->txtName->Location = System::Drawing::Point(158, 59);
            this->txtName->Name = L"txtName";
            this->txtName->Size = System::Drawing::Size(250, 30);
            this->txtName->TabIndex = 1;
            this->txtName->Text = L"Name";
            this->txtName->GotFocus += gcnew System::EventHandler(this, &StudentForm::txtName_Enter);
            this->txtName->LostFocus += gcnew System::EventHandler(this, &StudentForm::txtName_Leave);
            // 
            // txtSection
            // 
            this->txtSection->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txtSection->ForeColor = System::Drawing::Color::Gray;
            this->txtSection->Location = System::Drawing::Point(158, 19);
            this->txtSection->Name = L"txtSection";
            this->txtSection->Size = System::Drawing::Size(250, 30);
            this->txtSection->TabIndex = 2;
            this->txtSection->Text = L"Section";
            this->txtSection->GotFocus += gcnew System::EventHandler(this, &StudentForm::txtSection_Enter);
            this->txtSection->LostFocus += gcnew System::EventHandler(this, &StudentForm::txtSection_Leave);
            // 
            // cmbYear
            // 
            this->cmbYear->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->cmbYear->Items->AddRange(gcnew cli::array< System::Object^  >(4) { 1, 2, 3, 4 });
            this->cmbYear->Location = System::Drawing::Point(158, 100);
            this->cmbYear->Name = L"cmbYear";
            this->cmbYear->Size = System::Drawing::Size(250, 31);
            this->cmbYear->TabIndex = 3;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(7, 21);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(82, 28);
            this->label1->TabIndex = 4;
            this->label1->Text = L"Section";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->label2->Location = System::Drawing::Point(7, 61);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(148, 28);
            this->label2->TabIndex = 5;
            this->label2->Text = L"Student Name";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->label3->Location = System::Drawing::Point(7, 103);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(150, 28);
            this->label3->TabIndex = 6;
            this->label3->Text = L"Academic Year";
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::CornflowerBlue;
            this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->button1->ForeColor = System::Drawing::Color::White;
            this->button1->Location = System::Drawing::Point(670, 12);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(100, 40);
            this->button1->TabIndex = 7;
            this->button1->Text = L"Back";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &StudentForm::button1_Click);
            // 
            // StudentForm
            // 
            this->ClientSize = System::Drawing::Size(782, 553);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->dgvStudents);
            this->Controls->Add(this->btnDelete);
            this->Controls->Add(this->btnAdd);
            this->Controls->Add(this->btnUpdate);
            this->Controls->Add(this->txtName);
            this->Controls->Add(this->txtSection);
            this->Controls->Add(this->cmbYear);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
            this->Name = L"StudentForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Student";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvStudents))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        void LoadStudents()
        {
            dgvStudents->DataSource = db->GetStudents();
        }

        void btnAdd_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (ValidateInput()) {
                db->AddStudent(txtName->Text, txtSection->Text, Convert::ToInt32(cmbYear->SelectedItem));
                LoadStudents();
            }
        }

        void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (dgvStudents->SelectedRows->Count == 1 && ValidateInput()) {
                int id = Convert::ToInt32(dgvStudents->SelectedRows[0]->Cells["StudentID"]->Value);
                db->UpdateStudent(id, txtName->Text, txtSection->Text, Convert::ToInt32(cmbYear->SelectedItem));
                LoadStudents();
            }
        }

        void btnDelete_Click(System::Object^ sender, System::EventArgs^ e)
        {
            try {
                if (dgvStudents->SelectedRows->Count == 0) {
                    MessageBox::Show("Please select a student to delete.");
                    return;
                }
                DataGridViewRow^ row = dgvStudents->SelectedRows[0];
                String^ studentName = row->Cells["Name"]->Value->ToString();
                System::Windows::Forms::DialogResult result = MessageBox::Show("Are you sure you want to delete student: " + studentName + "?", "Confirm Delete", MessageBoxButtons::YesNo);
                if (result != System::Windows::Forms::DialogResult::Yes) {
                    return; // User cancelled deletion
                } else {
                    int id = Convert::ToInt32(dgvStudents->SelectedRows[0]->Cells["StudentID"]->Value);
                    db->DeleteStudent(id);
                    LoadStudents();
                }
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message);
                return;
            }
        }

        void dgvStudents_SelectionChanged(System::Object^ sender, System::EventArgs^ e)
        {
            if (dgvStudents->SelectedRows->Count == 1) {
                DataGridViewRow^ row = dgvStudents->SelectedRows[0];
                txtName->Text = row->Cells["Name"]->Value->ToString();
                txtSection->Text = row->Cells["Section"]->Value->ToString();
                cmbYear->SelectedItem = Convert::ToInt32(row->Cells["AcademicYear"]->Value);
			}
        }
        void dgvStudents_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
        {
            try {
                if (e->RowIndex < 0) return;
                DataGridViewRow^ row = dgvStudents->Rows[e->RowIndex];

                int id = Convert::ToInt32(row->Cells["StudentID"]->Value);
                String^ name = Convert::ToString(row->Cells["Name"]->Value);
                String^ section = Convert::ToString(row->Cells["Section"]->Value);
                int year = Convert::ToInt32(row->Cells["AcademicYear"]->Value);

                db->UpdateStudent(id, name, section, year);
                MessageBox::Show("Changes saved to database successfully!");
                LoadStudents(); // or update the row in-place instead of reloading
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error saving changes: " + ex->Message);
            }

		}

        bool ValidateInput()
        {
            // Implement validation logic (non-empty, valid year, etc.)
            return true;
        }
        // Example in C++/CLI
        void txtName_Enter(System::Object^ sender, System::EventArgs^ e) {
            if (txtName->Text == "Name") {
                txtName->Text = "";
                txtName->ForeColor = System::Drawing::Color::Black;
            }
        }
        void txtName_Leave(System::Object^ sender, System::EventArgs^ e) {
            if (String::IsNullOrWhiteSpace(txtName->Text)) {
                txtName->Text = "Name";
                txtName->ForeColor = System::Drawing::Color::Gray;
            }
        }

        void txtSection_Enter(System::Object^ sender, System::EventArgs^ e) {
            if (txtSection->Text == "Section") {
                txtSection->Text = "";
                txtSection->ForeColor = System::Drawing::Color::Black;
            }
        }
        void txtSection_Leave(System::Object^ sender, System::EventArgs^ e) {
            if (String::IsNullOrWhiteSpace(txtSection->Text)) {
                txtSection->Text = "Section";
                txtSection->ForeColor = System::Drawing::Color::Gray;
            }
        }

        String^ GetConnectionString()
        {
            // Use System::Configuration::ConfigurationManager to access connection strings
            return System::Configuration::ConfigurationManager::ConnectionStrings["UniversityDb"]->ConnectionString;
        }
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	           this->Hide();
               mainForm->Show();
               this->Close();
        }
};
}