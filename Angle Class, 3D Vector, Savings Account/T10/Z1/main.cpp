/* 
    TP 16/17 (LV 10, Zadatak 1)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
#include <cmath>
class StedniRacun{
    double stanje;
    public:
        StedniRacun() { stanje= 0; }
        StedniRacun(double x) { if(x<0) throw std::logic_error("Nedozvoljeno pocetno stanje"); stanje = x; }
        void Ulozi(double x){
            if(fabs(x)>stanje && x<0)throw std::logic_error("Transakcija odbijena");
            stanje+=x;
        }
        void Podigni(double x){
            if(stanje>=x)
            stanje-=x;
            else throw std::logic_error("Transakcija odbijena");
        }
        double DajStanje()const{
            return stanje;
        }
        void ObracunajKamatu(double x){
            if(x<0) throw std::logic_error("Nedozvoljena kamatna stopa");
            stanje+=stanje*(x/100);
        }
};
int main ()
{

	return 0;
}