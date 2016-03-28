#include <iostream>
#include <cmath>
#include <iomanip> //potrzebne przy wyswietlaniu Liczb
#include "Liczba.h"

const int PRECYZJA=4; //stala okreslajaca liczbe cyfr po przecinku
const int POT_10_PRECYZJA = pow(10, PRECYZJA); // 10 podniesione do potegi PRECYZJA

void inkrementacjaDekrementacjaCechy( bool, int &, int & );

Liczba::Liczba( int cecha, int mantysa ) {
	calkowita = cecha;
	ulamkowa = mantysa;
};//konstruktor

void Liczba::wyswietlLiczbe() {
	if( ulamkowa < 0 || calkowita < 0 ) { //liczba ujemna
		std::cout << "-" << -calkowita << '.' << std::setfill('0'); 
		std::cout << std::setw(PRECYZJA) << -ulamkowa;
	}
	else { //liczba dodatnia albo zero
		std::cout << calkowita << '.' << std::setfill('0'); 
		std::cout << std::setw(PRECYZJA) << ulamkowa;
	}	
};

void inkrementacjaDekrementacjaCechy(bool czyZwiekszycCeche, int &cecha, int &mantysa) {
	if(czyZwiekszycCeche) {
		mantysa -= POT_10_PRECYZJA;
		++cecha;
	}
	else {
		mantysa += POT_10_PRECYZJA;
		--cecha;
	}
}

// friend operatory

Liczba operator-( const Liczba& liczba ) {
	return Liczba( -(liczba.calkowita), -(liczba.ulamkowa) );
}//wyznacznie liczby przeciwnej

Liczba &Liczba::operator=( const Liczba& liczba ) {
	this->calkowita = liczba.calkowita;
	this->ulamkowa = liczba.ulamkowa;
}//operator przypisania

Liczba operator+( const Liczba& pierwsza, const Liczba& druga ) {
	int cecha = pierwsza.calkowita + druga.calkowita;
	int mantysa;
	mantysa = pierwsza.ulamkowa + druga.ulamkowa;

	if( pierwsza.calkowita < 0 || pierwsza.ulamkowa < 0 ) { //pierwsza liczba ujemna
		if( druga.calkowita < 0 || druga.ulamkowa < 0 ) { //druga liczba ujemna
			if( mantysa <= ( -POT_10_PRECYZJA ) )  //sprawdzanie czy potrzebne jest przeniesienie
				inkrementacjaDekrementacjaCechy( false, cecha, mantysa );
		}
		else { //druga liczba dodatnia albo zero
			if( mantysa < 0 && cecha > 0 )  //sprawdzanie czy cecha nie ma innego znaku niz mantysa
				inkrementacjaDekrementacjaCechy( false, cecha, mantysa );
			else if( mantysa >= 0 && cecha < 0 )  //sprawdzanie czy cecha nie ma innego znaku niz mantysa
				inkrementacjaDekrementacjaCechy( true, cecha, mantysa );	
		}
	}
	else  { //pierwsza liczba jest dodatnia albo zerem
		if( druga.calkowita < 0 || druga.ulamkowa < 0 ) { //druga liczba jest ujemna 
			if( mantysa < 0 && cecha > 0 )  //sprawdzanie czy cecha nie ma innego znaku niz mantysa
				inkrementacjaDekrementacjaCechy( false, cecha,  mantysa );
			else if( mantysa > 0 && cecha < 0 )  //sprawdzanie czy cecha nie ma innego znaku niz mantysa
				inkrementacjaDekrementacjaCechy( true,  cecha,  mantysa );	
		}
		else { //druga liczba jest dodatnia
			if( mantysa >= POT_10_PRECYZJA )  //sprawdzanie czy potrzebne jest przeniesienie
				inkrementacjaDekrementacjaCechy( true,  cecha,  mantysa );	
		}		
	}
	return Liczba( cecha, mantysa );
}

Liczba operator-( const Liczba& odjemna, const Liczba& odjemnik ) {
	Liczba przeciwnyOdjemnik = ( -odjemnik ); //wyznaczenie liczby przeciwnej do odjemnika aby skorzystać z operatora dodawania
	return odjemna + przeciwnyOdjemnik;
}

Liczba operator*( const Liczba& pierwsza, const Liczba& druga ) {
	int sumaPierwszej = pierwsza.calkowita * POT_10_PRECYZJA + pierwsza.ulamkowa; 
	int sumaDrugiej = druga.calkowita * POT_10_PRECYZJA + druga.ulamkowa; //zapisanie Liczby jako suma czesci calkowitej z odpowiednią waga i ulamkowej
	int iloczynSum = sumaPierwszej * sumaDrugiej; 
	int cecha = ( iloczynSum / POT_10_PRECYZJA ) / POT_10_PRECYZJA; //wyznaczenie cechy poprzez "skrocenie" iloczynu sum o 2*PRECYZJA cyfr
	int mantysa =  iloczynSum / POT_10_PRECYZJA; 
	mantysa %= POT_10_PRECYZJA; //mantysa jako modulo 10^PRECYZJA 
	return Liczba( cecha, mantysa );
}

Liczba operator/( const Liczba& pierwsza, const Liczba& druga ) {
	int sumaPierwszej = pierwsza.calkowita * POT_10_PRECYZJA + pierwsza.ulamkowa;
	int sumaDrugiej = druga.calkowita * POT_10_PRECYZJA + druga.ulamkowa; //zapisanie Liczby jako suma czesci calkowitej z odpowiednią waga i ulamkowej
	int cecha = sumaPierwszej / sumaDrugiej; //typ int, reszta zostanie ucieta
	int mantysaModulo= sumaPierwszej % sumaDrugiej; //"reszta" z dzielenie dwoch liczb
	int mantysa = ( mantysaModulo * POT_10_PRECYZJA ) / sumaDrugiej; //wyznaczenie jaka czescia liczby przez ktora dzielimy jest "reszta" z dzielenia 2 liczb
	return Liczba( cecha, mantysa );	
}

bool operator==( const Liczba& pierwsza, const Liczba& druga ) {
	if( pierwsza.calkowita == druga.calkowita && pierwsza.ulamkowa == druga.ulamkowa)
		return true;
	else
		return false;
}

bool operator>( const Liczba& pierwsza, const Liczba& druga ) {
	if( pierwsza.calkowita >= 0 && pierwsza.ulamkowa >= 0 ) { //pierwsza dodatnia albo zero
		if( druga.calkowita >= 0 && druga.ulamkowa >= 0 ) { //druga dodatnia albo zero
			if( pierwsza.calkowita >= druga.calkowita && pierwsza.ulamkowa > druga.ulamkowa )
				return true;
			else
				return false; 
		}
		else // pierwsza dodatnia albo zero, druga ujemna
			return true;
	}
	else { //pierwsza ujemna
		if( druga.calkowita < 0 || druga.ulamkowa < 0 ) { //druga ujemna
			if( pierwsza.calkowita >= druga.calkowita && pierwsza.ulamkowa > druga.ulamkowa )
				return true;
			else
				return false;
		}
		else //pierwsza ujemna, druga dodatnia
			return false;
	}
}

bool operator<( const Liczba& pierwsza, const Liczba& druga ) {
	if( druga > pierwsza )
		return true;
	else
		return false;
}
