// Wrobel Ireneusz, Informatyka, grupa 2I5 
// Program interaktywny demonstrujacy mozliwosci klasy Liczba

#include <iostream>
#include <limits>
#include "Liczba.h"

using namespace std;

extern const int PRECYZJA; //stala okreslajaca liczbe cyfr po przecinku
extern const int POT_10_PRECYZJA; // 10 podniesione do potegi PRECYZJA

bool menu = true;
Liczba pobranieLiczby( bool czyPierwszaLiczba ); //funkcja odpowiadajaca za wczytanie od uzytkownika liczby

int main() {
	int wybor;
	Liczba liczba1;
	Liczba liczba2;
	Liczba wynik;

	while( menu ) {
		wybor = 0;

		cout << "=======================================================" << endl;
		cout << "Jaka operacje chcesz wykonac? Wcisnij odpowiedni numer." << endl;
		cout << "1. Dodac liczby" << endl;
		cout << "2. Odjac liczby" << endl;
		cout << "3. Pomnozyc liczby" << endl;
		cout << "4. Podzielic liczby" << endl;
		cout << "5. Porownac liczby" << endl;
		cout << "9. Wyjsc z programu" << endl;
		cout << "=======================================================" << endl;

		cin >> wybor;

		if( wybor == 9 )
			menu=false;
		if( wybor <= 5 && wybor >= 1) {
			cout << "Aby uzyskac liczbe na przyklad 2.5 nalezy w czesci ulamkowej wprowadzic liczbe 5000." << endl;
			cout << "Aby uzyskac liczbe ujemna nalezy podac ujemna czesc calkowita lub ulamkowa." << endl << endl; 
			liczba1 = pobranieLiczby( true );
			liczba2 = pobranieLiczby( false );
			cout << endl;
		}

		for( int i = 0; i < 60; ++i )
			cout << endl; //czyszczenie ekranu

		switch( wybor ) {
			case 1: 
				wynik = liczba1 + liczba2;
				cout << "Wynik: "; wynik.wyswietlLiczbe(); cout << endl; 
				break; 
			
			case 2: 
				wynik = liczba1 - liczba2;
				cout << "Wynik: "; wynik.wyswietlLiczbe(); cout << endl; 
				break; 
			case 3:  
				wynik = liczba1 * liczba2;
				cout << "Wynik: "; wynik.wyswietlLiczbe(); cout << endl; 
				break; 
			case 4:  
				if( liczba2 == 0.0 ) {
					cout<< "Dzielenie przez zero jest niedozwolone!" << endl;
					break;
				}
				wynik = liczba1 / liczba2;
				cout << "Wynik: "; wynik.wyswietlLiczbe(); cout << endl; 
				break; 
			case 5: 
				liczba1.wyswietlLiczbe(); 

				if( liczba1 > liczba2 ) 
					cout << " > "; 
				else if( liczba1 == liczba2 ) 	
					cout << " == "; 
				else
					cout << " < "; 

				liczba2.wyswietlLiczbe();
				cout << endl;
				break;	
			case 9:  
				break; 
			default:  
				cout << "Musisz podac numer odpowiadajacy danemu dzialaniu!" << endl; 
		}
	}	
}//main

Liczba pobranieLiczby( bool czyPierwszaLiczba ) {
	int cecha = 0;
	int mantysa = 0;

	if( czyPierwszaLiczba )
		cout << "Wprowadz czesc calkowita pierwszej liczby" << endl;
	else //pobieranie drugiej liczby
		cout << "Wprowadz czesc calkowita drugiej liczby" << endl;

	cin >> cecha;
	while( cin.fail() ) { //sprawdzanie poprawnosci wprowadzonej wartosci
		cin.clear(); //czyszczenie flagi bledu
		cin.ignore( numeric_limits<streamsize>::max(),'\n' ); //czyszczenie bufora
		cout << "Musisz wprowadzic liczbe!" << endl;
		cout << "Wprowadz liczbe jeszcze raz: ";
		cin >> cecha;
	}

	if( czyPierwszaLiczba )
		cout << "Wprowadz czesc ulamkowa pierwszej liczby" << endl;
	else //pobieranie drugiej liczby
		cout << "Wprowadz czesc ulamkowa drugiej liczby" << endl;

	cin >> mantysa;
    	while( cin.fail() ) { //sprawdzanie poprawnosci wprowadzonej wartosci
		cin.clear(); //czyszczenie flagi bledu
		cin.ignore( numeric_limits<streamsize>::max(),'\n'); //czyszczenie bufora
		cout << "Musisz wprowadzic liczbe!" << endl;
		cout << "Wprowadz liczbe jeszcze raz: ";
		cin >> mantysa;
    	}

	if( cecha < 0 && mantysa > 0) //jezeli czesc calkowita jest ujemna a ulamkowa dodatnia
    		mantysa = -mantysa; //minus jest przechowywany w czesci calkowitej i ulamkowej
    	else if( cecha > 0 && mantysa < 0) //jezeli czesc calkowita jest dodatnia a ulamkowa ujemna
    		cecha = -cecha; //minus jest przechowywany w czesci calkowitej i ulamkowej

    	while( mantysa >= POT_10_PRECYZJA || mantysa <= -POT_10_PRECYZJA ) 
    		mantysa /= 10; //jezeli czesc calkowita wychodzi poza zakres PRECYZJI ucinanie mniej znaczacych cyfr

	return Liczba(cecha,mantysa);
}//pobranieLiczby
