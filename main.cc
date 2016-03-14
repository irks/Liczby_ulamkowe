#include <iostream>
#include <cmath>
#include "Liczba.h"

using namespace std;

void wypiszMenu(void);
bool menu = true;



int main() {
	while(menu)
		wypiszMenu();
	double a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,r,s;
	Liczba A(2,5000); a=2.5;
	Liczba B(1,2000);b=1.2;
	Liczba C(1,7000);c=1.7;
	Liczba D(0,1000);d=0.1;
	Liczba E(0,9900);e=0.99;
	Liczba F(1,200);f=1.02;
	Liczba G(1,30);g=1.003;
	Liczba H(-1,-5000);h=-1.5;
	Liczba I(1,6000);i=1.6;
	Liczba J(-1,-1000);j=-1.1;
	Liczba K(-2,-2000);k=-2.2;
	Liczba L(-1,-3000);l=-1.3;
	Liczba M(-2,-8000);m=-2.8;
	Liczba N(1,3000);n=1.3;
	Liczba O(-1,-8000);o=-1.8;
	Liczba P(1,8000);p=1.8;
	Liczba R(-2,-3000);r=-2.3l;
	Liczba S(0,-200);s=-0.02;
	
	if(A==B)
		cout<<"rowne" << endl;
	else
		cout<<"rozne" << endl;
	if(J==K)
		cout<<"rowne" << endl;
	else
		cout<<"rozne" << endl;
	if(O==O)
		cout<<"rowne" << endl;
	else
		cout<<"rozne" << endl;

	if(A>B)
		cout<<"wieksze (wieksze)" << endl;
	else
		cout<<"mniejsze (wieksze)" << endl;
	if(J>K)
		cout<<"wieksze (wieksze)" << endl;
	else
		cout<<"mniejsze (wieksze)" << endl;
	if(O>O)
		cout<<"wieksze" << endl;
	else
		cout<<"mniejsze" << endl;
 
	cout << "---------------------dodawanie-----------------------" << endl;

	cout << d+b <<"   "; 			(D+B).wyswietlLiczbe(); cout<<endl; 
	cout << g+c<<"   ";			(G+C).wyswietlLiczbe(); cout<<endl;
	cout << a+e<<"   ";			(A+E).wyswietlLiczbe();  cout<<endl;
	cout << f+g<<"   ";			(F+G).wyswietlLiczbe(); cout<<endl;
	cout << o+i<<"   "; 			(O+I).wyswietlLiczbe(); cout<<endl;
	cout << j+k<<"   ";			(J+K).wyswietlLiczbe(); cout<<endl;
	cout << m+m<<"   ";			(M+M).wyswietlLiczbe(); cout<<endl;
	cout << n+r<<"   "; 			(N+R).wyswietlLiczbe(); cout<<endl;
	cout << l+b<<"   "; 			(L+B).wyswietlLiczbe(); cout<<endl;
	cout << g+p<<"   "; 			(G+P).wyswietlLiczbe();cout<<endl;
	cout << s+e<<"   ";			(S+E).wyswietlLiczbe(); cout<<endl;
	cout << e+s<<"   ";			(E+S).wyswietlLiczbe(); cout<<endl;
	cout << i+s<<"   "; 			(I+S).wyswietlLiczbe(); cout<<endl;
	cout << e+h<<"   "; 			(E+H).wyswietlLiczbe(); cout<<endl;
	cout << s+g<<"   "; 			(S+G).wyswietlLiczbe();cout<<endl;

	cout << "----------------odejmowanie----------------------------" << endl;

	cout << d-b <<"   "; 			(D-B).wyswietlLiczbe(); cout<<endl;
	cout << g-c<<"   ";			(G-C).wyswietlLiczbe(); cout<<endl;
	cout << a-e<<"   ";			(A-E).wyswietlLiczbe();  cout<<endl;
	cout << f-g<<"   ";			(F-G).wyswietlLiczbe(); cout<<endl;
	cout << o-i<<"   "; 			(O-I).wyswietlLiczbe(); cout<<endl;
	cout << j-k<<"   ";			(J-K).wyswietlLiczbe(); cout<<endl;
	cout << m-m<<"   ";			(M-M).wyswietlLiczbe(); cout<<endl;
	cout << n-r<<"   "; 			(N-R).wyswietlLiczbe(); cout<<endl;
	cout << l-b<<"   "; 			(L-B).wyswietlLiczbe(); cout<<endl;
	cout << g-p<<"   "; 			(G-P).wyswietlLiczbe();cout<<endl;
	cout << s-e<<"   ";			(S-E).wyswietlLiczbe(); cout<<endl;
	cout << e-s<<"   ";			(E-S).wyswietlLiczbe(); cout<<endl;
	cout << i-s<<"   "; 			(I-S).wyswietlLiczbe(); cout<<endl;
	cout << e-h<<"   "; 			(E-H).wyswietlLiczbe(); cout<<endl;
	cout << s-g<<"   "; 			(S-G).wyswietlLiczbe();cout<<endl;

	cout << "---------------------mnozenie-----------------------" << endl;

	cout << d*b <<"   "; 			(D*B).wyswietlLiczbe(); cout<<endl;
	cout << g*c<<"   ";			(G*C).wyswietlLiczbe(); cout<<endl;
	cout << a*e<<"   ";			(A*E).wyswietlLiczbe();  cout<<endl;
	cout << f*g<<"   ";			(F*G).wyswietlLiczbe(); cout<<endl;
	cout << o*i<<"   "; 			(O*I).wyswietlLiczbe(); cout<<endl;
	cout << j*k<<"   ";			(J*K).wyswietlLiczbe(); cout<<endl;
	cout << m*m<<"   ";			(M*M).wyswietlLiczbe(); cout<<endl;
	cout << n*r<<"   "; 			(N*R).wyswietlLiczbe(); cout<<endl;
	cout << l*b<<"   "; 			(L*B).wyswietlLiczbe(); cout<<endl;
	cout << g*p<<"   "; 			(G*P).wyswietlLiczbe();cout<<endl;
	cout << s*e<<"   ";			(S*E).wyswietlLiczbe(); cout<<endl;
	cout << e*s<<"   ";			(E*S).wyswietlLiczbe(); cout<<endl;
	cout << i*s<<"   "; 			(I*S).wyswietlLiczbe(); cout<<endl;
	cout << e*h<<"   "; 			(E*H).wyswietlLiczbe(); cout<<endl;
	cout << s*g<<"   "; 			(S*G).wyswietlLiczbe();cout<<endl;

	cout << "--------------------dzielenie------------------------" << endl;

	cout << d/b <<"   "; 			(D/B).wyswietlLiczbe(); cout<<endl;
	cout << g/c<<"   ";			(G/C).wyswietlLiczbe(); cout<<endl;
	cout << a/e<<"   ";			(A/E).wyswietlLiczbe();  cout<<endl;
	cout << f/g<<"   ";			(F/G).wyswietlLiczbe(); cout<<endl;
	cout << o/i<<"   "; 			(O/I).wyswietlLiczbe(); cout<<endl;
	cout << j/k<<"   ";			(J/K).wyswietlLiczbe(); cout<<endl;
	cout << m/m<<"   ";			(M/M).wyswietlLiczbe(); cout<<endl;
	cout << n/r<<"   "; 			(N/R).wyswietlLiczbe(); cout<<endl;
	cout << l/b<<"   "; 			(L/B).wyswietlLiczbe(); cout<<endl;
	cout << g/p<<"   "; 			(G/P).wyswietlLiczbe();cout<<endl;
	cout << s/e<<"   ";			(S/E).wyswietlLiczbe(); cout<<endl;
	cout << e/s<<"   ";			(E/S).wyswietlLiczbe(); cout<<endl;
	cout << i/s<<"   "; 			(I/S).wyswietlLiczbe(); cout<<endl;
	cout << e/h<<"   "; 			(E/H).wyswietlLiczbe(); cout<<endl;
	cout << s/g<<"   "; 			(S/G).wyswietlLiczbe();cout<<endl;
}//main




