#include "Liczba.h"
#include <cmath>

Liczba::Liczba() {}
Liczba::~Liczba() {}

double Liczba::utworzLiczbe() {
	double pomocnicza = czescCalkowita ;
	double pomocniczaMantysa = double(czescUlamkowa);
	pomocniczaMantysa /= pow(10, CYFR_PO_PRZECINKU);
	pomocnicza +=pomocniczaMantysa;
	return pomocnicza;
}
	
	
