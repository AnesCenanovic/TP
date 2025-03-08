/* 
    TP 16/17 (LV 11, Zadatak 2)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <new>
static int br1=0;
static int br2=0;
class StedniRacun{
    double stanje;
    public:
        StedniRacun() { stanje= 0;br1+=1; br2+=1;}
        StedniRacun(double x) { if(x<0) throw std::logic_error("Nedozvoljeno pocetno stanje"); stanje = x; br1+=1; br2+=1;}
        StedniRacun(const StedniRacun &racun) { stanje= racun.stanje;br1+=1; br2+=1;}
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
        ~StedniRacun() {
                 br1-=1;
            }
        static int DajBrojAktivnih(){
            return br1;
        }
         static int DajBrojKreiranih(){
           return br2;
        }
};
int main ()
{

	return 0;
}