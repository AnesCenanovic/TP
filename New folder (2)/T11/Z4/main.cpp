/* 
    TP 16/17 (LV 11, Zadatak 4)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <tuple>
#include <stdexcept>
class Kugla{
  double a,b,c;
  unsigned int poluprecnik;
    public:
    explicit Kugla(double r = 0);
    Kugla(double x, double y, double z, double r = 0);
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0);
    double DajX() const;
    double DajY() const;
    double DajZ() const;
    std::tuple<double, double, double> DajCentar() const;
    double DajPoluprecnik() const;
    double DajPovrsinu() const;
    double DajZapreminu() const;
    Kugla &PostaviX(double x);
    Kugla &PostaviY(double y);
    Kugla &PostaviZ(double z);
    Kugla &PostaviCentar(double x, double y, double z);
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    Kugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z);
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};
int main ()
{
	return 0;
}
Kugla::Kugla(double r){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    poluprecnik=r;a=0;b=0;c=0;
}
Kugla::Kugla(double x, double y, double z, double r){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    a=x;b=y;c=z;poluprecnik=r;
}
Kugla::Kugla(const std::tuple<double, double, double> &centar, double r){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    a=std::get<0>(centar);b=std::get<1>(centar);c=std::get<2>(centar);poluprecnik=r;
}
double Kugla::DajX() const{
    return a;
};
double Kugla::DajY() const{
    return b;
};
double Kugla::DajZ() const{
    return c;
};
std::tuple<double, double, double> Kugla::DajCentar() const{
    std::tuple<double, double, double> rez;
    std::get<0>(rez)=a;
    std::get<1>(rez)=b;
    std::get<2>(rez)=c;
    return rez;
};
double Kugla::DajPoluprecnik() const{
    return poluprecnik;
};
double Kugla::DajPovrsinu() const{
return 5;
};
double Kugla::DajZapreminu() const{
return 5;
};
