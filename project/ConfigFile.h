#pragma once
#ifndef CONFIGFILE_H_
#define CONFIGFILE_H_

#include <string>
using namespace std;

//#include "Chameleon.h"

class cffile {


public:
	static bool tab[20];

	//sk�adniki klasy:
	//funkcje sk�adowe - s� w pami�ci tylko jednokrotnie (np. jedna dla kilku obiekt�w). Maj� zakres klasy w kt�rej pracuj�.
	// void fun(int zmienna); //sk�adnik funkcji znany jest w ca�ej definicji klasy

	//dane sk�adowe
	// int skladowa;

	//konstruktory:

	//tylko deklaracja konstruktora:
	//	nazwa uzytkownika	|	numer w pliku ini	|	wartosc parametru
	cffile(string username, int number);

	//destruktor - deklaracja
	~cffile(void) {} 

	static void SaveConfigFile(string username);//, string apppath);
	void LoadConfigFile(string username); // , string apppath); //nie mo�e by� static, poniewa� wo�a w swoim ciele non-static funkcje a to jest illegal
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

//klasa nie ma w przeciwie�stwie do funkcji pocz�tku ani ko�ca, to jakby pud�o na sk�adniki
//op�aca si� budowac klasy sk�adaj�ce si� z innych obiekt�w
//klasa to typ obiektu a nie sam obiekt (klasa to jakby rysunek techniczny obiektu, nie za� sam obiekt)
// :: operator zakresu widoczno�ci
// wska�nik t8

