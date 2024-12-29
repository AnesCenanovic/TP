/* 
    TP 16/17 (LV 7, Zadatak 8)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

std::string IzvrniBezRazmaka(std::string str){
    std::string rez(str.length(), ' ');
    std::remove_copy(str.rbegin(),str.rend(),rez.begin(),' ');
    return rez;
}
int main ()
{
    std::cout<<"Izvrnut : ";
    std::string str2=IzvrniBezRazmaka("  udovica  baci   vodu");
    std::cout<<str2;
	return 0;
}