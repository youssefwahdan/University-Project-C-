#pragma once
#include "Database.h"
#using <System.Configuration.dll>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Configuration;

namespace UniversityProject {
	public ref class StudentFeeControl : public System::Windows::Forms::UserControl
    {
    public:
        StudentFeeControl(int studentID)
        {
            InitializeComponent();
			db = gcnew Database(GetConnectionString());
            LoadStudentFees(studentID);
        }

    private:
        TabControl^ tabControl;
        TabPage^ feeTab;
        DataGridView^ dgvFees;
		Database^ db;

        void InitializeComponent()
        {
            this->Text = "Student Form";
            this->Size = System::Drawing::Size(900, 600);

            this->tabControl = gcnew TabControl();
            this->tabControl->Dock = DockStyle::Fill;
            
            this->feeTab = gcnew TabPage("Fees");
            this->dgvFees = gcnew DataGridView();
            
            this->dgvFees->Dock = DockStyle::Fill;
            this->dgvFees->ReadOnly = true;
            this->dgvFees->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            
            this->feeTab->Controls->Add(dgvFees);
            this->tabControl->TabPages->Add(feeTab);

            this->Controls->Add(tabControl);
        }

        void LoadStudentFees(int studentID)
        {
            this->dgvFees->Columns->Clear();
            this->dgvFees->Rows->Clear();

            SqlConnection^ conn = gcnew SqlConnection(db->connectionString);

            try
            {
                conn->Open();

                SqlDataAdapter^ adapter = gcnew SqlDataAdapter(
                    "SELECT ay.YearName, ft.Name AS FeeType, sf.Amount, sf.PaidAmount, sf.DueDate " +
                    "FROM StudentFee sf " +
                    "JOIN AcademicYear ay ON sf.AcademicYearID = ay.AcademicYearID " +
                    "JOIN FeeType ft ON sf.FeeTypeID = ft.FeeTypeID " +
                    "WHERE sf.StudentID = @sid", conn);

                adapter->SelectCommand->Parameters->AddWithValue("@sid", studentID);

                DataTable^ dt = gcnew DataTable();
                adapter->Fill(dt);

                dgvFees->Columns->Add("Year", "Academic Year");
                dgvFees->Columns->Add("FeeType", "Fee Type");
                dgvFees->Columns->Add("Amount", "Amount");
                dgvFees->Columns->Add("Paid", "Paid");
                dgvFees->Columns->Add("DueDate", "Due Date");

                for each (DataRow ^ row in dt->Rows)
                {
                    dgvFees->Rows->Add(
                        row["YearName"]->ToString(),
                        row["FeeType"]->ToString(),
                        row["Amount"]->ToString(),
                        row["PaidAmount"]->ToString(),
                        Convert::ToDateTime(row["DueDate"]).ToShortDateString()
                    );
                }
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error loading fees: " + ex->Message);
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
