#include "Ustawienia.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

[STAThread]//leave this as is
void main3()  //void [nazwa funkcji z properties/linker/advanced/entry point]
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	cBOM::Ustawienia form; //nazwa projektu oraz formy.cpp
	Application::Run(% form);

}

