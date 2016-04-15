// Wrobel Ireneusz, Informatyka, grupa 2I5 
// Operatory oraz funkcja wyswietlajaca klasy Liczba

#include <iostream>
#include <cmath>
#include <iomanip> //potrzebne przy wyswietlaniu Liczb
#include "Liczba.h"

const int PRECYZJA = 4; //stala okreslajaca liczbe cyfr po przecinku
const int POT_10_PRECYZJA = pow(10, PRECYZJA); // 10 podniesione do potegi PRECYZJA

void inkrementacjaDekrementacjaCechy( bool, int &, int & );

Liczba::Liczba( int cecha, int mantysa ) {
	calkowita_ = cecha;
	ulamkowa_ = mantysa;
}//konstruktor

void Liczba::wyswietlLiczbe() {
	if( ulamkowa_ < 0 || calkowita_ < 0 ) { //liczba ujemna
		std::cout << "-" << -calkowita_ << '.' << std::setfill('0'); 
		std::cout << std::setw(PRECYZJA) << -ulamkowa_;
	}
	else { //liczba dodatnia albo zero
		std::cout << calkowita_ << '.' << std::setfill('0'); 
		std::cout << std::setw(PRECYZJA) << ulamkowa_;
	}	
}

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
	return Liczba( -(liczba.calkowita_), -(liczba.ulamkowa_) );
}//wyznacznie liczby przeciwnej

Liczba &Liczba::operator=( const Liczba& liczba ) {
	calkowita_ = liczba.calkowita_;
	ulamkowa_ = liczba.ulamkowa_;
}//operator przypisania

Liczba operator+( const Liczba& pierwsza, const Liczba& druga ) {
	int cecha = pierwsza.calkowita_ + druga.calkowita_;
	int mantysa;
	mantysa = pierwsza.ulamkowa_ + druga.ulamkowa_;

	if( pierwsza.calkowita_ < 0 || pierwsza.ulamkowa_ < 0 ) { //pierwsza liczba ujemna
		if( druga.calkowita_ < 0 || druga.ulamkowa_ < 0 ) { //druga liczba ujemna
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
		if( druga.calkowita_ < 0 || druga.ulamkowa_ < 0 ) { //druga liczba jest ujemna 
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
	int cecha;
	int mantysa;
	int ulamkowaRazyUlamkowa = pierwsza.ulamkowa_ * druga.ulamkowa_;
	int calkowitaRazyUlamkowa = pierwsza.calkowita_ * druga.ulamkowa_;
	int ulamkowaRazyCalkowita = pierwsza.ulamkowa_ * druga.calkowita_;
	cecha = pierwsza.calkowita_ * druga.calkowita_;

	mantysa = ulamkowaRazyUlamkowa % ( POT_10_PRECYZJA * POT_10_PRECYZJA );
	mantysa /= POT_10_PRECYZJA;
	cecha += ulamkowaRazyUlamkowa / ( POT_10_PRECYZJA * POT_10_PRECYZJA ); //sprawdzanie czy potrzebne jest przeniesienie do czesci calkowitej

	cecha += calkowitaRazyUlamkowa / POT_10_PRECYZJA; //sprawdzanie czy potrzebne jest przeniesienie do czesci calkowitej
	mantysa += calkowitaRazyUlamkowa % POT_10_PRECYZJA;

	cecha += ulamkowaRazyCalkowita / POT_10_PRECYZJA; //sprawdzanie czy potrzebne jest przeniesienie do czesci calkowitej
	mantysa += ulamkowaRazyCalkowita % POT_10_PRECYZJA;

	return Liczba( cecha, mantysa );
}

Liczba operator/( const Liczba& pierwsza, const Liczba& druga ) {
	int sumaPierwszej = pierwsza.calkowita_ * POT_10_PRECYZJA + pierwsza.ulamkowa_;
	int sumaDrugiej = druga.calkowita_ * POT_10_PRECYZJA + druga.ulamkowa_; //zapisanie Liczby jako suma czesci calkowitej z odpowiednią waga i ulamkowej
	int cecha = sumaPierwszej / sumaDrugiej; //typ int, reszta zostanie ucieta
	int mantysaModulo= sumaPierwszej % sumaDrugiej; //"reszta" z dzielenie dwoch liczb
	int mantysa = ( mantysaModulo * POT_10_PRECYZJA ) / sumaDrugiej; //wyznaczenie jaka czescia liczby przez ktora dzielimy jest "reszta" z dzielenia 2 liczb
	return Liczba( cecha, mantysa );	
}

bool operator==( const Liczba& pierwsza, const Liczba& druga ) {
	if( pierwsza.calkowita_ == druga.calkowita_ && pierwsza.ulamkowa_ == druga.ulamkowa_ )
		return true;
	else
		return false;
}

bool operator>( const Liczba& pierwsza, const Liczba& druga ) {
	if( pierwsza.calkowita_ >= 0 && pierwsza.ulamkowa_ >= 0 ) { //pierwsza dodatnia albo zero
		if( druga.calkowita_ >= 0 && druga.ulamkowa_ >= 0 ) { //druga dodatnia albo zero
			if( pierwsza.calkowita_ >= druga.calkowita_ && pierwsza.ulamkowa_ > druga.ulamkowa_ )
				return true;
			else
				return false; 
		}
		else // pierwsza dodatnia albo zero, druga ujemna
			return true;
	}
	else { //pierwsza ujemna
		if( druga.calkowita_ < 0 || druga.ulamkowa_ < 0 ) { //druga ujemna
			if( pierwsza.calkowita_ >= druga.calkowita_ && pierwsza.ulamkowa_ > druga.ulamkowa_ )
				return true;
			else
				return false;
		}
		else //pierwsza ujemna, druga dodatnia
			return false;
	}
}

bool operator<( const Liczba& pierwsza, const Liczba& druga ) {
	return druga > pierwsza;
}
