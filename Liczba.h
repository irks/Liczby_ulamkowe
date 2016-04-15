// Wrobel Ireneusz, Informatyka, grupa 2I5 
// Plik naglowkowy, klasa Liczba

extern const int PRECYZJA; //stala okreslajaca liczbe cyfr po przecinku
extern const int POT_10_PRECYZJA; // 10 podniesione do potegi PRECYZJA

class Liczba 
{ //domyslnie private
	int calkowita_;
	int ulamkowa_;

	public:
		Liczba( int=0, int=0 );
		void wyswietlLiczbe(); 
		friend Liczba operator-( const Liczba& );
		Liczba &operator=( const Liczba& );
		friend Liczba operator+( const Liczba&, const Liczba& );
		friend Liczba operator-( const Liczba&, const Liczba& );
		friend Liczba operator*( const Liczba&, const Liczba&);
		friend Liczba operator/( const Liczba&, const Liczba& );
		friend bool operator==( const Liczba&, const Liczba& );
		friend bool operator>( const Liczba&, const Liczba& );
		friend bool operator<( const Liczba&, const Liczba& );	
};
