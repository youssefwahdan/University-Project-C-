#pragma once
#include "Database.h"
#using <System.Configuration.dll>

using namespace System;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Data::SqlClient;
using namespace System::Configuration;
using namespace System::Collections::Generic;


namespace UniversityProject {

    public ref class FeeControl : public System::Windows::Forms::UserControl
    {
    public:
        FeeControl() {
            InitializeComponent();
			db = gcnew Database(GetConnectionString());
            LoadDropdowns();
            LoadFeeGrid();
        }

        System::Windows::Forms::ComboBox^ cbStudent;
        System::Windows::Forms::ComboBox^ cbYear;
        System::Windows::Forms::ComboBox^ cbFeeType;
        TextBox^ txtAmount;
        TextBox^ txtPaid;
        DateTimePicker^ dtDue;
        Button^ btnAddFee;
        DataGridView^ dgvFees;
        Database^ db;
		System::Windows::Forms::Label^ lblStudent;
		System::Windows::Forms::Label^ lblYear;
		System::Windows::Forms::Label^ lblFeeType;
		System::Windows::Forms::Label^ lblAmount;
		System::Windows::Forms::Label^ lblPaid;
		System::Windows::Forms::Label^ lblDue;


        void InitializeComponent()
        {
            this->cbStudent = gcnew ComboBox();
            this->cbYear = gcnew ComboBox();
            this->cbFeeType = gcnew ComboBox();
            this->txtAmount = gcnew TextBox();
            this->txtPaid = gcnew TextBox();
            this->dtDue = gcnew DateTimePicker();
            this->btnAddFee = gcnew Button();
            this->dgvFees = gcnew DataGridView();
            this->lblStudent = gcnew Label();
			this->lblYear = gcnew Label();
			this->lblFeeType = gcnew Label();
			this->lblAmount = gcnew Label();
			this->lblPaid = gcnew Label();
			this->lblDue = gcnew Label();

            this->lblStudent->Text = "Student:";
            this->lblStudent->Location = Point(20, 30);
			this->lblStudent->ForeColor = Color::Black;

            this->cbStudent->Location = Point(100, 30);
            this->cbStudent->Size = Drawing::Size(200, 25);

            this->lblYear->Text = "Academic Year:";
            this->lblYear->Location = Point(320, 30);
			this->lblYear->ForeColor = Color::Black;

            this->cbYear->Location = Point(420, 30);
            this->cbYear->Size = Drawing::Size(150, 25);

            this->lblFeeType->Text = "Fee Type:";
            this->lblFeeType->Location = Point(20, 70);
			this->lblFeeType->ForeColor = Color::Black;


            this->cbFeeType->Location = Point(100, 70);
            this->cbFeeType->Size = Drawing::Size(200, 25);

            this->lblAmount->Text = "Amount:";
            this->lblAmount->Location = Point(320, 70);
			this->lblAmount->ForeColor = Color::Black;

            this->txtAmount->Location = Point(420, 70);
            this->txtAmount->Size = Drawing::Size(100, 25);

            this->lblPaid->Text = "Paid:";
            this->lblPaid->Location = Point(540, 70);
			this->lblPaid->ForeColor = Color::Black;

            this->txtPaid->Location = Point(590, 70);
            this->txtPaid->Size = Drawing::Size(100, 25);

            this->lblDue->Text = "Due Date:";
            this->lblDue->Location = Point(20, 110);
			this->lblDue->ForeColor = Color::Black;

            this->dtDue->Location = Point(100, 110);
            this->dtDue->Size = Drawing::Size(200, 25);

			this->btnAddFee->Text = "Add Fee";
			this->btnAddFee->Location = Point(320, 110);
			this->btnAddFee->Size = Drawing::Size(100, 30);
			this->btnAddFee->BackColor = Color::LightSeaGreen;
			this->btnAddFee->ForeColor = Color::White;
			this->btnAddFee->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnAddFee->Cursor = Cursors::Hand;
			this->btnAddFee->Click += gcnew EventHandler(this, &FeeControl::AddFee);

            this->dgvFees->Location = Point(20, 160);
            this->dgvFees->Size = Drawing::Size(1040, 300);
            this->dgvFees->ReadOnly = true;
            this->dgvFees->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvFees->Dock = DockStyle::Bottom;

            this->Controls->Add(btnAddFee);
            this->Controls->Add(dtDue);
            this->Controls->Add(txtPaid);
            this->Controls->Add(txtAmount);
            this->Controls->Add(cbFeeType);
            this->Controls->Add(cbYear);
            this->Controls->Add(cbStudent);
            this->Controls->Add(dgvFees);
			this->Controls->Add(lblStudent);
			this->Controls->Add(lblYear);
			this->Controls->Add(lblFeeType);
			this->Controls->Add(lblAmount);
			this->Controls->Add(lblPaid);
            this->Controls->Add(lblDue);

			this->Padding = System::Windows::Forms::Padding(10);
            this->Size = System::Drawing::Size(1080, 480);
        }

        void LoadDropdowns()
        {
            SqlConnection^ conn = gcnew SqlConnection(db->connectionString);

            try
            {
                conn->Open();

                // Students
				List<String^>^ students = gcnew List<String^>();
                SqlDataAdapter^ cmdStudent = gcnew SqlDataAdapter("SELECT StudentID, FirstName + ' ' + LastName AS FullName FROM Student", conn);
				DataTable^ dtStudents = gcnew DataTable();
				cmdStudent->Fill(dtStudents);
				for each (DataRow ^ row in dtStudents->Rows)
				{
					students->Add(row["StudentID"]->ToString() + " - " + row["FullName"]->ToString());
				}
				cbStudent->DataSource = students;


                // Academic Years
				List<String^ > ^ years = gcnew List<String^>();
                SqlDataAdapter^ cmdYear = gcnew SqlDataAdapter("SELECT AcademicYearID, YearName FROM AcademicYear", conn);
				DataTable^ dtYears = gcnew DataTable();
				cmdYear->Fill(dtYears);
                for each (DataRow ^ row in dtYears->Rows)
                {
                    years->Add(row["AcademicYearID"]->ToString() + " - " + row["YearName"]->ToString());
                }
				this->cbYear->DataSource = years;

                // Fee Types
				List<String^>^ feeTypes = gcnew List<String^>();
                SqlDataAdapter^ cmdFee = gcnew SqlDataAdapter("SELECT FeeTypeID, Name FROM FeeType", conn);
				DataTable^ dtFees = gcnew DataTable();
				cmdFee->Fill(dtFees);
                for each (DataRow ^ row in dtFees->Rows)
                {
                    feeTypes->Add(row["FeeTypeID"]->ToString() + " - " + row["Name"]->ToString());
				}
				cbFeeType->DataSource = feeTypes;
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error loading dropdowns: " + ex->Message);
            }
            finally
            {
                conn->Close();
            }
        }

        void AddFee(Object^ sender, EventArgs^ e)
        {
            if (cbStudent->SelectedItem == nullptr || cbYear->SelectedItem == nullptr || cbFeeType->SelectedItem == nullptr)
            {
                MessageBox::Show("Please select all fields.");
                return;
            }

            int studentID = Convert::ToInt32(cbStudent->SelectedItem->ToString()->Split('-')[0]->Trim());
            int yearID = Convert::ToInt32(cbYear->SelectedItem->ToString()->Split('-')[0]->Trim());
            int feeTypeID = Convert::ToInt32(cbFeeType->SelectedItem->ToString()->Split('-')[0]->Trim());
            double amount = Convert::ToDouble(txtAmount->Text);
            double paid = Convert::ToDouble(txtPaid->Text);
            DateTime due = dtDue->Value;

            SqlConnection^ conn = gcnew SqlConnection(db->connectionString);

            try
            {
                conn->Open();

                String^ query = "INSERT INTO StudentFee (StudentID, AcademicYearID, FeeTypeID, Amount, PaidAmount, DueDate) " +
                    "VALUES (@sid, @year, @ftid, @amt, @paid, @due)";

                SqlCommand^ cmd = gcnew SqlCommand(query, conn);
                cmd->Parameters->AddWithValue("@sid", studentID);
                cmd->Parameters->AddWithValue("@year", yearID);
                cmd->Parameters->AddWithValue("@ftid", feeTypeID);
                cmd->Parameters->AddWithValue("@amt", amount);
                cmd->Parameters->AddWithValue("@paid", paid);
                cmd->Parameters->AddWithValue("@due", due);

                cmd->ExecuteNonQuery();
                MessageBox::Show("Fee added successfully!");
                LoadFeeGrid();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error adding fee: " + ex->Message);
            }
            finally
            {
                conn->Close();
            }
        }

        void LoadFeeGrid()
        {
            dgvFees->Columns->Clear();
            dgvFees->Rows->Clear();

            SqlConnection^ conn = gcnew SqlConnection(db->connectionString);

            try
            {
                conn->Open();

                SqlCommand^ cmd = gcnew SqlCommand(
                    "SELECT sf.StudentFeeID, s.StudentID, s.FirstName + ' ' + s.LastName AS StudentName, ay.YearName, ft.Name AS FeeType, sf.Amount, sf.PaidAmount, sf.DueDate " +
                    "FROM StudentFee sf " +
                    "JOIN Student s ON sf.StudentID = s.StudentID " +
                    "JOIN AcademicYear ay ON sf.AcademicYearID = ay.AcademicYearID " +
                    "JOIN FeeType ft ON sf.FeeTypeID = ft.FeeTypeID", conn);

                SqlDataReader^ reader = cmd->ExecuteReader();
                dgvFees->Columns->Add("FeeID", "Fee ID");
                dgvFees->Columns->Add("StudentID", "Student ID");
                dgvFees->Columns->Add("StudentName", "Student Name");
                dgvFees->Columns->Add("Year", "Academic Year");
                dgvFees->Columns->Add("FeeType", "Fee Type");
                dgvFees->Columns->Add("Amount", "Amount");
                dgvFees->Columns->Add("Paid", "Paid");
                dgvFees->Columns->Add("DueDate", "Due Date");

                while (reader->Read())
                {
                    dgvFees->Rows->Add(
                        reader["StudentFeeID"]->ToString(),
                        reader["StudentID"]->ToString(),
                        reader["StudentName"]->ToString(),
                        reader["YearName"]->ToString(),
                        reader["FeeType"]->ToString(),
                        reader["Amount"]->ToString(),
                        reader["PaidAmount"]->ToString(),
                        Convert::ToDateTime(reader["DueDate"]).ToShortDateString()
                    );
                }
                reader->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error loading fee grid: " + ex->Message);
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