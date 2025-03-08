/* 
    TP 16/17 (LV 10, Zadatak 4)
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
    double ugao;
    public:
Ugao(double radijani = 0){
    if(radijani>=2*PI)while(radijani>=2*PI) radijani-=2*PI;
    else if (radijani<0)while(radijani<0) radijani+=2*PI;
    ugao=radijani;
};
Ugao(int stepeni, int minute, int sekunde){
    if(stepeni>=360)while(stepeni>=360) stepeni-=360;
    else if(stepeni<0)while(stepeni<0) stepeni+=360;
    ugao=(stepeni+minute/60.+sekunde/3600.)*PI/180;
};
void Postavi(double radijani){
    if(radijani>=2*PI)while(radijani>=2*PI) radijani-=2*PI;
    else if (radijani<0)while(radijani<0) radijani+=2*PI;
    ugao=radijani;
}
void Postavi(int stepeni, int minute, int sekunde){
    if(stepeni>=360)while(stepeni>=360) stepeni-=360;
    else if(stepeni<0)while(stepeni<0) stepeni+=360;
    ugao=(stepeni+minute/60.+sekunde/3600.)*PI/180;
}
double DajRadijane() const{
    return ugao;
}
void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde){
    stepeni=DajStepene();minute=DajMinute();sekunde=DajSekunde();
}
int DajStepene() const{return ugao*180/PI;}
int DajMinute() const{return (ugao*180/PI -DajStepene())*60;}
int DajSekunde() const{double rez=(((ugao*180/PI -DajStepene())*60)-DajMinute())*60; return rez+1e-6;}
void Ispisi() const{std::cout<<std::fixed<<std::setprecision(5)<<ugao;};
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
Ugao &SaberiSa(const Ugao &u){Postavi(ugao+u.ugao); return *this;};
Ugao &PomnoziSa(double x){Postavi(ugao*x); return *this;};
friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2);
friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x);
};
Ugao ZbirUglova(const Ugao &u1, const Ugao &u2){
    Ugao rez(u1.ugao+u2.ugao);
    return rez;
    }
Ugao ProduktUglaSaBrojem(const Ugao &u, double x){
    Ugao rez(u.ugao*x);
    return rez;
}
int main ()
{
	return 0;
}