#include "ConfigFile.h"
#include <fstream>

//#include <iostream>

#ifdef roboczy
#include "Funkcje.h"
#include <windows.h>
#include <Lmcons.h> //Getusername((TCHAR*)username, &size)
#include <string>
#include <iostream>
#include "Funkcje.h"
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

//definicja zmiennych static
int cffile::ile_skladnikow = 0;
bool cffile::tab[20] = {};
string cffile::cf_apppath = "";

// odczyt pliku dla danego uzytkownika
void cffile::LoadConfigFile(string username)
{
	//check if it live
	fstream file;
	string apppath = cf_apppath + "config.ini";
	file.open(apppath, ios::in);
	if (file.good() == false)
	{
		ofstream newsettings;
		string newfile = apppath;
		newsettings.open(newfile, ios::out);
		newsettings.close();
	}
	file.close();

	string linia, login, param;
	fstream settings_ini;
	string settings_ini_name = apppath;
	settings_ini.open(settings_ini_name, ios::in);

	bool b_login = false;
	while (!settings_ini.eof())
	{
		getline(settings_ini, linia);
		for (int i = 0; i < linia.size(); i++)
		{
			if (b_login == true)
				param += linia[i];
			if (linia[i] == 9 && linia[i+1]!=9)
			{
				if (login == username)
					b_login = true;
				else
					break;
			}
			login += linia[i];

		}
		if (b_login == true)
			break;
		login.clear();
	}
	settings_ini.close();
	if (b_login == false)
	{
		//ADD NEW USER WITH PARAMS
		//CALLING FOR ANOTHER FUNCTION
		CreateUser(username);
	}
	if (b_login == true)
	{
		for (int i = 0; i<param.size(); i++)
		{
			if (param[i] == '1')
				cffile::tab[i] = true;
			else
				cffile::tab[i] = false;
		}
	}
	//String^ str2 = gcnew String(param.c_str());
	//MessageBox::Show(str2 + " : ", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

// zapisanie pliku z ustawieniami dla danego u¿ytkownika
void cffile::SaveConfigFile(string username)
{
	bool b_login = false;
	string line, temp_line, login,param,delete_line;
	for (int i = 0; i < 20; i++)
	{
		if (tab[i] == true)
			param += '1';
		else
			param += '0';
	}
	ifstream settings_ini;
	string apppath = cf_apppath + "config.ini";
	settings_ini.open(apppath);
	ofstream temp;
	string temp_path = cf_apppath + "temp.ini";
	temp.open(temp_path);

	while (!settings_ini.eof())
	{
		getline(settings_ini, line);
		for (int i = 0; i < line.size(); i++)
		{

			if (line[i] == 9 && line[i + 1] != 9)
			{
				if (login == username)
				{
					b_login = true;
					temp_line = login + '\t' + param;
					//delete_line = line;
				}
				else
					break;
			}
			login += line[i];
		}

		if (b_login == true)
		{
			temp << temp_line << endl;
			break;
		}
		temp << line << endl;
		login.clear();
	}
	/*
	while (!settings_ini.eof())
	{
		getline(settings_ini, line);
		if (line == temp_line)
			//line.replace(line.find(deleteline), deleteline.length(), "Dupaa"); //dziwne ze to nie dziala (wykrzacza sie na tej linii, chyba ze string jest pusty to wtedy ok)
			temp << deleteline << endl;
		else
			temp << line << endl;
	}
	*/

	//char oldname[] = "temp.ini";
	//char newname[] = "config.ini";

	char oldname[] = "temp.ini";
	char newname[] = "config.ini";

	temp.close();
	settings_ini.close();
	remove(apppath.c_str());
	if (rename(oldname, newname) != 0)
		perror("Error renaming file");
	else
		perror("File renamed successfully");
	
}

//Tworzenie w pliku wpisu z nowym u¿ytkownikiem
void cffile::CreateUser(string username)
{
	bool f = false;
	fstream file;
	string apppath = cf_apppath + "config.ini";
	file.open(apppath, ios::in);
	if (file.good() == true)
		f = true;
	file.close();
	string linia, login, param;
	ofstream settings_ini(apppath, std::ios_base::app | std::ios_base::out);
	//settings_ini.open("settings.ini");
	//settings_ini.open(settings_ini_name, ios::in);
	if(f==false)
	settings_ini << '\n';

	string zera(20, '0');
	settings_ini << username << '\t' << zera;
	settings_ini.close();
}

//Przechowywanie œcie¿ki do rozszerzenia .exe
void cffile::ApplicationExePath(string apppath)
{
	cf_apppath = apppath;
}

//zapisywanie parametru w tab[20]
void cffile::ChangeParam(int number, bool value){
	tab[number] = value;
	}
bool cffile::ReadParam(int number) {
	return tab[number];
}

// KONSTRUKTORY
// a tutaj mamy definicjê konstruktora

cffile::cffile(string username, int number)
{
	cf_username = username;
	cf_param_number = number;
}