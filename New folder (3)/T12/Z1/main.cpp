/* 
    TP 16/17 (LV 12, Zadatak 1)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <stdexcept>
class Sat{
    int hour,minute,second;
    public:
    Sat(){hour=0;minute=0;second=0;}
    Sat(int a,int b,int c){
        if(c>59){
            b=b+c/60; 
            c=c%60;
        }
        else if(c<0){
            double nec=-c;
            b=b-ceil(nec/60);
            c=60+c%60;
        }
         if(b>59){
            a=a+b/60; 
            b=b%60;
        }
        else if(b<0){
            double neb=-b;
            a=a-ceil(neb/60);
            b=60+b%60;
        }
         if(a>23){ 
            a=a%24;
        }
        else if(a<0){
        
            a=24+a%24;
        }
        Sat::hour=a;Sat::minute=b;Sat::second=c;
    }
    static bool DaLiJeIspravno(int a,int b,int c){
        if(a<0 || a>23){
            return false;
        }
          if(b<0 || a>59){
            return false;
        }
         if(c<0 || c>59){
            return false;
        }
        return true;
    }
    void Postavi(int a,int b,int c){
        if(!DaLiJeIspravno(a,b,c)) throw std::domain_error("Neispravno vrijeme");
        Sat::hour=a;Sat::minute=b;Sat::second=c;
    }
    void PostaviNormalizirano(int a,int b,int c){
        if(c>59){
            b=b+c/60; 
            c=c%60;
        }
        else if(c<0){
            double nec=-c;
            b=b-ceil(nec/60);
            c=60+c%60;
        }
         if(b>59){
            a=a+b/60; 
            b=b%60;
        }
        else if(b<0){
            double neb=-b;
            a=a-ceil(neb/60);
            b=60+b%60;
        }
         if(a>23){ 
            a=a%24;
        }
        else if(a<0){
            
            a=24+a%24;
        }
        Sat::hour=a;Sat::minute=b;Sat::second=c;
    }
    Sat &Sljedeci(){
        second++;
        if(second>59){
            minute=minute+second/60; second=second%60;
        }
         if(minute>59){
            hour=hour+minute/60; minute=minute%60;
        }
        if(hour>23){
            hour=hour%24;
        }
        return *this;
    }
      Sat &Prethodni(){
        second--;
        if(second>59){
            minute=minute+second/60; 
            second=second%60;
        }
        else if(second<0){
            double nec=-second;
            minute=minute-ceil(nec/60);
            second=60+second%60;
        }
         if(minute>59){
            hour=hour+minute/60; 
            minute=minute%60;
        }
        else if(minute<0){
            double neb=-minute;
            hour=hour-ceil(neb/60);
            minute=60+minute%60;
        }
         if(hour>23){ 
            hour=hour%24;
        }
        else if(hour<0){ 
            hour=24+hour%24;
        }
        return *this;
    }
    Sat PomjeriZa(int sek){
        second+=sek;
         if(second>59){
            minute=minute+second/60; 
            second=second%60;
        }
        else if(second<0){
            double nec=-second;
            minute=minute-ceil(nec/60);
            second=60+second%60;
        }
         if(minute>59){
            hour=hour+minute/60; 
            minute=minute%60;
        }
        else if(minute<0){
            double neb=-minute;
            hour=hour-ceil(neb/60);
            minute=60+minute%60;
        }
         if(hour>23){ 
            hour=hour%24;
        }
        else if(hour<0){ 
            hour=24+hour%24;
        }
        return *this;
    }
    void Ispisi() const{
        if(hour<10) std::cout<<"0";
        std::cout<<hour<<":";
        if(minute<10) std::cout<<"0";
        std::cout<<minute<<":";
        if(second<10) std::cout<<"0";
        std::cout<<second<<":";
        std::cout<<std::endl;
    }
    static int Razmak(Sat a,Sat b){
        int x=a.hour-b.hour,y=a.minute-b.minute,z=a.second-b.second;
        int rez=z+y*60+x*60*60;
        return rez;
    }
    double DajSate() const { return hour; }
    double DajMinute() const { return minute; }
    double DajSekunde() const { return second; }
    friend Sat &operator ++(Sat &s);
    friend Sat operator ++(Sat &s, int);
    friend Sat &operator --(Sat &s);
    friend Sat operator --(Sat &s, int);
    friend Sat &operator +=(Sat &s, int n);
    friend Sat &operator -=(Sat &s, int n);
    friend std::ostream &operator <<(std::ostream &rijeka, const Sat &s);
    friend Sat operator +(const Sat &s1, int n);
    friend Sat operator -(const Sat &s1, int n);
    friend int operator +(const Sat &s1, const Sat &s2);
    friend int operator -(const Sat &s1, const Sat &s2);
};
Sat &operator ++(Sat &s){
    s.second++;
    if(s.second>59){
            s.minute=s.minute+s.second/60; s.second=s.second%60;
        }
         if(s.minute>59){
            s.hour=s.hour+s.minute/60; s.minute=s.minute%60;
        }
        if(s.hour>23){
            s.hour=s.hour%24;
        }
    return s;
}
Sat operator ++(Sat &s, int){
    Sat temp=s;
    s.second++;
    return temp;
}
Sat &operator --(Sat &s){
    s.second--;
    if(s.second>59){
            s.minute=s.minute+s.second/60; 
            s.second=s.second%60;
        }
        else if(s.second<0){
            double nec=-s.second;
            s.minute=s.minute-ceil(nec/60);
            s.second=60+s.second%60;
        }
         if(s.minute>59){
            s.hour=s.hour+s.minute/60; 
            s.minute=s.minute%60;
        }
        else if(s.minute<0){
            double neb=-s.minute;
            s.hour=s.hour-ceil(neb/60);
            s.minute=60+s.minute%60;
        }
         if(s.hour>23){ 
            s.hour=s.hour%24;
        }
        else if(s.hour<0){ 
            s.hour=24+s.hour%24;
        }
    return s;
}
Sat operator --(Sat &s, int){
    Sat temp=s;
    s.second--;
    return temp;
}
Sat &operator +=(Sat &s, int n){
    s.second+=n;
    if(s.second>59){
            s.minute=s.minute+s.second/60; 
            s.second=s.second%60;
        }
        else if(s.second<0){
            double nec=-s.second;
            s.minute=s.minute-ceil(nec/60);
            s.second=60+s.second%60;
        }
         if(s.minute>59){
            s.hour=s.hour+s.minute/60; 
            s.minute=s.minute%60;
        }
        else if(s.minute<0){
            double neb=-s.minute;
            s.hour=s.hour-ceil(neb/60);
            s.minute=60+s.minute%60;
        }
         if(s.hour>23){ 
            s.hour=s.hour%24;
        }
        else if(s.hour<0){ 
            s.hour=24+s.hour%24;
        }
    return s;
}
Sat &operator -=(Sat &s, int n){
    s+=-n;
    return s;
}
std::ostream &operator <<(std::ostream &rijeka, const Sat &s){
       if(s.hour<10) rijeka<<"0";
        rijeka<<s.hour<<":";
        if(s.minute<10) rijeka<<"0";
        rijeka<<s.minute<<":";
        if(s.second<10) rijeka<<"0";
        rijeka<<s.second<<std::endl;
        return rijeka;
}
Sat operator +(const Sat &s1, int n){
    Sat temp=s1;
    temp.second+=n;
    if(temp.second>59){
            temp.minute=temp.minute+temp.second/60; 
            temp.second=temp.second%60;
        }
        else if(temp.second<0){
            double nec=-temp.second;
            temp.minute=temp.minute-ceil(nec/60);
            temp.second=60+temp.second%60;
        }
         if(temp.minute>59){
            temp.hour=temp.hour+temp.minute/60; 
            temp.minute=temp.minute%60;
        }
        else if(temp.minute<0){
            double neb=-temp.minute;
            temp.hour=temp.hour-ceil(neb/60);
            temp.minute=60+temp.minute%60;
        }
         if(temp.hour>23){ 
            temp.hour=temp.hour%24;
        }
        else if(temp.hour<0){ 
            temp.hour=24+temp.hour%24;
        }
        return temp;
}
Sat operator -(const Sat &s1, int n){
    Sat temp=s1;
    temp.second-=n;
    if(temp.second>59){
            temp.minute=temp.minute+temp.second/60; 
            temp.second=temp.second%60;
        }
        else if(temp.second<0){
            double nec=-temp.second;
            temp.minute=temp.minute-ceil(nec/60);
            temp.second=60+temp.second%60;
        }
         if(temp.minute>59){
            temp.hour=temp.hour+temp.minute/60; 
            temp.minute=temp.minute%60;
        }
        else if(temp.minute<0){
            double neb=-temp.minute;
            temp.hour=temp.hour-ceil(neb/60);
            temp.minute=60+temp.minute%60;
        }
         if(temp.hour>23){ 
            temp.hour=temp.hour%24;
        }
        else if(temp.hour<0){ 
            temp.hour=24+temp.hour%24;
        }
        return temp;
}
int operator +(const Sat &s1, const Sat &s2){
     int x=s1.hour+s2.hour,y=s1.minute+s2.minute,z=s1.second+s2.second;
        int rez=z+y*60+x*60*60;
        return rez;
}
int operator -(const Sat &s1, const Sat &s2){
     int x=s1.hour-s2.hour,y=s1.minute-s2.minute,z=s1.second-s2.second;
        int rez=z+y*60+x*60*60;
        return rez;
}
int BrojSekundiIzmedju(Sat s1,Sat s2){
     int x=s1.DajSate()-s2.DajSate(),y=s1.DajMinute()-s2.DajMinute(),z=s1.DajSekunde()-s2.DajSekunde();
        int rez=z+y*60+x*60*60;
        return rez;
}
int main ()
{
	return 0;
}
