#pragma once
#using <System.Configuration.dll>

#include "Database.h"
using namespace System::Configuration;
using namespace System::Windows::Forms;
using namespace System::Data::SqlClient;
using namespace System::Data;
using namespace System;

	ref class MainForm;
namespace UniversityProject {
    public ref class StudentControl : public System::Windows::Forms::UserControl
    {
    public:
        StudentControl()
        {
            InitializeComponent();
            db = gcnew Database(GetConnectionString());
            LoadStudents();
			LoadAcademicLevelOptions();
			LoadFacultyOptions();
			LoadDepartmentOptions();
            //mainForm = form;
        }

    protected:
        ~StudentControl()
        {
            if (components)
                delete components;
        }

    private:
        Database^ db;
        System::Windows::Forms::DataGridView^ dgvStudents;
        System::Windows::Forms::TextBox^ txtFirstName;
        System::Windows::Forms::TextBox^ txtLastName;
    private: System::Windows::Forms::TextBox^ txtUniversityID;


        System::Windows::Forms::ComboBox^ cmbGender;



        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;
        System::ComponentModel::IContainer^ components;
        SqlDataAdapter^ adapter;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
    private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label7;

    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::TextBox^ txtphone;
    private: System::Windows::Forms::TextBox^ txtEmail;
    private: System::Windows::Forms::Button^ btnAdd;
    private: System::Windows::Forms::Button^ btnUpdate;
    private: System::Windows::Forms::Button^ btnDelete;
    private: System::Windows::Forms::TextBox^ textPassword;
    private: System::Windows::Forms::TextBox^ textUsername;
    private: System::Windows::Forms::Label^ passwordLabel;
    private: System::Windows::Forms::Label^ usernameLabel;
    private: System::Windows::Forms::ComboBox^ cbFaculty;
    private: System::Windows::Forms::ComboBox^ cbAcademicLevel;




    private: System::Windows::Forms::ComboBox^ cbDepartment;

    private: System::Windows::Forms::Label^ facultyLabel;
    private: System::Windows::Forms::Label^ departmentLabel;
    private: System::Windows::Forms::Label^ label8;
           int FacultyID;








        BindingSource^ bindingSource1;
        //Form^ mainForm;


        void InitializeComponent(void)
        {
            this->dgvStudents = (gcnew System::Windows::Forms::DataGridView());
            this->txtFirstName = (gcnew System::Windows::Forms::TextBox());
            this->txtLastName = (gcnew System::Windows::Forms::TextBox());
            this->txtUniversityID = (gcnew System::Windows::Forms::TextBox());
            this->cmbGender = (gcnew System::Windows::Forms::ComboBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
            this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->txtphone = (gcnew System::Windows::Forms::TextBox());
            this->txtEmail = (gcnew System::Windows::Forms::TextBox());
            this->btnAdd = (gcnew System::Windows::Forms::Button());
            this->btnUpdate = (gcnew System::Windows::Forms::Button());
            this->btnDelete = (gcnew System::Windows::Forms::Button());
            this->textPassword = (gcnew System::Windows::Forms::TextBox());
            this->textUsername = (gcnew System::Windows::Forms::TextBox());
            this->passwordLabel = (gcnew System::Windows::Forms::Label());
            this->usernameLabel = (gcnew System::Windows::Forms::Label());
            this->cbFaculty = (gcnew System::Windows::Forms::ComboBox());
            this->cbAcademicLevel = (gcnew System::Windows::Forms::ComboBox());
            this->cbDepartment = (gcnew System::Windows::Forms::ComboBox());
            this->facultyLabel = (gcnew System::Windows::Forms::Label());
            this->departmentLabel = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvStudents))->BeginInit();
            this->SuspendLayout();
            // 
            // dgvStudents
            // 
            this->dgvStudents->AllowUserToAddRows = false;
            this->dgvStudents->BackgroundColor = System::Drawing::Color::Gainsboro;
            this->dgvStudents->ColumnHeadersHeight = 29;
            this->dgvStudents->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->dgvStudents->Location = System::Drawing::Point(10, 468);
            this->dgvStudents->Name = L"dgvStudents";
            this->dgvStudents->RowHeadersWidth = 100;
            this->dgvStudents->Size = System::Drawing::Size(767, 199);
            this->dgvStudents->TabIndex = 0;
            this->dgvStudents->SelectionChanged += gcnew System::EventHandler(this, &StudentControl::dgvStudents_SelectionChanged);
            // 
            // txtFirstName
            // 
            this->txtFirstName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txtFirstName->ForeColor = System::Drawing::Color::Black;
            this->txtFirstName->Location = System::Drawing::Point(144, 12);
            this->txtFirstName->Name = L"txtFirstName";
            this->txtFirstName->Size = System::Drawing::Size(250, 30);
            this->txtFirstName->TabIndex = 1;
            // 
            // txtLastName
            // 
            this->txtLastName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txtLastName->ForeColor = System::Drawing::Color::Black;
            this->txtLastName->Location = System::Drawing::Point(144, 48);
            this->txtLastName->Name = L"txtLastName";
            this->txtLastName->Size = System::Drawing::Size(250, 30);
            this->txtLastName->TabIndex = 1;
            // 
            // txtUniversityID
            // 
            this->txtUniversityID->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txtUniversityID->ForeColor = System::Drawing::Color::Black;
            this->txtUniversityID->Location = System::Drawing::Point(144, 84);
            this->txtUniversityID->Name = L"txtUniversityID";
            this->txtUniversityID->Size = System::Drawing::Size(250, 30);
            this->txtUniversityID->TabIndex = 2;
            // 
            // cmbGender
            // 
            this->cmbGender->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->cmbGender->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Male", L"Female" });
            this->cmbGender->Location = System::Drawing::Point(144, 120);
            this->cmbGender->Name = L"cmbGender";
            this->cmbGender->Size = System::Drawing::Size(250, 31);
            this->cmbGender->TabIndex = 3;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::Black;
            this->label1->Location = System::Drawing::Point(7, 86);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(135, 28);
            this->label1->TabIndex = 4;
            this->label1->Text = L"University ID";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->label2->ForeColor = System::Drawing::Color::Black;
            this->label2->Location = System::Drawing::Point(7, 10);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(115, 28);
            this->label2->TabIndex = 5;
            this->label2->Text = L"First Name";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->label3->ForeColor = System::Drawing::Color::Black;
            this->label3->Location = System::Drawing::Point(8, 123);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(80, 28);
            this->label3->TabIndex = 6;
            this->label3->Text = L"Gender";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->label4->Location = System::Drawing::Point(5, 50);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(112, 28);
            this->label4->TabIndex = 7;
            this->label4->Text = L"Last Name";
            // 
            // dateTimePicker1
            // 
            this->dateTimePicker1->Location = System::Drawing::Point(144, 157);
            this->dateTimePicker1->Name = L"dateTimePicker1";
            this->dateTimePicker1->Size = System::Drawing::Size(250, 22);
            this->dateTimePicker1->TabIndex = 8;
            // 
            // dateTimePicker2
            // 
            this->dateTimePicker2->Location = System::Drawing::Point(144, 185);
            this->dateTimePicker2->Name = L"dateTimePicker2";
            this->dateTimePicker2->Size = System::Drawing::Size(250, 22);
            this->dateTimePicker2->TabIndex = 9;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->label5->Location = System::Drawing::Point(8, 213);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(71, 28);
            this->label5->TabIndex = 10;
            this->label5->Text = L"Phone";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->label6->Location = System::Drawing::Point(8, 151);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(55, 28);
            this->label6->TabIndex = 11;
            this->label6->Text = L"BOD";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->label7->Location = System::Drawing::Point(8, 251);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(64, 28);
            this->label7->TabIndex = 12;
            this->label7->Text = L"Email";
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->label9->Location = System::Drawing::Point(8, 179);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(101, 28);
            this->label9->TabIndex = 14;
            this->label9->Text = L"Add Date";
            // 
            // txtphone
            // 
            this->txtphone->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txtphone->ForeColor = System::Drawing::Color::Black;
            this->txtphone->Location = System::Drawing::Point(144, 213);
            this->txtphone->Name = L"txtphone";
            this->txtphone->Size = System::Drawing::Size(250, 30);
            this->txtphone->TabIndex = 15;
            // 
            // txtEmail
            // 
            this->txtEmail->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txtEmail->ForeColor = System::Drawing::Color::Black;
            this->txtEmail->Location = System::Drawing::Point(144, 253);
            this->txtEmail->Name = L"txtEmail";
            this->txtEmail->Size = System::Drawing::Size(250, 30);
            this->txtEmail->TabIndex = 16;
            // 
            // btnAdd
            // 
            this->btnAdd->BackColor = System::Drawing::Color::MediumSeaGreen;
            this->btnAdd->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->btnAdd->ForeColor = System::Drawing::Color::White;
            this->btnAdd->Location = System::Drawing::Point(406, 251);
            this->btnAdd->Name = L"btnAdd";
            this->btnAdd->Size = System::Drawing::Size(83, 32);
            this->btnAdd->TabIndex = 17;
            this->btnAdd->Text = L"Add";
            this->btnAdd->UseVisualStyleBackColor = false;
            this->btnAdd->Click += gcnew System::EventHandler(this, &StudentControl::btnAdd_Click_1);
            // 
            // btnUpdate
            // 
            this->btnUpdate->BackColor = System::Drawing::Color::Orange;
            this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->btnUpdate->ForeColor = System::Drawing::Color::White;
            this->btnUpdate->Location = System::Drawing::Point(495, 251);
            this->btnUpdate->Name = L"btnUpdate";
            this->btnUpdate->Size = System::Drawing::Size(88, 32);
            this->btnUpdate->TabIndex = 18;
            this->btnUpdate->Text = L"Update";
            this->btnUpdate->UseVisualStyleBackColor = false;
            this->btnUpdate->Click += gcnew System::EventHandler(this, &StudentControl::btnUpdate_Click_1);
            // 
            // btnDelete
            // 
            this->btnDelete->BackColor = System::Drawing::Color::Red;
            this->btnDelete->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->btnDelete->ForeColor = System::Drawing::Color::White;
            this->btnDelete->Location = System::Drawing::Point(589, 251);
            this->btnDelete->Name = L"btnDelete";
            this->btnDelete->Size = System::Drawing::Size(88, 32);
            this->btnDelete->TabIndex = 19;
            this->btnDelete->Text = L"Delete";
            this->btnDelete->UseVisualStyleBackColor = false;
            this->btnDelete->Click += gcnew System::EventHandler(this, &StudentControl::btnDelete_Click_1);
            // 
            // textPassword
            // 
            this->textPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->textPassword->ForeColor = System::Drawing::Color::Black;
            this->textPassword->Location = System::Drawing::Point(567, 52);
            this->textPassword->Name = L"textPassword";
            this->textPassword->Size = System::Drawing::Size(134, 30);
            this->textPassword->TabIndex = 23;
            // 
            // textUsername
            // 
            this->textUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->textUsername->ForeColor = System::Drawing::Color::Black;
            this->textUsername->Location = System::Drawing::Point(567, 14);
            this->textUsername->Name = L"textUsername";
            this->textUsername->Size = System::Drawing::Size(134, 30);
            this->textUsername->TabIndex = 22;
            // 
            // passwordLabel
            // 
            this->passwordLabel->AutoSize = true;
            this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->passwordLabel->Location = System::Drawing::Point(400, 50);
            this->passwordLabel->Name = L"passwordLabel";
            this->passwordLabel->Size = System::Drawing::Size(101, 28);
            this->passwordLabel->TabIndex = 21;
            this->passwordLabel->Text = L"Password";
            // 
            // usernameLabel
            // 
            this->usernameLabel->AutoSize = true;
            this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->usernameLabel->Location = System::Drawing::Point(400, 12);
            this->usernameLabel->Name = L"usernameLabel";
            this->usernameLabel->Size = System::Drawing::Size(106, 28);
            this->usernameLabel->TabIndex = 20;
            this->usernameLabel->Text = L"Username";
            // 
            // cbFaculty
            // 
            this->cbFaculty->FormattingEnabled = true;
            this->cbFaculty->Location = System::Drawing::Point(567, 88);
            this->cbFaculty->Name = L"cbFaculty";
            this->cbFaculty->Size = System::Drawing::Size(134, 24);
            this->cbFaculty->TabIndex = 24;
            this->cbFaculty->SelectedIndexChanged += gcnew System::EventHandler(this, &StudentControl::cbFaculty_SelectedIndexChanged);
            // 
            // cbAcademicLevel
            // 
            this->cbAcademicLevel->FormattingEnabled = true;
            this->cbAcademicLevel->Location = System::Drawing::Point(567, 148);
            this->cbAcademicLevel->Name = L"cbAcademicLevel";
            this->cbAcademicLevel->Size = System::Drawing::Size(134, 24);
            this->cbAcademicLevel->TabIndex = 25;
            // 
            // cbDepartment
            // 
            this->cbDepartment->FormattingEnabled = true;
            this->cbDepartment->Location = System::Drawing::Point(567, 118);
            this->cbDepartment->Name = L"cbDepartment";
            this->cbDepartment->Size = System::Drawing::Size(134, 24);
            this->cbDepartment->TabIndex = 26;
            // 
            // facultyLabel
            // 
            this->facultyLabel->AutoSize = true;
            this->facultyLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->facultyLabel->Location = System::Drawing::Point(400, 84);
            this->facultyLabel->Name = L"facultyLabel";
            this->facultyLabel->Size = System::Drawing::Size(79, 28);
            this->facultyLabel->TabIndex = 27;
            this->facultyLabel->Text = L"Faculty";
            // 
            // departmentLabel
            // 
            this->departmentLabel->AutoSize = true;
            this->departmentLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->departmentLabel->Location = System::Drawing::Point(400, 114);
            this->departmentLabel->Name = L"departmentLabel";
            this->departmentLabel->Size = System::Drawing::Size(127, 28);
            this->departmentLabel->TabIndex = 28;
            this->departmentLabel->Text = L"Department";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->label8->Location = System::Drawing::Point(400, 144);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(159, 28);
            this->label8->TabIndex = 29;
            this->label8->Text = L"Academic Level";
            // 
            // StudentControl
            // 
            this->Controls->Add(this->label8);
            this->Controls->Add(this->departmentLabel);
            this->Controls->Add(this->facultyLabel);
            this->Controls->Add(this->cbDepartment);
            this->Controls->Add(this->cbAcademicLevel);
            this->Controls->Add(this->cbFaculty);
            this->Controls->Add(this->textPassword);
            this->Controls->Add(this->textUsername);
            this->Controls->Add(this->passwordLabel);
            this->Controls->Add(this->usernameLabel);
            this->Controls->Add(this->btnDelete);
            this->Controls->Add(this->btnUpdate);
            this->Controls->Add(this->btnAdd);
            this->Controls->Add(this->txtEmail);
            this->Controls->Add(this->txtphone);
            this->Controls->Add(this->label9);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->dateTimePicker2);
            this->Controls->Add(this->dateTimePicker1);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->dgvStudents);
            this->Controls->Add(this->txtFirstName);
            this->Controls->Add(this->txtLastName);
            this->Controls->Add(this->txtUniversityID);
            this->Controls->Add(this->cmbGender);
            this->Name = L"StudentControl";
            this->Padding = System::Windows::Forms::Padding(10);
            this->Size = System::Drawing::Size(787, 677);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvStudents))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        void LoadStudents()
        {
            dgvStudents->DataSource = db->GetStudents();
        }

        void dgvStudents_SelectionChanged(System::Object^ sender, System::EventArgs^ e)
        {
            if (dgvStudents->SelectedRows->Count == 1) {
                DataGridViewRow^ row = dgvStudents->SelectedRows[0];
                txtFirstName->Text = row->Cells["FirstName"]->Value->ToString();
                txtLastName->Text = row->Cells["LastName"]->Value->ToString();
                cmbGender->SelectedItem = row->Cells["Gender"]->Value->ToString();
				txtUniversityID->Text = row->Cells["UniversityID"]->Value->ToString();
				txtEmail->Text = row->Cells["Email"]->Value->ToString();
				txtphone->Text = row->Cells["Phone"]->Value->ToString();
				dateTimePicker1->Value = Convert::ToDateTime(row->Cells["BirthDate"]->Value);
				dateTimePicker2->Value = Convert::ToDateTime(row->Cells["AdmissionDate"]->Value);

                SqlConnection^ conn = gcnew SqlConnection(db->connectionString);
                try {
                    conn->Open();
                    String^ query = "SELECT * FROM Users WHERE StudentID = " + row->Cells["StudentID"]->Value->ToString();
                    SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, conn);
                    DataTable^ dt = gcnew DataTable();
                    adapter->Fill(dt);

                    for each (DataRow ^ r in dt->Rows)
                    {
                        textUsername->Text = r["Username"]->ToString();
                        textPassword->Text = r["Password"]->ToString();
                    }
                    String^ query2 = "SELECT * FROM Faculty WHERE FacultyID = " + row->Cells["FacultyID"]->Value->ToString();
                    SqlDataAdapter^ adapter2 = gcnew SqlDataAdapter(query2, conn);
                    DataTable^ dt2 = gcnew DataTable();
                    adapter2->Fill(dt2);
                    for each (DataRow ^ r in dt2->Rows)
                    {
                        cbFaculty->SelectedItem = r["Name"]->ToString();
                    }
                    String^ query3 = "SELECT * FROM Department WHERE DepartmentID = " + row->Cells["DepartmentID"]->Value->ToString();
                    SqlDataAdapter^ adapter3 = gcnew SqlDataAdapter(query3, conn);
                    DataTable^ dt3 = gcnew DataTable();
                    adapter3->Fill(dt3);
                    for each (DataRow ^ r in dt3->Rows)
                    {
                        cbFaculty->SelectedItem = r["Name"]->ToString();
                    }

                    String^ query4 = "SELECT * FROM AcademicLevel WHERE AcademicLevelID = " + row->Cells["AcademicLevelID"]->Value->ToString();
                    SqlDataAdapter^ adapter4 = gcnew SqlDataAdapter(query4, conn);
                    DataTable^ dt4 = gcnew DataTable();
                    adapter4->Fill(dt4);
                    for each (DataRow ^ r in dt4->Rows)
                    {
                        cbFaculty->SelectedItem = r["LevelName"]->ToString();
                    }
                }
                catch (Exception^ e) {
                    MessageBox::Show("Error" + e);
                }
			}
        }

        bool ValidateInput()
        {
            // Implement validation logic (non-empty, valid year, etc.)
            return true;
        }

        String^ GetConnectionString()
        {
            // Use System::Configuration::ConfigurationManager to access connection strings
            return System::Configuration::ConfigurationManager::ConnectionStrings["UniversityDb"]->ConnectionString;
        }
        void AddStudent(String^ universityID,
            String^ firstName,
            String^ lastName,
            String^ email,
            String^ phone,
			DateTime Dob,
            DateTime addDate,
            String^ gender,
            String^ Username,
            String^ Password,
			String^ department,
            String^ faculty,
			String^ academicLevel
        )
        {
            int departmentID = Convert::ToInt32(department->Split('-')[0]->Trim());
            int facultyID = Convert::ToInt32(faculty->Split('-')[0]->Trim());
            int academicLevelID = Convert::ToInt32(academicLevel->Split('-')[0]->Trim());

            SqlConnection^ conn = gcnew SqlConnection(db->connectionString);

            try
            {
                conn->Open();

                String^ query1 = "INSERT INTO Student (UniversityID, FirstName,LastName, Email, Phone,BirthDate, AdmissionDate, Gender, DepartmentID, FacultyID, AcademicLevelID) VALUES (@uid, @fname,@lname, @email, @phone,@DOB, @date,@gender, @department, @faculty, @academicLevel)";

                SqlCommand^ cmd1 = gcnew SqlCommand(query1, conn);
                cmd1->Parameters->AddWithValue("@uid", universityID);
                cmd1->Parameters->AddWithValue("@fname", firstName);
                cmd1->Parameters->AddWithValue("@lname", lastName);
                cmd1->Parameters->AddWithValue("@email", email);
                cmd1->Parameters->AddWithValue("@phone", phone);
                cmd1->Parameters->AddWithValue("@Dob", Dob);
                cmd1->Parameters->AddWithValue("@date", addDate);
                cmd1->Parameters->AddWithValue("@gender", gender);
				cmd1->Parameters->AddWithValue("@department", departmentID);
				cmd1->Parameters->AddWithValue("@faculty", facultyID);
				cmd1->Parameters->AddWithValue("@academicLevel", academicLevelID);

                cmd1->ExecuteNonQuery();

                try
                {

                    // Retrieve the StudentID of the newly added student
                    String^ query3 = "SELECT TOP 1 StudentID FROM Student ORDER BY StudentID DESC";
                    SqlCommand^ cmdSelect = gcnew SqlCommand(query3, conn);
                    int studentID = (int)cmdSelect->ExecuteScalar();

                    String^ query2 = "INSERT INTO Users (Username, Password, Role, StudentID) VALUES (@username, @password, @role, @studentID)";

                    SqlCommand^ cmd2 = gcnew SqlCommand(query2, conn);
                    cmd2->Parameters->AddWithValue("@username", Username);
                    cmd2->Parameters->AddWithValue("@password", Password);
                    cmd2->Parameters->AddWithValue("@role", "Student");
                    cmd2->Parameters->AddWithValue("@studentID", studentID);


                    int rowsAffected = cmd2->ExecuteNonQuery();
                    if (rowsAffected == 1)
                        MessageBox::Show("Student added successfully!");
                    else
                        MessageBox::Show("Insert failed.");
                }
                catch (Exception^ ex)
                {
                    MessageBox::Show("Error adding student: " + ex->Message);
                }
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error adding student: " + ex->Message);
            }
            finally
            {
                conn->Close();
            }

			LoadStudents();
        }
        void UpdateStudent(int studentId,
            String^ UniversityID,
            String^ firstName,
            String^ lastName,
            String^ email,
            String^ phone,
            String^ Gender,
            DateTime Dob,
            DateTime addDate,
			String^ username,
			String^ password,
			String^ department,
			String^ faculty,
			String^ academicLevel
            ) {
            if (dgvStudents->SelectedRows->Count == 1 && ValidateInput()) {
                int id = Convert::ToInt32(dgvStudents->SelectedRows[0]->Cells["StudentID"]->Value);
                try {
                    SqlConnection^ conn = gcnew SqlConnection(db->connectionString);
                    String^ query = "UPDATE Student SET FirstName = @FirstName,LastName = @LastName,UniversityID = @UniversityID , Email = @email, Phone = @phone, Gender = @Gender, BirthDate = @Dob, AdmissionDate = @addDate, DepartmentID = @department, FacultyID = @faculty, AcademicLevelID = @academicLevel WHERE StudentId = @StudentId";
                    SqlCommand^ cmd = gcnew SqlCommand(query, conn);
                    cmd->Parameters->AddWithValue("@FirstName", firstName);
                    cmd->Parameters->AddWithValue("@LastName", lastName);
                    cmd->Parameters->AddWithValue("@UniversityID", UniversityID);
                    cmd->Parameters->AddWithValue("@Gender", Gender);
                    cmd->Parameters->AddWithValue("@StudentId", studentId);
                    cmd->Parameters->AddWithValue("@Dob", Dob);
                    cmd->Parameters->AddWithValue("@addDate", addDate);
                    cmd->Parameters->AddWithValue("@email", email);
                    cmd->Parameters->AddWithValue("@phone", phone);
					cmd->Parameters->AddWithValue("@department", Convert::ToInt32(department->Split('-')[0]->Trim()));
					cmd->Parameters->AddWithValue("@faculty", Convert::ToInt32(faculty->Split('-')[0]->Trim()));
					cmd->Parameters->AddWithValue("@academicLevel", Convert::ToInt32(academicLevel->Split('-')[0]->Trim()));


                    conn->Open();
                    int rowsAffected = cmd->ExecuteNonQuery();
                    conn->Close();

                }catch (Exception^ ex) {
                    MessageBox::Show("Error updating student: " + ex->Message);
				}

                LoadStudents();
            }
        }

