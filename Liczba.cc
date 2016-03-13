#include <iostream>
#include "Liczba.h"
#include <cmath>
#include <iomanip>

static const int PRECYZJA=4;
Liczba::Liczba(int cecha, int mantysa) {
	calkowita= cecha;
	ulamkowa= mantysa;
};
Liczba::~Liczba() {}

void Liczba::wyswietlLiczbe() {
	std::cout << calkowita << '.' << std::setfill('0'); 
	std::cout<< std::setw(PRECYZJA) << ulamkowa << std::endl;
};


// friend operatory

Liczba operator-(Liczba& liczba) {
	return Liczba(-(liczba.calkowita), liczba.ulamkowa);
}

Liczba &Liczba::operator=(Liczba& liczba) {
	this->calkowita = liczba.calkowita;
	this->ulamkowa = liczba.ulamkowa;
}

Liczba operator+(Liczba& pierwsza, Liczba& druga) {
	int cecha = pierwsza.calkowita + druga.calkowita;
	int mantysa;
	if(pierwsza.calkowita<0)
		if(druga.calkowita<0) {
			mantysa= pierwsza.ulamkowa + druga.ulamkowa;
			if(mantysa>=pow(10, PRECYZJA)) {
				mantysa -= pow(10, PRECYZJA);
				cecha--;
			}
		}
		else { //(druga.calkowita>=0)
			mantysa= -pierwsza.ulamkowa + druga.ulamkowa;
			if(mantysa<0) {
				mantysa += pow(10, PRECYZJA);
				cecha--;
			}
		}
	if(pierwsza.calkowita>=0)
		if(druga.calkowita>=0) {
			mantysa = pierwsza.ulamkowa + druga.ulamkowa;
			if(mantysa>=pow(10, PRECYZJA)) {
				mantysa -= pow(10, PRECYZJA);
				cecha++;
			}	
		}
		else { //(druga.calkowita<0) 
			mantysa = pierwsza.ulamkowa - druga.ulamkowa;
			if(mantysa<0) {
				mantysa += pow(10, PRECYZJA);
				cecha--;
			}
		}
	return Liczba(cecha, mantysa);
};

Liczba operator-(Liczba& odjemna, Liczba& odjemnik) {
	Liczba przeciwnyOdjemnik= (-odjemnik);
	return odjemna + przeciwnyOdjemnik;
};

Liczba operator*(Liczba& , Liczba&) {
	int cecha;
	int mantysa;


}

Liczba operator/(Liczba& , Liczba&) {
	
}

bool operator==(Liczba& pierwsza, Liczba& druga) {
	if(pierwsza.calkowita==druga.calkowita && pierwsza.ulamkowa==druga.ulamkowa)
		return true;
	else
		return false;
}

bool operator>(Liczba& pierwsza, Liczba& druga) {
	if(pierwsza.calkowita>=0)
		if(druga.calkowita>=0) { //obie dodatnie
			if(pierwsza.calkowita>=druga.calkowita && pierwsza.ulamkowa>druga.ulamkowa)
				return true;
			else
				return false; 
		}
		else // pierwsza dodatnia, druga ujemna
			return true;
	else { //pierwsza ujemna
		if(druga.calkowita<0) { //obie ujemne
			if(pierwsza.calkowita>=druga.calkowita && pierwsza.ulamkowa<druga.ulamkowa)
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
	/*if(pierwsza.calkowita>=0)
		if(druga.calkowita>=0) { //obie dodatnie
			if(pierwsza.calkowita<=druga.calkowita && pierwsza.ulamkowa<druga.ulamkowa)
				return true;
			else
				return false; 
		}
		else // pierwsza dodatnia, druga ujemna
			return false;
	else { //pierwsza ujemna
		if(druga.calkowita<0) { //obie ujemne
			if(pierwsza.calkowita<=druga.calkowita && pierwsza.ulamkowa>druga.ulamkowa)
				return true;
			else
				return false;
		}
		else //pierwsza ujemna, druga dodatnia
			return true;
	}
	*/
}




	
	
