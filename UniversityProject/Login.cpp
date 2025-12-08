#include "Login.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<System::String^>^ args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	// Create the main window and run it
	UniversityProject::Login loginWindow;
	Application::Run(% loginWindow);
}