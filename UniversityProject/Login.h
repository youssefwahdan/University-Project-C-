#include "MainForm.h"
#include "StudentMainForm.h"
#using <System.Configuration.dll>

#pragma once
namespace UniversityProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;
	using namespace System::Configuration;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
			db = gcnew Database(GetConnectionString());

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::TextBox^ username;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::TextBox^ password;
		System::Windows::Forms::Button^ button1;
		Database^ db;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->username = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MV Boli", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(138, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(304, 105);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Sign in";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// username
			// 
			this->username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->username->Location = System::Drawing::Point(156, 189);
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(260, 30);
			this->username->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(151, 161);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Username";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(151, 237);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 25);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Password";
			// 
			// password
			// 
			this->password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->password->Location = System::Drawing::Point(156, 265);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(260, 30);
			this->password->TabIndex = 3;
			this->password->UseSystemPasswordChar = true;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkOrange;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(226, 320);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 40);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Log in";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Login::button1_Click);
			// 
			// Login
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(582, 453);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->password);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->username);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &Login::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ user = this->username->Text;
		String^ pass = this->password->Text;
		SqlConnection^ conn = gcnew SqlConnection(GetConnectionString());
		try {
			conn->Open(); // Must open before using


		String^ query = "SELECT Role, StudentID, ProfessorID FROM Users WHERE Username=@u AND Password=@p";
		SqlCommand^ cmd = gcnew SqlCommand(query, conn);
		cmd->Parameters->AddWithValue("@u", user);
		cmd->Parameters->AddWithValue("@p", pass);

		SqlDataReader^ reader = cmd->ExecuteReader();
		if (reader->Read()) {
			String^ role = reader["Role"]->ToString();
			if (role == "Student") {
				int studentId = Convert::ToInt32(reader["StudentID"]);
			// Hide login window
			this->Hide();

			StudentMainForm^ student = gcnew StudentMainForm(studentId);
			// Show student main form
			student->ShowDialog();

			// Close login after main form ends
			this->Close();
			}
			else if (role == "Professor") {
				int professorId = Convert::ToInt32(reader["ProfessorID"]);
				// Load professor dashboard
			}
			else {
				this->Hide();
				int adminId = Convert::ToInt32(reader["ProfessorID"]);
				// Show main form
				MainForm^ main = gcnew MainForm(adminId);
				main->ShowDialog();
			}
		}
		else {
			System::Windows::Forms::MessageBox::Show("Invalid login");
		}

		reader->Close();
		conn->Close(); // Always close after use
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message);
	}
	}
	System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		label1->Left = (this->ClientSize.Width - label1->Width) / 2;
		label2->Left = (this->ClientSize.Width - username->Width) / 2;
		username->Left = (this->ClientSize.Width - username->Width) / 2;
		label3->Left = (this->ClientSize.Width - password->Width) / 2;
		password->Left = (this->ClientSize.Width - password->Width) / 2;
		button1->Left = (this->ClientSize.Width - button1->Width) / 2;
	}
	System::String^ GetConnectionString()
	{
		// System::Configuration::ConfigurationManager is in System.Configuration.dll
		return System::Configuration::ConfigurationManager::ConnectionStrings["UniversityDb"]->ConnectionString;
	}
};

}
