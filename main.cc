#include <iostream>
#include "Liczba.h"

//using namespace std;

void wypiszMenu() {
	std::cout << "Test text" << std::endl;
}

int main() {
	Liczba A;
	A.czescCalkowita = 210;
	A.czescUlamkowa = 211;
	std::cout << A.czescCalkowita << ' ' <<  A.czescUlamkowa << std::endl;
	wypiszMenu();
	std::cout << A.utworzLiczbe() << std::endl;
}


