#pragma once

namespace UniversityProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainStudentForm
	/// </summary>
	public ref class StudentMainForm : public System::Windows::Forms::Form
	{
	public:
		StudentMainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StudentMainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Button^ btnLogout;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe Script", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(421, 67);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome, Student";
			// 
			// btnLogout
			// 
			this->btnLogout->BackColor = System::Drawing::Color::Red;
			this->btnLogout->ForeColor = System::Drawing::Color::White;
			this->btnLogout->Location = System::Drawing::Point(670, 9);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(100, 40);
			this->btnLogout->TabIndex = 1;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->UseVisualStyleBackColor = false;
			this->btnLogout->Click += gcnew System::EventHandler(this, &StudentMainForm::btnLogout_Click);
			// 
			// StudentMainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(782, 553);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->label1);
			this->Name = L"StudentMainForm";
			this->Text = L"MainStudentForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {
			//    // Hide main window
			//    this->Hide();
			//    // Show login form
			//    Login^ login = gcnew Login();
			//    login->ShowDialog();
			//    // Close main form after login form ends
			//	this->Close();
			Application::Restart();
		}
	};
}
