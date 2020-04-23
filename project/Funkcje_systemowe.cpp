#include <windows.h>
#include <Lmcons.h> //Getusername((TCHAR*)username, &size)
#include <string>
#include <iostream>
#include <fstream>
#include "ConfigFile.h"
#include "Funkcje.h"

#ifdef roboczy
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Diagnostics; //
using namespace System::IO;
//Drag & Drop
using namespace System::Collections::Generic;
//using namespace System::Linq;
using namespace System::Text;
using namespace System::Threading::Tasks;
//MessageBox::Show("e: "+dd, "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
#endif

using namespace std;

#pragma comment( lib, "advapi32" )  
//Przyk³adowe funkcje zwracaj¹ce login username windows
std::wstring user_name_w()
{
	wchar_t buffer[UNLEN + 1]{};
	DWORD len = UNLEN + 1;
	if (::GetUserNameW(buffer, &len)) return buffer;
	else return {}; // or: return L"" ;
}

std::string user_name()
{
	char buffer[UNLEN + 1]{};
	DWORD len = UNLEN + 1;
	if (::GetUserNameA(buffer, &len)) return buffer;
	else return {}; // or: return "" ;

}

void main00()
{
	std::wcout << user_name_w() << L'\n';
	std::cout << user_name() << '\n';
}


//decapitation
/*
void fbom_settings_save(int a)
{
	
	//MessageBox::Show("zapisuje...", "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	string deleteline,temp_line;
	string line;

	temp_line = deleteline = fbom_settings_load(user_name(), 0);
	if (deleteline[a] == '0')
		deleteline[a] = '1';
	else
		deleteline[a] = '0';

	ifstream settings_file;
	settings_file.open("settings.ini");
	ofstream temp;
	temp.open("temp.ini");

	while (!settings_file.eof())
	{
		getline(settings_file, line);
		{
			if (line == temp_line)
				//line.replace(line.find(deleteline), deleteline.length(), "Dupaa"); //dziwne ze to nie dziala (wykrzacza sie na tej linii, chyba ze string jest pusty to wtedy ok)
				temp << deleteline << endl;
			else
			temp << line << endl;
		}
	}

	char oldname[] = "temp.ini";
	char newname[] = "settings.ini";

	temp.close();
	settings_file.close();
	remove("settings.ini");
	if (rename(oldname, newname) != 0)
		perror("Error renaming file");
	else
		cout << "File renamed successfully";
	

}
*/

//decapitation
/*
string fbom_settings_load(string username, bool tab) 
{
	//funkcja zwraca liniê dla aktywnego u¿ytkownika
	//inaczej zwraca ci¹g zer (defaultowe ustawienia)
	string linia, settings;
	string login = "dupa";

	fstream settings_file;
	string settings_name = "settings.ini";
	settings_file.open(settings_name, ios::in);

	while (!settings_file.eof())
	{
		login.clear();
		bool flag = false;
		int j=0;
		getline(settings_file, linia);
		for (int i = 0; i < linia.size(); i++)
		{
			if (flag == true)
			{
				login += linia[i];
				if (login == username)
				{
					//String^ str2 = gcnew String(linia.c_str());
						//MessageBox::Show(str2, "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					settings_file.close();
					return linia;

					break;
				}
				j++;
			}
			if (linia[i] == '-')
			{
				flag = true;
			}
		}

	}
	settings_file.close();
	return "01000000000000000000";
	//return login;
}

bool fbom_settings_view(int a)
{
	string temp = fbom_settings_load(user_name(), 0);
	if (temp[a] == '1')
		return true;
	else
		return false;
}
*/
#ifdef roboczy
string sprawdzenie(string a)
{
	String^ user_login = gcnew String(a.c_str());
	MessageBox::Show(user_login, "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	return a;
}

#endif