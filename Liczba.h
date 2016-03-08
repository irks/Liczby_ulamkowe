#ifndef LICZBA_H_
#define LICZBA_H_

class Liczba 
{
	static const int CYFR_PO_PRZECINKU=4;
	public:
		Liczba();
		~Liczba();
		int czescCalkowita;
		int czescUlamkowa;
		double utworzLiczbe(); // tworzenie liczby ulamkowej z dwoch calkowitych
	private:
};
#endif //LICZBA_H_
