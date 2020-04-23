#include <iostream>
#include <fstream>
#include <string>
#include "Funkcje.h"
#include <windows.h>
#include "ConfigFile.h"

using namespace std;

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
#endif

string fbom_szyfruj(string sciezka);

//static int liczba_wierszy;

//let it live
int fbom_sprawdzenie(string sciezka)
{
	string linia;
	fstream plik;

	string rozszerzenie;
	for (int i = sciezka.size() - 1; i >= sciezka.size() - 3; i--)
	{
		rozszerzenie += sciezka[i];
	}
#ifdef roboczy
	sprawdzenie(rozszerzenie);
#endif
	plik.open(sciezka, ios::in);
	if (plik.good() == false) 
	{
		cout << "Nie mozna otworzyc pliku!";
		plik.close();
		return 0;
	}
	else if (rozszerzenie != "txt")
	{
		cout << "Plik z³o¿enia materia³owego nie jest plikiem tekstowym o rozszerzeniu .txt";
		rozszerzenie.clear();
		plik.close();
		return -1;
	}
	else
	{
		int liczba_wierszy = 0;
		while (!plik.eof())
		{
			/*
			if (liczba_wierszy == 0)
			{
				while (getline(plik, linia))
				{

				}
			}
			*/
			getline(plik, linia);
			liczba_wierszy++;
		}
			plik.close();
	return liczba_wierszy;

	}
}

//-----------------------------------------------------------------------
//		FUNCKJA ANALIZA (FUNKCJA BOM)
//-----------------------------------------------------------------------
//let it live
void analiza(string plik_bom, string sciezka)
{
	int c = 0, w = 0;

	ofstream log;
	string log_file = sciezka + "\\" + "log.txt";
	//ofstream file_log(log_file); //open in constructor
	log.open(log_file, ios::out);

	//unsigned char bom[] = { 0xEF,0xBB,0xBF };
	//log.write((char*)bom, sizeof(bom));

	//log << utf8;

	fstream plik;
	//ofstream file(plik_bom); //open in constructor
	plik.open(plik_bom, ios::in);

	//Zdefiniowanie 30-elementowej tablicy string (dla przechowywania sk³adników tabeli)
	string tab[30];
	string naglowek[30];
	string linia;
	int wiersz = 1;

	while (!plik.eof())
	{
		getline(plik, linia);
		int kolumna = 1;

		for (int i = 0; i < linia.size(); i++)
		{

			if (linia[i] == 9)
				kolumna++;
			else
			{
				tab[kolumna] += linia[i];
				if (wiersz == 1)
					naglowek[kolumna] += linia[i];
			}
		}
		if (linia == "")
			break;
		//******************************
		//				FUNKCJE
		//******************************
		if (wiersz > 1)
		{
			if (fa_grubosc_plyty(tab[2], tab[6], wiersz) != "x")
				log << fa_grubosc_plyty(tab[2], tab[6], wiersz) << endl;
			if (fa_puste_pola(tab, naglowek, wiersz, kolumna) != "x")
				log << fa_puste_pola(tab, naglowek, wiersz, kolumna) << endl;
			if (fa_dlugosc_plyty(tab[2],tab[4], tab[5], wiersz) != "x")
				log << fa_dlugosc_plyty(tab[2],tab[4], tab[5], wiersz) << endl;
			if(cffile::ReadParam(1)==true)
			fa_powiadomienie_plyty_okleiny(tab[2], 1, 0);
		}
		for (int j = 0; j < 20; j++)
			tab[j].clear();
		wiersz++;

	}
	if (cffile::ReadParam(1) == true)
	{
		log << fa_powiadomienie_plyty_okleiny(tab[2], 0, 1) << endl;
		log << fa_powiadomienie_plyty_okleiny(tab[2], 0, 0) << endl;
	}
	//log << "Wierszy: "<< wiersz << endl;
	//log << "Kolumn: " << kolumna << endl;
	//string data("x\n");
	//file << data;

	//Niezbêdne zamkniêcie plików

	plik.close();
	log.close();
}

//let it live
void fbom_dopisz_sciezke(string plik_bom, string sciezka)
{
	//sprawdzenie czy istnieje ju¿ dodana œcie¿ka
	bool b_path = false;
	string line;
	fstream file;
	file.open(plik_bom, ios::in);
	while (!file.eof())
	{
		getline(file, line);
		{;
			if (line[1]==':' && line[2] =='\\')
				b_path = true;
		}
	}
	file.close();
	if (b_path == false)
	{
		ofstream plik2(plik_bom, std::ios_base::app | std::ios_base::out);
		string path_file = sciezka;
		//=======================
		//		SZYFROWANIE 
		//=======================
		//cffile* user = new cffile(user_name(), 0);
		if (cffile::ReadParam(6))
			path_file = fbom_szyfruj(path_file);

		plik2 << "\n";
		plik2 << "\n";
		plik2 << path_file;

		plik2.close();
	}
}

//let it live
void fbom_usun_plik(string sciezka)
{
	string plik_do_usuniecia = sciezka + "\\" + "log.txt";
	const char* c_plik_do_usuniecia = plik_do_usuniecia.c_str();
	//remove(c_plik_do_usuniecia);
	if (remove(c_plik_do_usuniecia) != 0)
	{
#ifdef roboczy
		//perror("Error deleting file");
	MessageBox::Show("Error deleting file", "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
#endif
	}
	else
	{
#ifdef roboczy
		//puts("File successfully deleted");	
	MessageBox::Show("File successfully deleted", "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
#endif
	}
}

//let it live
void fbom_dodaj_sciezke(string sciezka)
{
	ofstream path;
	string path_file = sciezka + "\\" + "~temp.log";
	path.open(path_file, ios::out);
	path_file = sciezka;
	//=======================
	//		SZYFROWANIE 
	//=======================
	//cffile* user = new cffile(user_name(), 0);
	if(cffile::ReadParam(6))
	path_file = fbom_szyfruj(sciezka);
	 
	path << path_file << endl;
	path.close();
	//delete user;
}

//let it live
string fbom_szyfruj(string sciezka)
{
	int h = 1;
	string szyfr;
	for (int i = 0; i < sciezka.size(); i++)
	{
		sciezka[i] = sciezka[i] - h;
		//szyfr[i] = temp;
		h++;
		if (h > 10)
			h = 1;
	}
	szyfr = sciezka;
	return szyfr;
}