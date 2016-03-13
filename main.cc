#include <iostream>
#include "Liczba.h"

using namespace std;

bool menu = true;

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
			Liczba test_1(cecha1, mantysa1);
			Liczba test_2(cecha2, mantysa2);
			(test_1+test_2).wyswietlLiczbe();
			break;
		}
		case 9: {
			menu=false;
			break;
		}
	}
}

int main() {
	//Liczba A(100,5);
	//Liczba B(4,1);
	//Liczba C = (A+B);
	int x= -0;
	cout<< x << endl;
	Liczba A(2,5000);
	Liczba B(1,2000);
	Liczba C(1,7000);
	Liczba D(0,1000);
	Liczba E(0,9900);
	Liczba F(1,200);
	Liczba G(1,30);
	Liczba H(-1,5000);
	Liczba I(1,6000);
	Liczba J(-1,1000);
	Liczba K(-2,2000);
	Liczba L(-1,3000);
	Liczba M(-2,8000);
	Liczba N(1,3000);
	Liczba O(-1,8000);
	Liczba P(1,8000);
	Liczba R(-2,3000);
	
	
	cout << "2,5000 +1,2000 =3,7      "; (A+B).wyswietlLiczbe(); 
	cout << "2,5000 +1,7000 =4,2      ";(A+C).wyswietlLiczbe(); 
	cout << "0,1000 +0,9900 =1,09     ";(D+E).wyswietlLiczbe();  
	cout << "1,0200 +1,0030 =2,0230   ";(F+G).wyswietlLiczbe(); 
	cout << "-1,5000 +1,6000 =0,1     "; (H+I).wyswietlLiczbe(); 
	cout << "-1,1000 +-2,2000 =-3,3   ";(J+K).wyswietlLiczbe(); 
	cout << "-1,3000 +-2,8000 =-4,1   ";(L+M).wyswietlLiczbe(); 
	cout << "1,3000 +-1,8000 =-0,5    "; (N+O).wyswietlLiczbe(); 
	cout << "-1,3000 + 1,8000=0,5     "; (L+P).wyswietlLiczbe(); 
	cout << "-2,3000 + 1,8000=-0,5    "; (R+P).wyswietlLiczbe(); 
	//while(menu) {
	//	wypiszMenu();
	//}

	//cout << "Liczba A:  ";  A.wyswietlLiczbe();
	//cout << "Liczba B:  ";  B.wyswietlLiczbe();
	//cout << "A+B:  ";  C.wyswietlLiczbe();

	cout << endl<<endl<<"2,5000 -1,2000 =1,3      "; (A-B).wyswietlLiczbe(); 
	cout << "2,5000 -1,7000 =0,8      ";(A-C).wyswietlLiczbe(); 
	cout << "0,1000 -0,9900 =-0,89     ";(D-E).wyswietlLiczbe();  
	cout << "1,0200 -1,0030 =0,0170   ";(F-G).wyswietlLiczbe(); 

	cout << "-1,1000 --2,2000 =1,1   ";(J-K).wyswietlLiczbe(); 
	cout << "-1,3000 --2,8000 =1,5   ";(L-M).wyswietlLiczbe(); 

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
		cout<<"wieksze" << endl;
	else
		cout<<"mniejsze" << endl;
	if(J>K)
		cout<<"wieksze" << endl;
	else
		cout<<"mniejsze" << endl;
	if(O>O)
		cout<<"wieksze" << endl;
	else
		cout<<"mniejsze" << endl;
}