void wypiszMenu() {
	int wybor=0;
	int cecha1=0,cecha2=0,mantysa1=0,mantysa2=0;
	cout << "Jaka operacje chcesz wykonac? Wcisnij odpowiedni numer." << endl;
	cout << "1. Dodac liczby"<< endl;
	cout << "2. Odjac liczby"<< endl;
	cout << "3. Pomnozyc liczby"<< endl;
	cout << "4. Podzielic liczby"<< endl;
	cout << "5. Porownac liczby"<< endl;
	cout << "9. Wyjsc z programu" << endl;

	cin >> wybor;
	switch(wybor) 
	{
		case 1: {
			cout << "Podaj czesc calkowita pierwszej liczby:" << endl;
			cin >> cecha1;
			cout << "Podaj czesc ulamkowa pierwszej liczby:" << endl;
			cin >> mantysa1;
			cout << "Podaj czesc calkowita drugiej liczby:" << endl;
			cin >> cecha2;
			cout << "Podaj czesc ulamkowa drugiej liczby:" << endl;
			cin >> mantysa2;
			Liczba liczba1(cecha1, mantysa1);
			Liczba liczba2(cecha2, mantysa2);
			Liczba wynik = liczba1+liczba2;
			wynik.wyswietlLiczbe();
			break;
		}
		case 2: {
			cout << "Podaj czesc calkowita pierwszej liczby:" << endl;
			cin >> cecha1;
			cout << "Podaj czesc ulamkowa pierwszej liczby:" << endl;
			cin >> mantysa1;
			cout << "Podaj czesc calkowita drugiej liczby:" << endl;
			cin >> cecha2;
			cout << "Podaj czesc ulamkowa drugiej liczby:" << endl;
			cin >> mantysa2;
			Liczba liczba1(cecha1, mantysa1);
			Liczba liczba2(cecha2, mantysa2);
			Liczba wynik = liczba1-liczba2;
			wynik.wyswietlLiczbe();
		}
		case 3: {
			cout << "Podaj czesc calkowita pierwszej liczby:" << endl;
			cin >> cecha1;
			cout << "Podaj czesc ulamkowa pierwszej liczby:" << endl;
			cin >> mantysa1;
			cout << "Podaj czesc calkowita drugiej liczby:" << endl;
			cin >> cecha2;
			cout << "Podaj czesc ulamkowa drugiej liczby:" << endl;
			cin >> mantysa2;
			Liczba liczba1(cecha1, mantysa1);
			Liczba liczba2(cecha2, mantysa2);
			Liczba wynik = liczba1*liczba2;
			wynik.wyswietlLiczbe();
		}
		case 4: {
			cout << "Podaj czesc calkowita pierwszej liczby:" << endl;
			cin >> cecha1;
			cout << "Podaj czesc ulamkowa pierwszej liczby:" << endl;
			cin >> mantysa1;
			cout << "Podaj czesc calkowita drugiej liczby:" << endl;
			cin >> cecha2;
			cout << "Podaj czesc ulamkowa drugiej liczby:" << endl;
			cin >> mantysa2;
			Liczba liczba1(cecha1, mantysa1);
			Liczba liczba2(cecha2, mantysa2);
			Liczba wynik = liczba1/liczba2;
			wynik.wyswietlLiczbe();
		}
		case 5: {
			cout << "Podaj czesc calkowita pierwszej liczby:" << endl;
			cin >> cecha1;
			cout << "Podaj czesc ulamkowa pierwszej liczby:" << endl;
			cin >> mantysa1;
			cout << "Podaj czesc calkowita drugiej liczby:" << endl;
			cin >> cecha2;
			cout << "Podaj czesc ulamkowa drugiej liczby:" << endl;
			cin >> mantysa2;
			Liczba liczba1(cecha1, mantysa1);
			Liczba liczba2(cecha2, mantysa2);
			if(liczba1>liczba2) {
				liczba1.wyswietlLiczbe(); 
				cout<<" > "; 
				liczba2.wyswietlLiczbe();
			}
			else if(liczba1<liczba2) {
				liczba1.wyswietlLiczbe(); 
				cout<<" < "; 
				liczba2.wyswietlLiczbe();
			}
			else {
				liczba1.wyswietlLiczbe(); 
				cout<<" == "; 
				liczba2.wyswietlLiczbe();
			}
			
		}
		case 9: {
			menu=false;
			break;
		}
		default: {
			cout<< "Musisz podac numer odpowiadajacy danemu dzialaniu!"<<endl;
		}
	}
}


