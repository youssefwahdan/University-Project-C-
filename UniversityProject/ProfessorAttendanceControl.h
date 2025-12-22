#using <System.Configuration.dll>
#include "Database.h"
#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Configuration;

namespace UniversityProject {
    public ref class ProfessorAttendanceControl : public System::Windows::Forms::UserControl
    {
    public:
        ProfessorAttendanceControl(int professorID) {
            InitializeComponent(); 
			db = gcnew Database(GetConnectionString());
            this->professorID = professorID; 
            LoadOfferings(); }

    private:
        int professorID;
        ComboBox^ cbOffering;
        DataGridView^ dgvLectures;
        DataGridView^ dgvStudents;
        Button^ btnCreateLecture;
        Button^ btnMarkAttendance;
        Button^ btnExport;
		Database^ db;

        void InitializeComponent(void)
        {
            // Offering dropdown
            this->cbOffering = gcnew ComboBox();
            this->cbOffering->Location = Point(20, 20);
            this->cbOffering->Size = System::Drawing::Size(300, 25);
            this->cbOffering->DropDownStyle = ComboBoxStyle::DropDownList;
            //this->cbOffering->SelectedIndexChanged += gcnew EventHandler(this, &ProfessorAttendanceControl::LoadLectures);

            // Lecture list
            this->dgvLectures = gcnew DataGridView();
            this->dgvLectures->Size = System::Drawing::Size(400, 150);
            this->dgvLectures->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            this->dgvLectures->ReadOnly = true;
            this->dgvLectures->SelectionMode = DataGridViewSelectionMode::FullRowSelect;

            this->dgvLectures->Columns->Add("Date", "Date");
            this->dgvLectures->Columns->Add("Topic", "Topic");
            this->dgvLectures->Columns->Add("Room", "Room");
            this->dgvLectures->Columns->Add("Status", "Status");
			this->dgvLectures->Dock = DockStyle::Bottom;

            this->dgvLectures->CellClick += gcnew DataGridViewCellEventHandler(this, &ProfessorAttendanceControl::LoadStudents);

            // Student roster
            this->dgvStudents = gcnew DataGridView();
            this->dgvStudents->Size = System::Drawing::Size(400, 200);
            this->dgvStudents->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

            this->dgvStudents->Columns->Add("UniversityID", "University ID");
            this->dgvStudents->Columns->Add("Name", "Name");
			this->Margin = System::Windows::Forms::Padding(10);
            this->dgvStudents->Dock = DockStyle::Bottom;


            DataGridViewComboBoxColumn^ colStatus = gcnew DataGridViewComboBoxColumn();
            colStatus->HeaderText = "Attendance";
            colStatus->Items->AddRange(gcnew cli::array<Object^>{"Present", "Absent", "Late"});
            this->dgvStudents->Columns->Add(colStatus);

            // Buttons
            this->btnCreateLecture = gcnew Button();
            this->btnCreateLecture->Location = Point(500, 20);
            this->btnCreateLecture->Size = System::Drawing::Size(100, 30);
            this->btnCreateLecture->Text = "Create Lecture";
            this->btnCreateLecture->Click += gcnew EventHandler(this, &ProfessorAttendanceControl::CreateLecture);
            
            this->btnMarkAttendance = gcnew Button();
            this->btnMarkAttendance->Location = Point(500, 60);
            this->btnMarkAttendance->Size = System::Drawing::Size(100, 30);
            this->btnMarkAttendance->Text = "Mark Attendance";
            this->btnMarkAttendance->Click += gcnew EventHandler(this, &ProfessorAttendanceControl::SaveAttendance);
            
            this->btnExport = gcnew Button();
            this->btnExport->Location = Point(500, 100);
            this->btnExport->Size = System::Drawing::Size(100, 30);
            this->btnExport->Text = "Export Report";
            this->btnExport->Click += gcnew EventHandler(this, &ProfessorAttendanceControl::ExportReport);

            // Add controls
            this->Controls->Add(cbOffering);
            this->Controls->Add(dgvLectures);
            this->Controls->Add(dgvStudents);
            this->Controls->Add(btnCreateLecture);
            this->Controls->Add(btnMarkAttendance);
            this->Controls->Add(btnExport);
			this->Dock = DockStyle::Fill;
			this->Padding = System::Windows::Forms::Padding(10);
            this->Size = System::Drawing::Size(850, 480);
        }

        // Load offerings into dropdown
        void LoadOfferings()
        {
            SqlConnection^ conn = gcnew SqlConnection(db->connectionString);

            try
            {
                conn->Open();
                SqlCommand^ cmd = gcnew SqlCommand("SELECT CourseID, SectionNumber, GroupNumber FROM CourseOffering WHERE ProfessorID=@pid", conn);
                cmd->Parameters->AddWithValue("@pid", professorID);

                SqlDataReader^ reader = cmd->ExecuteReader();
                while (reader->Read())
                {
                    String^ offering = "Course " + reader["CourseID"]->ToString() +
                        " - Sec " + reader["SectionNumber"]->ToString() +
                        " - Group " + reader["GroupNumber"]->ToString();
                    cbOffering->Items->Add(offering);
                }
                reader->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error loading offerings: " + ex->Message);
            }
            finally
            {
                conn->Close();
            }
        }

        // Load lectures for selected offering
        //void LoadLectures(Object^ sender, EventArgs^ e)
        //{
        //    dgvLectures->Rows->Clear();

        //    if (cbOffering->SelectedItem == nullptr) return;

        //    String^ selectedOffering = cbOffering->SelectedItem->ToString();

        //    // Example parsing: "Course 12 - Sec A - Group 1"
        //    // Extract CourseID, Section, Group
        //    array<String^>^ parts = selectedOffering->Split('-');
        //    String^ coursePart = parts[0]->Trim();   // "Course 12"
        //    String^ sectionPart = parts[1]->Trim();  // "Sec A"
        //    String^ groupPart = parts[2]->Trim();    // "Group 1"

        //    //int courseID = Convert::ToInt32(coursePart->Replace("Course", "").Trim());
        //    //String^ section = sectionPart->Replace("Sec", "").Trim();
        //    //String^ group = groupPart->Replace("Group", "").Trim();

        //    SqlConnection^ conn = gcnew SqlConnection(db->connectionString);

        //    try
        //    {
        //        conn->Open();

        //        // Step 1: Get OfferingID
        //        SqlCommand^ cmdOffer = gcnew SqlCommand(
        //            "SELECT OfferingID FROM CourseOffering WHERE CourseID=@cid AND SectionNumber=@sec AND GroupNumber=@grp", conn);
        //        cmdOffer->Parameters->AddWithValue("@cid", 3);
        //        cmdOffer->Parameters->AddWithValue("@sec", "C");
        //        cmdOffer->Parameters->AddWithValue("@grp", "G2");

        //        Object^ offeringObj = cmdOffer->ExecuteScalar();
        //        if (offeringObj == nullptr)
        //        {
        //            MessageBox::Show("No offering found for selection.");
        //            return;
        //        }
        //        int offeringID = Convert::ToInt32(offeringObj);

        //        // Step 2: Get Lectures for Offering
        //        SqlCommand^ cmdLectures = gcnew SqlCommand(
        //            "SELECT LectureDate, Topic, Room, Status FROM Lecture WHERE OfferingID=@offid", conn);
        //        cmdLectures->Parameters->AddWithValue("@offid", offeringID);

        //        SqlDataReader^ reader = cmdLectures->ExecuteReader();
        //        while (reader->Read())
        //        {
        //            String^ date = Convert::ToDateTime(reader["LectureDate"]).ToShortDateString();
        //            String^ topic = reader["Topic"]->ToString();
        //            String^ room = reader["Room"]->ToString();
        //            String^ status = reader["Status"]->ToString();

        //            dgvLectures->Rows->Add(date, topic, room, status);
        //        }
        //        reader->Close();
        //    }
        //    catch (Exception^ ex)
        //    {
        //        MessageBox::Show("Error loading lectures: " + ex->Message);
        //    }
        //    finally
        //    {
        //        conn->Close();
        //    }
        //}


        // Load students for selected lecture
        void LoadStudents(Object^ sender, DataGridViewCellEventArgs^ e)
        {
            this->dgvStudents->Rows->Clear();

            // Query Enrollment table by OfferingID and add students
            // Example: SELECT UniversityID, Name FROM Student WHERE OfferingID=@offid
        }

        // Create new lecture
        void CreateLecture(Object^ sender, EventArgs^ e)
        {
            MessageBox::Show("Open modal to create lecture (Date, Topic, Room).");
        }

        // Save attendance
        void SaveAttendance(Object^ sender, EventArgs^ e)
        {
            for each (DataGridViewRow ^ row in dgvStudents->Rows)
            {
                try {

                String^ studentID = row->Cells["UniversityID"]->Value->ToString();
                String^ status = row->Cells[2]->Value->ToString(); // Attendance column
                // INSERT/UPDATE Attendance table with studentID, lectureID, status
                }
                catch (Exception^ ex) {
                    MessageBox::Show("Error saving attendance for student: " + ex->Message);
				}
            }
            MessageBox::Show("Attendance saved!");
        }

        // Export report
        void ExportReport(Object^ sender, EventArgs^ e)
        {
            MessageBox::Show("Export attendance report to CSV/PDF here.");
        }
        String^ GetConnectionString()
        {
            // Use System::Configuration::ConfigurationManager to access connection strings
            return System::Configuration::ConfigurationManager::ConnectionStrings["UniversityDb"]->ConnectionString;
        }
    };
}