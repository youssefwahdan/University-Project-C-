
#using <System.Configuration.dll>
#include "AdminProfileControl.h"
#include "FeeControl.h"
#include "StudentControl.h"
#pragma once
using namespace System::Windows::Forms;
using namespace System::Configuration;
namespace UniversityProject {
    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(int id)
        {
            InitializeComponent();
            db = gcnew Database(GetConnectionString());
            adminID = id;
            LoadAdminData(id);
        }

    protected:
        ~MainForm()
        {
            if (components)
                delete components;
        }

    private:
        Database^ db;
        System::Windows::Forms::Button^ btnProfile;
        System::Windows::Forms::Button^ btnFees;
        System::Windows::Forms::Button^ btnStudents;
        System::Windows::Forms::Label^ welcomeLabel;
        System::Windows::Forms::Button^ btnLogout;
    private: System::Windows::Forms::Panel^ sidebarPanel;
    private: System::Windows::Forms::Panel^ sectionsPanel;
    private: System::Windows::Forms::Panel^ navbar;
		   int adminID;
           System::ComponentModel::IContainer^ components;
		   String^ FirstName;
		   String^ LastName;
           String^ Code;
           String^ Email;
           String^ Phone;
		   DateTime HireDate;



        void InitializeComponent()
        {
            this->btnProfile = (gcnew System::Windows::Forms::Button());
            this->btnFees = (gcnew System::Windows::Forms::Button());
            this->btnStudents = (gcnew System::Windows::Forms::Button());
            this->welcomeLabel = (gcnew System::Windows::Forms::Label());
            this->btnLogout = (gcnew System::Windows::Forms::Button());
            this->sidebarPanel = (gcnew System::Windows::Forms::Panel());
            this->sectionsPanel = (gcnew System::Windows::Forms::Panel());
            this->navbar = (gcnew System::Windows::Forms::Panel());
            this->sidebarPanel->SuspendLayout();
            this->navbar->SuspendLayout();
            this->SuspendLayout();
            // 
            // btnProfile
            // 
            this->btnProfile->BackColor = System::Drawing::Color::OliveDrab;
            this->btnProfile->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnProfile->Dock = System::Windows::Forms::DockStyle::Top;
            this->btnProfile->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnProfile->Location = System::Drawing::Point(10, 20);
            this->btnProfile->Name = L"btnProfile";
            this->btnProfile->Size = System::Drawing::Size(180, 50);
            this->btnProfile->TabIndex = 1;
            this->btnProfile->Text = L"Profile";
            this->btnProfile->UseVisualStyleBackColor = false;
            this->btnProfile->Click += gcnew System::EventHandler(this, &MainForm::btnProfile_Click);
            // 
            // btnFees
            // 
            this->btnFees->BackColor = System::Drawing::Color::DarkSlateGray;
            this->btnFees->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnFees->Dock = System::Windows::Forms::DockStyle::Top;
            this->btnFees->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnFees->Location = System::Drawing::Point(10, 120);
            this->btnFees->Name = L"btnFees";
            this->btnFees->Size = System::Drawing::Size(180, 50);
            this->btnFees->TabIndex = 2;
            this->btnFees->Text = L"Fees";
            this->btnFees->UseVisualStyleBackColor = false;
            this->btnFees->Click += gcnew System::EventHandler(this, &MainForm::btnFees_Click);
            // 
            // btnStudents
            // 
            this->btnStudents->BackColor = System::Drawing::Color::Orange;
            this->btnStudents->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnStudents->Dock = System::Windows::Forms::DockStyle::Top;
            this->btnStudents->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnStudents->Location = System::Drawing::Point(10, 70);
            this->btnStudents->Name = L"btnStudents";
            this->btnStudents->Size = System::Drawing::Size(180, 50);
            this->btnStudents->TabIndex = 0;
            this->btnStudents->Text = L"Students";
            this->btnStudents->UseVisualStyleBackColor = false;
            this->btnStudents->Click += gcnew System::EventHandler(this, &MainForm::btnStudents_Click);
            // 
            // welcomeLabel
            // 
            this->welcomeLabel->AutoSize = true;
            this->welcomeLabel->BackColor = System::Drawing::Color::Transparent;
            this->welcomeLabel->Dock = System::Windows::Forms::DockStyle::Left;
            this->welcomeLabel->Font = (gcnew System::Drawing::Font(L"Segoe Script", 12, System::Drawing::FontStyle::Bold));
            this->welcomeLabel->ForeColor = System::Drawing::Color::Black;
            this->welcomeLabel->Location = System::Drawing::Point(0, 0);
            this->welcomeLabel->Name = L"welcomeLabel";
            this->welcomeLabel->Size = System::Drawing::Size(0, 33);
            this->welcomeLabel->TabIndex = 3;
            // 
            // btnLogout
            // 
            this->btnLogout->BackColor = System::Drawing::Color::Red;
            this->btnLogout->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnLogout->Dock = System::Windows::Forms::DockStyle::Right;
            this->btnLogout->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnLogout->Location = System::Drawing::Point(643, 0);
            this->btnLogout->Name = L"btnLogout";
            this->btnLogout->Size = System::Drawing::Size(75, 40);
            this->btnLogout->TabIndex = 4;
            this->btnLogout->Text = L"Logout";
            this->btnLogout->UseVisualStyleBackColor = false;
            this->btnLogout->Click += gcnew System::EventHandler(this, &MainForm::btnLogout_Click);
            // 
            // sidebarPanel
            // 
            this->sidebarPanel->BackColor = System::Drawing::Color::DarkGray;
            this->sidebarPanel->Controls->Add(this->btnFees);
            this->sidebarPanel->Controls->Add(this->btnStudents);
            this->sidebarPanel->Controls->Add(this->btnProfile);
            this->sidebarPanel->Dock = System::Windows::Forms::DockStyle::Left;
            this->sidebarPanel->Location = System::Drawing::Point(0, 0);
            this->sidebarPanel->Name = L"sidebarPanel";
            this->sidebarPanel->Padding = System::Windows::Forms::Padding(10, 20, 10, 0);
            this->sidebarPanel->Size = System::Drawing::Size(200, 561);
            this->sidebarPanel->TabIndex = 5;
            // 
            // sectionsPanel
            // 
            this->sectionsPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->sectionsPanel->ForeColor = System::Drawing::Color::Black;
            this->sectionsPanel->Location = System::Drawing::Point(200, 40);
            this->sectionsPanel->Name = L"sectionsPanel";
            this->sectionsPanel->Size = System::Drawing::Size(718, 521);
            this->sectionsPanel->TabIndex = 6;
            // 
            // navbar
            // 
            this->navbar->Controls->Add(this->btnLogout);
            this->navbar->Controls->Add(this->welcomeLabel);
            this->navbar->Dock = System::Windows::Forms::DockStyle::Top;
            this->navbar->Location = System::Drawing::Point(200, 0);
            this->navbar->Name = L"navbar";
            this->navbar->Size = System::Drawing::Size(718, 40);
            this->navbar->TabIndex = 6;
            // 
            // MainForm
            // 
            this->ClientSize = System::Drawing::Size(918, 561);
            this->Controls->Add(this->sectionsPanel);
            this->Controls->Add(this->navbar);
            this->Controls->Add(this->sidebarPanel);
            this->ForeColor = System::Drawing::Color::WhiteSmoke;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
            this->Name = L"MainForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->sidebarPanel->ResumeLayout(false);
            this->navbar->ResumeLayout(false);
            this->navbar->PerformLayout();
            this->ResumeLayout(false);

        }
        void LoadAdminData(int id)
        {
            SqlConnection^ conn = gcnew SqlConnection(db->connectionString);

            try {
                SqlCommand^ command = gcnew SqlCommand("SELECT * FROM Admin WHERE AdminID = @id", conn);
                command->Parameters->AddWithValue("@id", id);
				conn->Open();
                SqlDataReader^ reader = command->ExecuteReader();
                if (reader->Read()) {
                    FirstName = reader["FirstName"]->ToString();
                    LastName = reader["LastName"]->ToString();
					Code = reader["Code"]->ToString();
					Email = reader["Email"]->ToString();
					Phone = reader["Phone"]->ToString();
					HireDate = DateTime::Parse(reader["HireDate"]->ToString());
                    welcomeLabel->Text = "Welcome, " + FirstName + " " + LastName;
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error loading admin data: " + ex->Message);
            }
            finally {
                conn->Close();
            }
		}
        void btnStudents_Click(System::Object^ sender, System::EventArgs^ e)
        {
			sectionsPanel->Controls->Clear();
            StudentControl^ form = gcnew StudentControl();
			form->Dock = DockStyle::Fill;
			sectionsPanel->Controls->Add(form);
        }

        void btnProfile_Click(System::Object^ sender, System::EventArgs^ e)
        {
        
            sectionsPanel->Controls->Clear();
            AdminProfileControl^ form = gcnew AdminProfileControl(FirstName,LastName, Code,Phone,Email,HireDate);
            form->Dock = DockStyle::Fill;
            sectionsPanel->Controls->Add(form);
        }

        void btnFees_Click(System::Object^ sender, System::EventArgs^ e)
        {
            sectionsPanel->Controls->Clear();
            FeeControl^ form = gcnew FeeControl();
            form->Dock = DockStyle::Fill;
            sectionsPanel->Controls->Add(form);
        }
        String^ GetConnectionString()
        {
            // Use System::Configuration::ConfigurationManager to access connection strings
            return System::Configuration::ConfigurationManager::ConnectionStrings["UniversityDb"]->ConnectionString;
        }

        System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {

	        Application::Restart();
        }

};
}