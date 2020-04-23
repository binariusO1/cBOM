#include "Main_menu.h"
#include <windows.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

[STAThread]//leave this as is
int main()  //void [nazwa funkcji z properties/linker/advanced/entry point]
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	cBOM::Main_menu form; //nazwa projektu oraz formy.cpp
	Application::Run(% form);


}