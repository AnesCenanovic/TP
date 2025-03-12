/* 
    TP 16/17 (LV 13, Zadatak 1)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
class Lik{
    public:
    virtual ~Lik(){}
    virtual void IspisiSpecificnosti() const { std::cout<<"Lik";}
    virtual double DajObim() const {return 0;}
    virtual double DajPovrsinu() const { return 0;}
    virtual void Ispisi() const{
        IspisiSpecificnosti();
        std::cout<<"Obim: "<<DajObim();
        std::cout<<" Povrsina: "<<DajPovrsinu()<<std::endl;
    }
};
class Pravougaonik:public Lik{
    double a,b;
    public:
    Pravougaonik(double x,double y): a(x),b(y){
        if(x<=0 || b<=0) throw std::domain_error("Neispravni parametri");
    }
    void IspisiSpecificnosti() const override { std::cout<<"Pravougaonik sa stranicama duzine "<<a<<" i "<<b<<std::endl;}
    double DajObim() const override{return 2*a+2*b;}
    double DajPovrsinu() const override{ return a*b;}
};
class Krug:public Lik{
    double r;
    const double pi=4*atan(1);
    public:
    Krug(double poluprecnik): r(poluprecnik){
        if(poluprecnik<=0) throw std::domain_error("Neispravni parametri");
    }
    void IspisiSpecificnosti() const override { std::cout<<"Krug poluprecnika "<<r<<std::endl;}
    double DajObim() const override{return 2*r*pi;}
    double DajPovrsinu() const override{ return r*r*pi;}
};
class Trougao:public Lik{
    double a,b,c;
    public:
    Trougao(double x,double y,double z): a(x),b(y),c(z){
        if(x+y<=z || y+z<=x || z+x<=y || x-y>=z || y+z<=x || x-z>=y || y-x>=z || z-x>=y || z-y>=x || y-z>=x) throw std::domain_error("Neispravni parametri");
    }
    void IspisiSpecificnosti() const override { std::cout<<"Trougao sa stranicama duzine "<<a<<", "<<b<<" i "<<c<<std::endl;}
    double DajObim() const override{return a+b+c;}
    double DajPovrsinu() const override{ double s=(a+b+c)/2; return std::sqrt(s*(s-a)*(s-b)*(s-c));}
};
int main ()
{
    std::vector<std::shared_ptr<Lik>> vec;
    int n;
    std::cout<<"Koliko zelite likova: ";
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cout<<"Lik "<<i+1<<": ";
        char a;
        std::cin>>a;
        if(a=='P'){
            double a,b; char c;
            std::cin>>a>>c>>b;
        
            if(std::cin && std::cin.peek()=='\n'){
                try{
                    vec.push_back(std::make_shared<Pravougaonik>(a,b));
                }
                catch(...){
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Pogresni podaci, ponovite unos!\n";
                    i--;
            }
            }
            else{
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Pogresni podaci, ponovite unos!\n";
                    i--;
            }
        }
              else if(a=='K'){
            double r;
            std::cin>>r;
            if(std::cin && std::cin.peek()=='\n'){
                try{
                    vec.push_back(std::make_shared<Krug>(r));
                }
                catch(...){
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Pogresni podaci, ponovite unos!\n";
                    i--;
            }
            }
            else{
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Pogresni podaci, ponovite unos!\n";
                    i--;
            }
              }
              else if(a=='T'){
            double a,b,c; char e,d;
            std::cin>>a>>e>>b>>d>>c;
            if(std::cin && std::cin.peek()=='\n'){
                try{
                    vec.push_back(std::make_shared<Trougao>(a,b,c));
                }
                catch(...){
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Pogresni podaci, ponovite unos!\n";
                    i--;
            }
            }
            else{
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Pogresni podaci, ponovite unos!\n";
                    i--;
            }
              }
                else{
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Pogresni podaci, ponovite unos!\n";
                    i--;
            }
    }
    for(auto x: vec) x->Ispisi();
	return 0;
}