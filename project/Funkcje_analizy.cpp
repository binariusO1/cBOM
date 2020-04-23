#include <iostream>
#include <string>
#include "Funkcje.h"
#include <sstream> 
#include <algorithm>

using namespace std;

string fa_grubosc_plyty(string s1, string s2, int w)
{
	//modyfikujemy tab oraz zakres fora
	string temp_w = to_string(w);
	string tab[5] = { "QL-","QB-","QM-","QH-","BE-LAM-HPL-" };
	int flag = 0;
	for (int i = 0; i < 5; i++)
	{
		if (s1.size() >= tab[i].size())
		{
			for (int j = 0; j < tab[i].size(); j++)
			{
				if (s1[j] == tab[i][j])
				{
					//cout<<tab[i][j];
					flag++;
				}
				else
				{
					flag = 0;
					break;
				}
			}
		}
		//cout << endl;
		if (flag == tab[i].size())
			break;
	}
	if (flag < 6 && flag > 0)
	{
		string temp;
		//cout << "Pracujemy..." << endl;
		int pauza = 0;
		for (int i = 0; i < s1.size(); i++)
		{

			if (pauza == 2 && s1[i-1] == '-')
			{
				if (s1[i] < 58 && s1[i]>47)
				{
					temp += s1[i];
					if (s1[i + 1] < 58 && s1[i + 1]>47)
						temp += s1[i + 1];
					if (temp != s2 && s1[1] != 'B')
						return "[Wiersz:] " + temp_w + " [Nieprawid³owa gruboœæ p³yty:] " + s1 + " [Gruboœæ:] " + s2 + "[mm]";
				}
			}
			if (pauza == 2 && s1[0] == 'Q' && s1[1] == 'B' && s1[i] == 'X')
			{
				if ((s1[i + 1] == '3' && s2 != "38") || (s1[i + 1] == '2' && s2 != "28"))
					return "[Wiersz:] " + temp_w + " [Nieprawid³owa gruboœæ blatu:] " + s1 + " [Gruboœæ:] " + s2 + "[mm]";
			}
			else if (pauza >= 3)
				break;

			if (s1[i] == '-')
				pauza++;
		}
	}
	else if (flag >= 6) //Szansa dla HPL-ÓW
		if (s2 != "1")
			return "[Wiersz:] " + temp_w + " [Nieprawid³owa gruboœæ materia³u:] " + s1 + " [Gruboœæ:] " + s2+ "[mm]";
		else
			return "x";
	return "x";
}

string fa_puste_pola(string *wsk1, string *wsk2,int  w,int k)
{
	string temp_w = to_string(w);
	for(int i=1;i<k;i++)//,wsk1++,wsk2++)
	{
		//okreœlenie kolumn, których nie chcemy aby by³y puste
		if(wsk1[i]=="" && (i==1 || i==2 || i==8))
		{
		string temp_i = to_string(i);
		//string temp_wsk2 = to_string(wsk2);
		return "[Wiersz:] " + temp_w + " [Kolumna:] " + temp_i + " [Brak pozycji w kolumnie:] " + wsk2[i];
		}
	}
	//zly magazyn
	if(wsk1[8]!="PROD" && wsk1[8] != "HALA" && wsk1[8] != "PR-2" && wsk1[8] != "DOBR")
		return "[Wiersz:] " + temp_w + " [Kolumna:] " + "8" + " [Nieprawid³owa nazwa magazynu:] " + wsk1[8];
	return "x";
}

string fa_dlugosc_plyty(string s3,string s1, string s2, int w)
{
	string temp_s(s3, 0,3);
	string temp_w = to_string(w);
	stringstream dlugosc(s1);
	stringstream szerokosc(s2);
	int dl = 0;
	int sz = 0;
	dlugosc >> dl;
	szerokosc >> sz;
	if(temp_s=="QL-" || temp_s=="QM-" || temp_s=="QH-")
	{
		if ((dl > 2780) || (sz > 2780))
			return "[Wiersz:] " + temp_w + " [D³ugoœæ formatki przekracza dozwolon¹ wartoœæ:] " + s1 + "[mm]" + "  ( " + s1 + "X" + s2 + "[mm] )";
		else if ((dl > 2050 && sz > 2050) )
			return "[Wiersz:] " + temp_w + " [Szerokoœæ formatki przekracza dozwolon¹ wartoœæ:] " + s2 + "[mm]" + "  ( " + s1 + "X" + s2 + "[mm] )";
		else
			return "x";
	}
	else if (temp_s == "QB-")
	{
		//wziêcie g³êbokoœci blatu
		string temp;
		int a;
		for (int i = 3; i < 9; i++)
		{
			if (s3[i] < 58 && s3[i]>47)
				temp = s3[i];
			if (s3[i] == 'X')
				break;
		}
		if (temp == "120")
			a = 1200;
		else
			a = 600;
		if ((dl > 4000) || (sz > 4000))
			return "[Wiersz:] " + temp_w + " [D³ugoœæ blatu przekracza dozwolon¹ wartoœæ:] " + s1 + "[mm]" + "  (" + s1 + "X" + s2 + "[mm])";
		else if ( ( dl > a && sz > a ) )
			return "[Wiersz:] " + temp_w + " [Szerokoœæ blatu przekracza dozwolon¹ wartoœæ:] " + s2 + "[mm]" + "  (" + s1 + "X" + s2 + "[mm])";
		else
			return "x";
	}
	else
		return "x";
}

string fa_powiadomienie_plyty_okleiny(string s1,bool f,bool t)
{
	//f:1 zapis, f:0 odczyt ; t:1 p³yty, t:0 okleiny
	static string plyty[20];
	static int p = 0;
	static string okleiny[20];
	static int o = 0;
	string temp_s(s1, 0, 2);
	if (f == true)
	{
		if (temp_s == "QL" || temp_s == "QM" || temp_s == "QH" || temp_s == "QB")
		{
			for (int i = 0; i < p + 1; i++)
			{
				if (s1 == plyty[i])
				{
					return "x";
				}
				if (i == p)
				{
					plyty[i] = s1;

				}
			}
			p++;
			return "x";
		}
		else if (temp_s == "Q-")
		{
			for (int i = 0; i < o + 1; i++)
			{
				if (s1 == okleiny[i])
				{
					return "x";
				}
				if (i == o)
				{
					okleiny[i] = s1;

				}
			}
			o++;
			return "x";
		}
		else
			return "x";
	}
	else if (f == false)
	{
		//sortowanie alfabetyczne tablic string
		{
			sort(plyty, plyty + p);
			sort(okleiny, okleiny + o);
		}
		string linia_p, linia_o;
		if (t == true)
		{
			linia_p += "<W z³o¿eniu u¿yto p³yt:>";
			string dod2(76, ' ');
			linia_p += dod2;
			for (int i = 0; i < p; i++)
			{
				linia_p += plyty[i];
				string dod((100 - plyty[i].size()), ' ');
				linia_p += dod;
			}
			// Czyszczenie tablic
			for (int j = 0; j < 20; j++)
				plyty[j].clear();
			p = 0;
			return linia_p;
		}
		else if (t == false)
		{
			linia_o += "<W z³o¿eniu u¿yto oklein:>";
			string dod2(74, ' ');
			linia_o += dod2;
			for (int i = 0; i < o; i++)
			{
				linia_o += okleiny[i];
				string dod((100 - okleiny[i].size()), ' ');
				linia_o += dod;
			}
			// Czyszczenie tablic
			for (int j = 0; j < 20; j++)
				okleiny[j].clear();
			o = 0;
			return linia_o;
		}
		else
			return "x";
	}
	else
		return "x";

}