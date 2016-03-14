#include <iostream>
#include <cmath>
#include <iomanip> //potrzebne przy wyswietlaniu Liczb
#include "Liczba.h"

static const int PRECYZJA=4; //stala okreslajaca liczbe cyfr po przecinku

Liczba::Liczba(int cecha, int mantysa) {
	calkowita= cecha;
	ulamkowa= mantysa;
};//konstruktor
Liczba::~Liczba() {}//destruktor

void Liczba::wyswietlLiczbe() {
	if(ulamkowa<0 || calkowita<0 ) { //liczba ujemna
		std::cout<<"-"<< -calkowita << '.' << std::setfill('0'); 
		std::cout << std::setw(PRECYZJA) << -ulamkowa;
	}
	else { //liczba dodatnia albo zero
		std::cout << calkowita << '.' << std::setfill('0'); 
		std::cout << std::setw(PRECYZJA) << ulamkowa;
	}	
};

// friend operatory

Liczba operator-(Liczba& liczba) {
	return Liczba(-(liczba.calkowita), -(liczba.ulamkowa));
}//wyznacznie liczby przeciwnej

Liczba &Liczba::operator=(Liczba& liczba) {
	this->calkowita = liczba.calkowita;
	this->ulamkowa = liczba.ulamkowa;
}//operator przypisania

Liczba operator+(Liczba& pierwsza, Liczba& druga) {
	int cecha = pierwsza.calkowita + druga.calkowita;
	int mantysa;
		
	if(pierwsza.calkowita<0 || pierwsza.ulamkowa<0) { //pierwsza liczba ujemna
		if(druga.calkowita<0 || druga.ulamkowa<0) { //druga liczba ujemna
			mantysa= pierwsza.ulamkowa + druga.ulamkowa;
			if(mantysa<=(-pow(10, PRECYZJA))) { //sprawdzanie czy potrzebne jest przeniesienie
				mantysa += pow(10, PRECYZJA);
				cecha--;
			}
		}
		else { //druga liczba dodatnia albo zero
			mantysa= pierwsza.ulamkowa + druga.ulamkowa;
			if(mantysa<0&&cecha>0) { //sprawdzanie czy cecha nie ma innego znaku niz mantysa
				mantysa += pow(10, PRECYZJA);
				cecha--;
			}
			else if(mantysa>=0 && cecha<0) { //sprawdzanie czy cecha nie ma innego znaku niz mantysa
				mantysa -= pow(10, PRECYZJA);
				cecha++;
			}
		}
	}
	else  { //pierwsza liczba jest dodatnia albo zerem
		if(druga.calkowita<0 || druga.ulamkowa<0) { //druga liczba jest ujemna 
			mantysa = pierwsza.ulamkowa + druga.ulamkowa;
			if(mantysa<0&&cecha>0) { //sprawdzanie czy cecha nie ma innego znaku niz mantysa
				mantysa += pow(10, PRECYZJA);
				cecha--;
			}
			else if(mantysa>0&&cecha<0) { //sprawdzanie czy cecha nie ma innego znaku niz mantysa
				mantysa -= pow(10, PRECYZJA);
				cecha++;
			}
		}
		else { //druga liczba jest dodatnia
			mantysa = pierwsza.ulamkowa + druga.ulamkowa;
			if(mantysa>=pow(10, PRECYZJA)) { //sprawdzanie czy potrzebne jest przeniesienie
				mantysa -= pow(10, PRECYZJA);
				cecha++;
			}	
		}		
	}
	return Liczba(cecha, mantysa);
}

Liczba operator-(Liczba& odjemna, Liczba& odjemnik) {
	Liczba przeciwnyOdjemnik= (-odjemnik); //wyznaczenie liczby przeciwnej do odjemnika aby skorzystać z operatora dodawania
	return odjemna + przeciwnyOdjemnik;
}

Liczba operator*(Liczba& pierwsza, Liczba& druga) {
	int sumaPierwszej= pierwsza.calkowita*pow(10,PRECYZJA) + pierwsza.ulamkowa; 
	int sumaDrugiej = druga.calkowita*pow(10,PRECYZJA) + druga.ulamkowa; //zapisanie Liczby jako suma czesci calkowitej z odpowiednią waga i ulamkowej
	int iloczynSum = sumaPierwszej*sumaDrugiej; 
	int cecha = iloczynSum/pow(10,2*PRECYZJA); //wyznaczenie cechy poprzez "skrocenie" iloczynu sum o 2*PRECYZJA
	int mantysa =  iloczynSum/pow(10,PRECYZJA); 
	mantysa %= static_cast<int>(pow(10, PRECYZJA)); //mantysa jako modulo 10^PRECYZJA (pow zwraca double, potrzebne rzutowanie)
	return Liczba(cecha,mantysa);
}

Liczba operator/(Liczba& pierwsza, Liczba& druga) {
	int sumaPierwszej = pierwsza.calkowita*pow(10,PRECYZJA) + pierwsza.ulamkowa;
	int sumaDrugiej = druga.calkowita*pow(10,PRECYZJA) + druga.ulamkowa; //zapisanie Liczby jako suma czesci calkowitej z odpowiednią waga i ulamkowej
	int cecha = sumaPierwszej / sumaDrugiej; //typ int, reszta zostanie ucieta
	int mantysaModulo=sumaPierwszej % sumaDrugiej; //"reszta" z dzielenie dwoch liczb
	int mantysa = (mantysaModulo*pow(10,PRECYZJA)) / sumaDrugiej; //wyznaczenie jaka czescia liczby przez ktora dzielimy jest "reszta" z dzielenia 2 liczb
	return Liczba(cecha,mantysa);	
}

bool operator==(Liczba& pierwsza, Liczba& druga) {
	if(pierwsza.calkowita==druga.calkowita && pierwsza.ulamkowa==druga.ulamkowa)
		return true;
	else
		return false;
}

bool operator>(Liczba& pierwsza, Liczba& druga) {
	if(pierwsza.calkowita>=0 && pierwsza.ulamkowa>=0) { //pierwsza dodatnia albo zero
		if(druga.calkowita>=0 && druga.ulamkowa>=0) { //druga dodatnia albo zero
			if(pierwsza.calkowita>=druga.calkowita && pierwsza.ulamkowa>druga.ulamkowa)
				return true;
			else
				return false; 
		}
		else // pierwsza dodatnia albo zero, druga ujemna
			return true;
	}
	else { //pierwsza ujemna
		if(druga.calkowita<0 || druga.ulamkowa<0) { //druga ujemna
			if(pierwsza.calkowita>=druga.calkowita && pierwsza.ulamkowa>druga.ulamkowa)
				return true;
			else
				return false;
		}
		else //pierwsza ujemna, druga dodatnia
			return false;
	}
}

bool operator<(Liczba& pierwsza, Liczba& druga) {
	if(druga>pierwsza)
		return true;
	else
		return false;
}




	
	
