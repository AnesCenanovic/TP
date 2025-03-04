/* 
    TP 16/17 (LV 9, Zadatak 1)
	
	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cmath>
class Vektor3d {
 double x, y, z;
public:
 void Postavi(double x, double y, double z) {
 Vektor3d::x = x; Vektor3d::y = y; Vektor3d::z = z;
 }
 void Ocitaj(double &x, double &y, double &z) const {
 x = Vektor3d::x; y = Vektor3d::y; z = Vektor3d::z;
 }
 void Ispisi() const {
 std::cout << "{" << x << "," << y << "," << z << "}";
 }
 double DajX() const { return x; }
 double DajY() const { return y; }
 double DajZ() const { return z; }
 void PostaviX(double x){
     Vektor3d::x=x;
 }
 void PostaviY(double x){
     Vektor3d::y=x;
 }
 void PostaviZ(double x){
     Vektor3d::z=x;
 }
 double DajDuzinu() const { return std::sqrt(x * x + y * y + z * z); }
Vektor3d &PomnoziSaSkalarom(double s) {
 x *= s; y *= s; z *= s;
 return *this;
 }
 Vektor3d &SaberiSa(const Vektor3d &v) {
 x += v.x; y += v.y; z += v.z;
 return *this;
 }
 friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);
};

Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2) {
 Vektor3d v3;
 v3.x = v1.x + v2.x; v3.y = v1.y + v2.y; v3.z = v1.z + v2.z;
 return v3;
}


int main ()
{
    double x,y,z;
    int b=3;
    Vektor3d a,d,c;
    a.Postavi(1,2,3);
    a.Ispisi();
    std::cout<<std::endl;
    a.PostaviX(3);
    a.PostaviY(2);
    a.PostaviZ(1);
    a.Ispisi();
    std::cout<<std::endl;
    a.Postavi(5,5,5);
    a.Ocitaj(x,y,z);
    std::cout<<x<<y<<z;
    std::cout<<std::endl;
    std::cout<<a.DajX()<<a.DajY()<<a.DajZ();
    std::cout<<std::endl;
    std::cout<<a.DajDuzinu();
    std::cout<<std::endl;
    a.PomnoziSaSkalarom(b);
    a.Ispisi();
    std::cout<<std::endl;
    d.Postavi(1,2,3);
    c=ZbirVektora(a,d);
    c.Ispisi();
    std::cout<<std::endl;
    	return 0;
}