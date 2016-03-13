//#ifndef LICZBA_H_
//#define LICZBA_H_

class Liczba 
{ //domyslnie private
	int calkowita;
	int ulamkowa;
	
	
	public:
		Liczba(int=0,int=0);
		~Liczba();
		void wyswietlLiczbe();
		friend Liczba operator+(Liczba&, Liczba&);
		friend Liczba operator-(Liczba&, Liczba&);
		friend Liczba operator*(Liczba&, Liczba&);
		friend Liczba operator/(Liczba&, Liczba&);
		friend bool operator==(Liczba&, Liczba&);
		friend bool operator>(Liczba&, Liczba&);
		friend bool operator<(Liczba&, Liczba&);
		friend Liczba operator-(Liczba&);
		Liczba &operator=(Liczba&);
};
//#endif //LICZBA_H_
