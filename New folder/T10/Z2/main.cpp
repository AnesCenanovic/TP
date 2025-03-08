/* 
    TP 16/17 (LV 10, Zadatak 2)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
const double PI=4*std::atan(1);
class Krug{
    double poluprecnik;
    public:
    explicit Krug(double x){
        if(x<=0) throw std::domain_error("Neispravan poluprecnik");
        poluprecnik=x;
    }
    void Postavi(double x){
        if(x<=0) throw std::domain_error("Neispravan poluprecnik");
        poluprecnik=x;
    }
    double DajPoluprecnik()const{return poluprecnik;}
    double DajPovrsinu()const{return poluprecnik*poluprecnik*PI;}
    double DajObim()const{return 2*poluprecnik*PI;}
    void Skaliraj(double x){
        if(x<=0) throw std::domain_error("Neispravan faktor skaliranja");
        poluprecnik*=x;
    }
    void Ispisi()const{
        std::cout<<std::fixed<<" R="<<std::setprecision(5)<<DajPoluprecnik()<<std::fixed<<" O="<<std::setprecision(5)<<DajObim()<<std::fixed<<" P="<<std::setprecision(5)<<DajPovrsinu();
    }
};
class Valjak{
    Krug baza;
    double visina;
    public:
        public:
    explicit Valjak(double x,double y):baza(x){
        if(x<0) throw std::domain_error("Neispravan poluprecnik");
        if(y<0) throw std::domain_error("Neispravna visina");
        visina=y;
    }
    void Postavi(double x,double y){
         if(x<0) throw std::domain_error("Neispravan poluprecnik");
        if(y<0) throw std::domain_error("Neispravna visina");
        baza=Krug(x);
        visina=y;
    }
    Krug DajBazu()const{return baza;}
    double DajPoluprecnikBaze()const{return baza.DajPoluprecnik();}
    double DajVisinu()const{return visina;}
    double DajPovrsinu()const{return (2*DajPoluprecnikBaze()*DajPoluprecnikBaze()*PI+2*DajPoluprecnikBaze()*DajVisinu()*PI);}
    double DajZapreminu()const{return DajVisinu()*baza.DajPovrsinu();}
    void Skaliraj(double x){
        if(x<=0) throw std::domain_error("Neispravan faktor skaliranja");
        visina*=x;
        baza.Skaliraj(x);
    }
    void Ispisi()const{
        std::cout<<std::fixed<<"R="<<std::setprecision(5)<<DajPoluprecnikBaze()<<std::fixed<<" H="<<std::setprecision(5)<<DajVisinu()<<std::fixed<<" P="<<std::setprecision(5)<<DajPovrsinu()<<std::fixed<<" V="<<std::setprecision(5)<<DajZapreminu();
    }
};
int main ()
{
	return 0;
}