private: System::Void btnAdd_Click_1(System::Object^ sender, System::EventArgs^ e) {
    AddStudent(txtUniversityID->Text,
        txtFirstName->Text,
        txtLastName->Text,
        txtEmail->Text,
        txtphone->Text,
        dateTimePicker1->Value,
        dateTimePicker2->Value,
		cmbGender->SelectedItem->ToString(),
        textUsername->Text,
		textPassword->Text,
		cbAcademicLevel->SelectedItem->ToString(),
		cbDepartment->SelectedItem->ToString(),
		cbFaculty->SelectedItem->ToString()
    );
}
private: System::Void btnUpdate_Click_1(System::Object^ sender, System::EventArgs^ e) {
    UpdateStudent(
        Convert::ToInt32(dgvStudents->SelectedRows[0]->Cells["StudentID"]->Value),
        txtUniversityID->Text,
        txtFirstName->Text,
        txtLastName->Text,
        txtEmail->Text,
        txtphone->Text,
        cmbGender->SelectedItem->ToString(),
        dateTimePicker1->Value,
        dateTimePicker2->Value,
		textUsername->Text,
		textPassword->Text,
		cbAcademicLevel->SelectedItem->ToString(),
		cbDepartment->SelectedItem->ToString(),
		cbFaculty->SelectedItem->ToString()
    );
}
private: System::Void btnDelete_Click_1(System::Object^ sender, System::EventArgs^ e) {
    try {
        if (dgvStudents->SelectedRows->Count == 0) {
            MessageBox::Show("Please select a student to delete.");
            return;
        }
        DataGridViewRow^ row = dgvStudents->SelectedRows[0];
        String^ studentName = row->Cells["FirstName"]->Value->ToString();
        System::Windows::Forms::DialogResult result = MessageBox::Show("Are you sure you want to delete student: " + studentName + "?", "Confirm Delete", MessageBoxButtons::YesNo);
        if (result != System::Windows::Forms::DialogResult::Yes) {
            return; // User cancelled deletion
        } else {
            int id = Convert::ToInt32(dgvStudents->SelectedRows[0]->Cells["StudentID"]->Value);
            try {
                SqlConnection^ conn = gcnew SqlConnection(db->connectionString);
                String^ query = "DELETE FROM Student WHERE StudentID = @StudentId";
                SqlCommand^ cmd = gcnew SqlCommand(query, conn);
                cmd->Parameters->AddWithValue("@StudentId", id);

                String^ query2 = "DELETE FROM Users WHERE StudentID = @StudentId";
                SqlCommand^ cmd2 = gcnew SqlCommand(query2, conn);
                cmd2->Parameters->AddWithValue("@StudentId", id);

                conn->Open();
                cmd2->ExecuteNonQuery();
                cmd->ExecuteNonQuery();
                conn->Close();

            } catch (Exception^ ex) {
                MessageBox::Show("Error deleting student: " + ex->Message);
			}
            LoadStudents();
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
        return;
    }
}
       void LoadDepartmentOptions()
       {
           cbDepartment->Items->Clear();
           SqlConnection^ conn = gcnew SqlConnection(db->connectionString);

           try
           {
               conn->Open();
               SqlDataAdapter^ adapter = gcnew SqlDataAdapter("SELECT DepartmentID,FacultyID, Name FROM Department", conn);
               DataTable^ dt = gcnew DataTable();
               adapter->Fill(dt);

               for each (DataRow ^ row in dt->Rows)
               {
                   if (FacultyID == Convert::ToInt32(row["FacultyID"])) {

                   cbDepartment->Items->Add(row["DepartmentID"]->ToString() + " - " + row["Name"]->ToString());
                   }
               }
           }
           catch (Exception^ ex)
           {
               MessageBox::Show("Error loading departments: " + ex->Message);
           }
           finally
           {
               conn->Close();
           }
       }

       void LoadFacultyOptions()
       {
           cbFaculty->Items->Clear();
           SqlConnection^ conn = gcnew SqlConnection(db->connectionString);

           try
           {
               conn->Open();
               SqlDataAdapter^ adapter = gcnew SqlDataAdapter("SELECT FacultyID, Name FROM Faculty", conn);
               DataTable^ dt = gcnew DataTable();
               adapter->Fill(dt);

               for each (DataRow ^ row in dt->Rows)
               {

                   cbFaculty->Items->Add(row["FacultyID"]->ToString() + " - " + row["Name"]->ToString());
               }
           }
           catch (Exception^ ex)
           {
               MessageBox::Show("Error loading faculties: " + ex->Message);
           }
           finally
           {
               conn->Close();
           }
       }

       void LoadAcademicLevelOptions()
       {
           cbAcademicLevel->Items->Clear();
           SqlConnection^ conn = gcnew SqlConnection(db->connectionString);

           try
           {
               conn->Open();
               SqlDataAdapter^ adapter = gcnew SqlDataAdapter("SELECT AcademicLevelID, LevelName FROM AcademicLevel", conn);
               DataTable^ dt = gcnew DataTable();
               adapter->Fill(dt);

               for each (DataRow ^ row in dt->Rows)
               {
                   cbAcademicLevel->Items->Add(row["AcademicLevelID"]->ToString() + " - " + row["LevelName"]->ToString());
               }
           }
           catch (Exception^ ex)
           {
               MessageBox::Show("Error loading academic levels: " + ex->Message);
           }
           finally
           {
               conn->Close();
           }
       }

private: System::Void cbFaculty_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    this->FacultyID = Convert::ToInt32(this->cbFaculty->SelectedItem->ToString()->Split('-')[0]->Trim());
    LoadDepartmentOptions();
}
};
}