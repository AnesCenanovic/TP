/* 
    TP 2018/2019: LV 5, Zadatak 3
	
	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.
	
	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje niz[i] ili simulacija indeksiranja
			  npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.
			  
			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
typedef std::deque<int> niz;


void Unesi(int &a) {
 std::cin >> a ;
}
void Ispisi(int a) {
    if(!((int)log10(abs(a)) ==2))
    std::cout << a << " ";
}
bool Kvadrat(int a){
    if(sqrt(a)-floor(sqrt(a))==0)
    return true;
    return false;
}
bool Cifre(int a, int b){
    if((int)log10(abs(a))>(int)log10(abs(b)))
    return true;
    return false;
}


int main ()
{
    int n;
    std::deque<int>::iterator i1,i2;
    niz a;
    std::cout << "Unesite broj elemenata: ";
    std::cin >> n;
    if(n>1000)
    return 0;
    a.resize(n);
    std::cout << "Unesite elemente: ";
    std::for_each(a.begin(),a.end(),Unesi);
    std::cout << "Najveci element deka je ";
    i1 = std::max_element(a.begin(),a.end());
    i2 = std::min_element(a.begin(),a.end());
    std::cout<<*i1<<std::endl;
    std::cout << "Najmanji element deka se pojavljuje " << std::count(a.begin(),a.end(),*std::min_element(a.begin(),a.end()))  << " puta u deku" << std::endl;
    std::cout << "U deku ima " << std::count_if(a.begin(),a.end(),Kvadrat)  << " brojeva koji su potpuni kvadrati" << std::endl;
    std::cout << "Prvi element sa najmanjim brojem cifara je " << *std::max_element(a.begin(),a.end(),Cifre) << std::endl;
    std::cout << "Elementi koji nisu trocifreni su: ";
    std::for_each(a.begin(),a.end(),Ispisi);
    return 0;
}