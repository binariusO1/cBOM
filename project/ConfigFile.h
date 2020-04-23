#pragma once
#ifndef CONFIGFILE_H_
#define CONFIGFILE_H_

#include <string>
using namespace std;

//#include "Chameleon.h"

class cffile {


public:
	static bool tab[20];

	//sk³adniki klasy:
	//funkcje sk³adowe - s¹ w pamiêci tylko jednokrotnie (np. jedna dla kilku obiektów). Maj¹ zakres klasy w której pracuj¹.
	// void fun(int zmienna); //sk³adnik funkcji znany jest w ca³ej definicji klasy

	//dane sk³adowe
	// int skladowa;

	//konstruktory:

	//tylko deklaracja konstruktora:
	//	nazwa uzytkownika	|	numer w pliku ini	|	wartosc parametru
	cffile(string username, int number);

	//destruktor - deklaracja
	~cffile(void) {} 

	static void SaveConfigFile(string username);//, string apppath);
	void LoadConfigFile(string username); // , string apppath); //nie mo¿e byæ static, poniewa¿ wo³a w swoim ciele non-static funkcje a to jest illegal
	static void ChangeParam(int number, bool value);
	static bool ReadParam(int number);
	static void ApplicationExePath(string apppath);

private:
	string cf_username;
	static string cf_apppath;
	int cf_param_number;
	bool wartosc;
	static int ile_skladnikow;
	
	void CreateUser(string username);

};

#endif

//klasa nie ma w przeciwieñstwie do funkcji pocz¹tku ani koñca, to jakby pud³o na sk³adniki
//op³aca siê budowac klasy sk³adaj¹ce siê z innych obiektów
//klasa to typ obiektu a nie sam obiekt (klasa to jakby rysunek techniczny obiektu, nie zaœ sam obiekt)
// :: operator zakresu widocznoœci
// wskaŸnik t8

