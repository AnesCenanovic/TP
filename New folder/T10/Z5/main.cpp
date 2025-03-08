/* 
    TP 16/17 (LV 10, Zadatak 5)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
const double PI=4*atan(1);
class Ugao{
    int deg,min,sek;
    public:
Ugao(double radijani = 0){
    if(radijani>=2*PI)while(radijani>=2*PI) radijani-=2*PI;
    else if (radijani<0)while(radijani<0) radijani+=2*PI;
    double rez=radijani*180/PI;
    Postavi(int(rez),int((rez-int(rez))*60),(rez-int(rez)-int((rez-int(rez))*60)/60.)*3600+1e-6);
};
Ugao(int stepeni, int minute, int sekunde){
    if(sekunde>59)while(sekunde>59) sekunde-=60,minute++;
    else if(sekunde<0)while(sekunde<0) sekunde+=60,minute--;
     if(minute>59)while(minute>59) minute-=60,stepeni++;
    else if(minute<0)while(minute<0) minute+=60,stepeni--;
    if(stepeni>=360)while(stepeni>=360) stepeni-=360;
    else if(stepeni<0)while(stepeni<0) stepeni+=360;
    Ugao::deg=stepeni;Ugao::min=minute;Ugao::sek=sekunde;
};
void Postavi(double radijani){
    if(radijani>=2*PI)while(radijani>=2*PI) radijani-=2*PI;
    else if (radijani<0)while(radijani<0) radijani+=2*PI;
    double rez=radijani*180/PI;
    Postavi(int(rez),int((rez-int(rez))*60),(rez-int(rez)-int((rez-int(rez))*60)/60.)*3600+1e-6);
}
void Postavi(int stepeni, int minute, int sekunde){
    if(sekunde>59)while(sekunde>59) sekunde-=60,minute++;
    else if(sekunde<0)while(sekunde<0) sekunde+=60,minute--;
     if(minute>59)while(minute>59) minute-=60,stepeni++;
    else if(minute<0)while(minute<0) minute+=60,stepeni--;
    if(stepeni>=360)while(stepeni>=360) stepeni-=360;
    else if(stepeni<0)while(stepeni<0) stepeni+=360;
    Ugao::deg=stepeni;Ugao::min=minute;Ugao::sek=sekunde;
}
double DajRadijane() const{
    return (deg+min/60.+sek/3600.)*PI/180;
}
void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde){
    stepeni=DajStepene();minute=DajMinute();sekunde=DajSekunde();
}
int DajStepene() const{return deg;}
int DajMinute() const{return min;}
int DajSekunde() const{return sek;}
void Ispisi() const{std::cout<<std::fixed<<std::setprecision(5)<<DajRadijane();};
void IspisiKlasicno() const{
    int x=DajStepene();
    int y=DajMinute();
    int z=DajSekunde();
    if(z>59){
        z=0;
        y++;
    }
    std::cout<<x<<"deg "<<y<<"min "<<z<<"sec";
}
Ugao &SaberiSa(const Ugao &u){Postavi(DajRadijane()+u.DajRadijane()); return *this;};
Ugao &PomnoziSa(double x){Postavi(DajRadijane()*x); return *this;};
friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2);
friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x);
};
Ugao ZbirUglova(const Ugao &u1, const Ugao &u2){
    Ugao rez(u1.DajRadijane()+u2.DajRadijane());
    return rez;
    }
Ugao ProduktUglaSaBrojem(const Ugao &u, double x){
    Ugao rez(u.DajRadijane()*x);
    return rez;
}
int main ()
{
	return 0;
}