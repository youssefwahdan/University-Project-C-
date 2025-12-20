#using <System.Configuration.dll>
#include "Database.h"
#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Configuration;
public ref class DetailedGradesForm : public System::Windows::Forms::Form
{
private:
    System::Windows::Forms::Label^ lblAss1;
    System::Windows::Forms::Label^ lblAss2;
    System::Windows::Forms::Label^ lblCW;
    System::Windows::Forms::Label^ lblFinal;
    Database^ db;
    int GradeID;
    String^ CourseCode;

public:
    DetailedGradesForm(int GradeID, String^ CourseCode)
    {
        InitializeComponent();
        this->CourseCode = CourseCode;
        this->GradeID = GradeID;
        db = gcnew Database(GetConnectionString());
        LoadGradeBreakdown();

    }

private:
    void InitializeComponent()
    {
        this->lblAss1 = (gcnew System::Windows::Forms::Label());
        this->lblAss2 = (gcnew System::Windows::Forms::Label());
        this->lblCW = (gcnew System::Windows::Forms::Label());
        this->lblFinal = (gcnew System::Windows::Forms::Label());
        this->SuspendLayout();
        // 
        // lblAss1
        // 
        this->lblAss1->Dock = System::Windows::Forms::DockStyle::Top;
        this->lblAss1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->lblAss1->ForeColor = System::Drawing::Color::Black;
        this->lblAss1->Location = System::Drawing::Point(10, 10);
        this->lblAss1->Name = L"lblAss1";
        this->lblAss1->Size = System::Drawing::Size(449, 23);
        this->lblAss1->TabIndex = 3;
        // 
        // lblAss2
        // 
        this->lblAss2->Dock = System::Windows::Forms::DockStyle::Top;
        this->lblAss2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->lblAss2->ForeColor = System::Drawing::Color::Black;
        this->lblAss2->Location = System::Drawing::Point(10, 33);
        this->lblAss2->Name = L"lblAss2";
        this->lblAss2->Size = System::Drawing::Size(449, 23);
        this->lblAss2->TabIndex = 2;
        // 
        // lblCW
        // 
        this->lblCW->Dock = System::Windows::Forms::DockStyle::Top;
        this->lblCW->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->lblCW->ForeColor = System::Drawing::Color::Black;
        this->lblCW->Location = System::Drawing::Point(10, 56);
        this->lblCW->Name = L"lblCW";
        this->lblCW->Size = System::Drawing::Size(449, 23);
        this->lblCW->TabIndex = 1;
        // 
        // lblFinal
        // 
        this->lblFinal->Dock = System::Windows::Forms::DockStyle::Top;
        this->lblFinal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->lblFinal->ForeColor = System::Drawing::Color::Black;
        this->lblFinal->Location = System::Drawing::Point(10, 79);
        this->lblFinal->Name = L"lblFinal";
        this->lblFinal->Size = System::Drawing::Size(449, 23);
        this->lblFinal->TabIndex = 0;
        // 
        // DetailedGradesForm
        // 
        this->ClientSize = System::Drawing::Size(469, 324);
        this->Controls->Add(this->lblFinal);
        this->Controls->Add(this->lblCW);
        this->Controls->Add(this->lblAss2);
        this->Controls->Add(this->lblAss1);
        this->Name = L"DetailedGradesForm";
        this->Padding = System::Windows::Forms::Padding(10);
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
        this->ResumeLayout(false);

    }
    void LoadGradeBreakdown() {
        try {
            SqlDataReader^ reader = db->LoadGradeBreakdown(GradeID);
            if (reader->Read()) {
                this->Text = "Detailed Grades - " + this->CourseCode;
                this->lblAss1->Text = "Assignment 1: " + reader["Ass1"];
                this->lblAss2->Text = "Assignment 2: " + reader["Ass2"];
                this->lblCW->Text = "Coursework: " + reader["CW"];
                this->lblFinal->Text = "Final Exam: " + reader["FinalExam"];
            }
            reader->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message);
        }
    }
    String^ GetConnectionString()
    {
        // Use System::Configuration::ConfigurationManager to access connection strings
        return System::Configuration::ConfigurationManager::ConnectionStrings["UniversityDb"]->ConnectionString;
    }
};
