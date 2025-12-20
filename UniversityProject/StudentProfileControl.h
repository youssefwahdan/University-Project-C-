#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace UniversityProject {

	/// <summary>
	/// Summary for StudentProfileControl
	/// </summary>
	public ref class StudentProfileControl : public System::Windows::Forms::UserControl
	{
	public:
		StudentProfileControl(String^ FirstName, String^ LastName, String^ DepartmentName, String^ FacultyName, String^ AcademicLevelName, String^ UniversityID, DateTime AdmissionDate)
		{
			InitializeComponent();
			fullNameValue->Text = FirstName + " " + LastName;
			universityIDValue->Text = UniversityID;
			departmentValue->Text = DepartmentName;
			facultyValue->Text = FacultyName;
			academicLevelValue->Text = AcademicLevelName;
			admissionDateValue->Text = AdmissionDate.ToString("dd/MM/yyyy");
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StudentProfileControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ fullNameLabel;
	private: System::Windows::Forms::Label^ fullNameValue;
	private: System::Windows::Forms::Label^ UniversityIDLabel;
	private: System::Windows::Forms::Label^ universityIDValue;
	private: System::Windows::Forms::Label^ departmentLabel;
	private: System::Windows::Forms::Label^ departmentValue;
	private: System::Windows::Forms::Label^ facultyLabel;
	private: System::Windows::Forms::Label^ facultyValue;
	private: System::Windows::Forms::Label^ academicLevelLabel;
	private: System::Windows::Forms::Label^ academicLevelValue;
	private: System::Windows::Forms::Label^ admissionDateLabel;
	private: System::Windows::Forms::Label^ admissionDateValue;




	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->fullNameLabel = (gcnew System::Windows::Forms::Label());
			this->fullNameValue = (gcnew System::Windows::Forms::Label());
			this->UniversityIDLabel = (gcnew System::Windows::Forms::Label());
			this->universityIDValue = (gcnew System::Windows::Forms::Label());
			this->departmentLabel = (gcnew System::Windows::Forms::Label());
			this->departmentValue = (gcnew System::Windows::Forms::Label());
			this->facultyLabel = (gcnew System::Windows::Forms::Label());
			this->facultyValue = (gcnew System::Windows::Forms::Label());
			this->academicLevelLabel = (gcnew System::Windows::Forms::Label());
			this->academicLevelValue = (gcnew System::Windows::Forms::Label());
			this->admissionDateLabel = (gcnew System::Windows::Forms::Label());
			this->admissionDateValue = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// fullNameLabel
			// 
			this->fullNameLabel->AutoSize = true;
			this->fullNameLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->fullNameLabel->Location = System::Drawing::Point(22, 19);
			this->fullNameLabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->fullNameLabel->Name = L"fullNameLabel";
			this->fullNameLabel->Size = System::Drawing::Size(129, 32);
			this->fullNameLabel->TabIndex = 0;
			this->fullNameLabel->Text = L"Full Name";
			// 
			// fullNameValue
			// 
			this->fullNameValue->AutoSize = true;
			this->fullNameValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->fullNameValue->ForeColor = System::Drawing::Color::ForestGreen;
			this->fullNameValue->Location = System::Drawing::Point(281, 19);
			this->fullNameValue->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->fullNameValue->Name = L"fullNameValue";
			this->fullNameValue->Size = System::Drawing::Size(0, 32);
			this->fullNameValue->TabIndex = 1;
			// 
			// UniversityIDLabel
			// 
			this->UniversityIDLabel->AutoSize = true;
			this->UniversityIDLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->UniversityIDLabel->Location = System::Drawing::Point(22, 69);
			this->UniversityIDLabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->UniversityIDLabel->Name = L"UniversityIDLabel";
			this->UniversityIDLabel->Size = System::Drawing::Size(162, 32);
			this->UniversityIDLabel->TabIndex = 2;
			this->UniversityIDLabel->Text = L"University ID";
			// 
			// universityIDValue
			// 
			this->universityIDValue->AutoSize = true;
			this->universityIDValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->universityIDValue->ForeColor = System::Drawing::Color::ForestGreen;
			this->universityIDValue->Location = System::Drawing::Point(281, 68);
			this->universityIDValue->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->universityIDValue->Name = L"universityIDValue";
			this->universityIDValue->Size = System::Drawing::Size(0, 32);
			this->universityIDValue->TabIndex = 3;
			// 
			// departmentLabel
			// 
			this->departmentLabel->AutoSize = true;
			this->departmentLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->departmentLabel->Location = System::Drawing::Point(22, 122);
			this->departmentLabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->departmentLabel->Name = L"departmentLabel";
			this->departmentLabel->Size = System::Drawing::Size(152, 32);
			this->departmentLabel->TabIndex = 4;
			this->departmentLabel->Text = L"Department";
			// 
			// departmentValue
			// 
			this->departmentValue->AutoSize = true;
			this->departmentValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->departmentValue->ForeColor = System::Drawing::Color::ForestGreen;
			this->departmentValue->Location = System::Drawing::Point(280, 121);
			this->departmentValue->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->departmentValue->Name = L"departmentValue";
			this->departmentValue->Size = System::Drawing::Size(0, 32);
			this->departmentValue->TabIndex = 5;
			// 
			// facultyLabel
			// 
			this->facultyLabel->AutoSize = true;
			this->facultyLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->facultyLabel->Location = System::Drawing::Point(22, 176);
			this->facultyLabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->facultyLabel->Name = L"facultyLabel";
			this->facultyLabel->Size = System::Drawing::Size(94, 32);
			this->facultyLabel->TabIndex = 6;
			this->facultyLabel->Text = L"Faculty";
			// 
			// facultyValue
			// 
			this->facultyValue->AutoSize = true;
			this->facultyValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->facultyValue->ForeColor = System::Drawing::Color::ForestGreen;
			this->facultyValue->Location = System::Drawing::Point(281, 175);
			this->facultyValue->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->facultyValue->Name = L"facultyValue";
			this->facultyValue->Size = System::Drawing::Size(0, 32);
			this->facultyValue->TabIndex = 7;
			// 
			// academicLevelLabel
			// 
			this->academicLevelLabel->AutoSize = true;
			this->academicLevelLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->academicLevelLabel->Location = System::Drawing::Point(22, 229);
			this->academicLevelLabel->Name = L"academicLevelLabel";
			this->academicLevelLabel->Size = System::Drawing::Size(190, 32);
			this->academicLevelLabel->TabIndex = 8;
			this->academicLevelLabel->Text = L"Academic Level";
			// 
			// academicLevelValue
			// 
			this->academicLevelValue->AutoSize = true;
			this->academicLevelValue->ForeColor = System::Drawing::Color::ForestGreen;
			this->academicLevelValue->Location = System::Drawing::Point(280, 228);
			this->academicLevelValue->Name = L"academicLevelValue";
			this->academicLevelValue->Size = System::Drawing::Size(0, 32);
			this->academicLevelValue->TabIndex = 9;
			// 
			// admissionDateLabel
			// 
			this->admissionDateLabel->AutoSize = true;
			this->admissionDateLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->admissionDateLabel->Location = System::Drawing::Point(22, 284);
			this->admissionDateLabel->Name = L"admissionDateLabel";
			this->admissionDateLabel->Size = System::Drawing::Size(194, 32);
			this->admissionDateLabel->TabIndex = 10;
			this->admissionDateLabel->Text = L"Admission Date";
			// 
			// admissionDateValue
			// 
			this->admissionDateValue->AutoSize = true;
			this->admissionDateValue->ForeColor = System::Drawing::Color::ForestGreen;
			this->admissionDateValue->Location = System::Drawing::Point(281, 283);
			this->admissionDateValue->Name = L"admissionDateValue";
			this->admissionDateValue->Size = System::Drawing::Size(0, 32);
			this->admissionDateValue->TabIndex = 11;
			// 
			// StudentProfileControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->admissionDateValue);
			this->Controls->Add(this->admissionDateLabel);
			this->Controls->Add(this->academicLevelValue);
			this->Controls->Add(this->academicLevelLabel);
			this->Controls->Add(this->facultyValue);
			this->Controls->Add(this->facultyLabel);
			this->Controls->Add(this->departmentValue);
			this->Controls->Add(this->departmentLabel);
			this->Controls->Add(this->universityIDValue);
			this->Controls->Add(this->UniversityIDLabel);
			this->Controls->Add(this->fullNameValue);
			this->Controls->Add(this->fullNameLabel);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->Name = L"StudentProfileControl";
			this->Size = System::Drawing::Size(982, 926);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
