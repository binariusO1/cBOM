#pragma once
using namespace std;

//Funkcje_plik.cpp
int fbom_sprawdzenie(string sciezka);

void analiza(string plik_bom,string sciezka);
void fbom_usun_plik(string sciezka);
void fbom_dodaj_sciezke(string sciezka);
void fbom_dopisz_sciezke(string plik_bom, string sciezka);

//Funkcje_analizy.cpp
string fa_grubosc_plyty(string s1, string s2, int w);
string fa_puste_pola(string *wsk1, string *ws2,int  w,int k);
string fa_dlugosc_plyty(string s3, string s1, string s2, int w);
string fa_powiadomienie_plyty_okleiny(string s1, bool f, bool t);

//System_funkcje.cpp
string user_name();


//************************************************************
//		FUNCJE POMOCNICZE
//************************************************************

//#define roboczy

#ifdef roboczy
std::string sprawdzenie(std::string a);
#endif

