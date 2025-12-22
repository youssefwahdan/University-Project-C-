#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace UniversityProject {

	public ref class AdminProfileControl : public System::Windows::Forms::UserControl
	{
	public:
		AdminProfileControl(String^ FirstName, String^ LastName, String^ Code, String^ Phone, String^ Email, DateTime HireDate)
		{
			InitializeComponent();
			fullNameValue->Text = FirstName + " " + LastName;
			CodeValue->Text = Code;
			phoneValue->Text = Phone;
			emailValue->Text = Email;
			HireDateValue->Text = HireDate.ToString("dd/MM/yyyy");

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminProfileControl()
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
	private: System::Windows::Forms::Label^ phoneLabel;
	private: System::Windows::Forms::Label^ phoneValue;
	private: System::Windows::Forms::Label^ emailLabel;
	private: System::Windows::Forms::Label^ emailValue;
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
			this->phoneLabel = (gcnew System::Windows::Forms::Label());
			this->phoneValue = (gcnew System::Windows::Forms::Label());
			this->emailLabel = (gcnew System::Windows::Forms::Label());
			this->emailValue = (gcnew System::Windows::Forms::Label());
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
			// phoneLabel
			// 
			this->phoneLabel->AutoSize = true;
			this->phoneLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->phoneLabel->Location = System::Drawing::Point(22, 122);
			this->phoneLabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->phoneLabel->Name = L"phoneLabel";
			this->phoneLabel->Size = System::Drawing::Size(152, 32);
			this->phoneLabel->TabIndex = 4;
			this->phoneLabel->Text = L"Phone";
			// 
			// phoneValue
			// 
			this->phoneValue->AutoSize = true;
			this->phoneValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->phoneValue->ForeColor = System::Drawing::Color::ForestGreen;
			this->phoneValue->Location = System::Drawing::Point(280, 121);
			this->phoneValue->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->phoneValue->Name = L"phoneValue";
			this->phoneValue->Size = System::Drawing::Size(0, 32);
			this->phoneValue->TabIndex = 5;
			// 
			// emailLabel
			// 
			this->emailLabel->AutoSize = true;
			this->emailLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->emailLabel->Location = System::Drawing::Point(22, 176);
			this->emailLabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->emailLabel->Name = L"emailLabel";
			this->emailLabel->Size = System::Drawing::Size(94, 32);
			this->emailLabel->TabIndex = 6;
			this->emailLabel->Text = L"Email";
			// 
			// emailValue
			// 
			this->emailValue->AutoSize = true;
			this->emailValue->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->emailValue->ForeColor = System::Drawing::Color::ForestGreen;
			this->emailValue->Location = System::Drawing::Point(281, 175);
			this->emailValue->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->emailValue->Name = L"emailValue";
			this->emailValue->Size = System::Drawing::Size(0, 32);
			this->emailValue->TabIndex = 7;
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
			// AdminProfileControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->HireDateValue);
			this->Controls->Add(this->HireDateLabel);
			this->Controls->Add(this->emailValue);
			this->Controls->Add(this->emailLabel);
			this->Controls->Add(this->phoneValue);
			this->Controls->Add(this->phoneLabel);
			this->Controls->Add(this->CodeValue);
			this->Controls->Add(this->CodeLabel);
			this->Controls->Add(this->fullNameValue);
			this->Controls->Add(this->fullNameLabel);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->Name = L"AdminProfileControl";
			this->Size = System::Drawing::Size(982, 926);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}