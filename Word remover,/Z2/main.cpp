/* 
    TP 2018/2019: LV 5, Zadatak 2
	
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

template <typename element1,typename element2> 
void razmjena(element1& a, element2& b)
{
  element2 c(a); 
  a=b; 
  b=c;
}

template<typename begin,typename end>
auto RazmijeniBlokove( begin pocetak1, begin kraj1, end pocetak2 ) -> decltype(pocetak2){

    while(pocetak1!=kraj1){
        razmjena(*pocetak1,*pocetak2);
        pocetak2++;
        pocetak1++;
    }
    
    return pocetak2;
}
int main ()
{
	return 0;
}