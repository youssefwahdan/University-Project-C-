#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace UniversityProject {

	/// <summary>
	/// Summary for ProfessorProfileControl
	/// </summary>
	public ref class ProfessorProfileControl : public System::Windows::Forms::UserControl
	{
	public:
		ProfessorProfileControl(String^ FirstName, String^ LastName, String^ DepartmentName, String^ FacultyName, String^ Code, DateTime HireDate)
		{
			InitializeComponent();
			fullNameValue->Text = FirstName + " " + LastName;
			CodeValue->Text = Code;
			departmentValue->Text = DepartmentName;
			facultyValue->Text = FacultyName;
			HireDateValue->Text = HireDate.ToString("dd/MM/yyyy");
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProfessorProfileControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ fullNameLabel;
	private: System::Windows::Forms::Label^ fullNameValue;
	private: System::Windows::Forms::Label^ CodeLabel;
	private: System::Windows::Forms::Label^ CodeValue;
	private: System::Windows::Forms::Label^ departmentLabel;
	private: System::Windows::Forms::Label^ departmentValue;
	private: System::Windows::Forms::Label^ facultyLabel;
	private: System::Windows::Forms::Label^ facultyValue;
	private: System::Windows::Forms::Label^ HireDateLabel;
	private: System::Windows::Forms::Label^ HireDateValue;




	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->fullNameLabel = (gcnew System::Windows::Forms::Label());
			this->fullNameValue = (gcnew System::Windows::Forms::Label());
			this->CodeLabel = (gcnew System::Windows::Forms::Label());
			this->CodeValue = (gcnew System::Windows::Forms::Label());
			this->departmentLabel = (gcnew System::Windows::Forms::Label());
			this->departmentValue = (gcnew System::Windows::Forms::Label());
			this->facultyLabel = (gcnew System::Windows::Forms::Label());
			this->facultyValue = (gcnew System::Windows::Forms::Label());
			this->HireDateLabel = (gcnew System::Windows::Forms::Label());
			this->HireDateValue = (gcnew System::Windows::Forms::Label());
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
			// CodeLabel
			// 
			this->CodeLabel->AutoSize = true;
			this->CodeLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->CodeLabel->Location = System::Drawing::Point(22, 69);
			this->CodeLabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->CodeLabel->Name = L"CodeLabel";
			this->CodeLabel->Size = System::Drawing::Size(72, 32);
			this->CodeLabel->TabIndex = 2;
			this->CodeLabel->Text = L"Code";
			// 
			// CodeValue
			// 
			this->CodeValue->AutoSize = true;
			this->CodeValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->CodeValue->ForeColor = System::Drawing::Color::ForestGreen;
			this->CodeValue->Location = System::Drawing::Point(281, 68);
			this->CodeValue->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->CodeValue->Name = L"CodeValue";
			this->CodeValue->Size = System::Drawing::Size(0, 32);
			this->CodeValue->TabIndex = 3;
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
			// HireDateLabel
			// 
			this->HireDateLabel->AutoSize = true;
			this->HireDateLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->HireDateLabel->Location = System::Drawing::Point(22, 231);
			this->HireDateLabel->Name = L"HireDateLabel";
			this->HireDateLabel->Size = System::Drawing::Size(122, 32);
			this->HireDateLabel->TabIndex = 10;
			this->HireDateLabel->Text = L"Hire Date";
			// 
			// HireDateValue
			// 
			this->HireDateValue->AutoSize = true;
			this->HireDateValue->ForeColor = System::Drawing::Color::ForestGreen;
			this->HireDateValue->Location = System::Drawing::Point(281, 230);
			this->HireDateValue->Name = L"HireDateValue";
			this->HireDateValue->Size = System::Drawing::Size(0, 32);
			this->HireDateValue->TabIndex = 11;
			// 
			// ProfessorProfileControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->HireDateValue);
			this->Controls->Add(this->HireDateLabel);
			this->Controls->Add(this->facultyValue);
			this->Controls->Add(this->facultyLabel);
			this->Controls->Add(this->departmentValue);
			this->Controls->Add(this->departmentLabel);
			this->Controls->Add(this->CodeValue);
			this->Controls->Add(this->CodeLabel);
			this->Controls->Add(this->fullNameValue);
			this->Controls->Add(this->fullNameLabel);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->Name = L"ProfessorProfileControl";
			this->Size = System::Drawing::Size(982, 926);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}