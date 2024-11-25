
#include <iostream>
#include <cmath>
int main ()
{
    double a,b,c,m,deg,sec,mins;
    double pi=4*std::atan(1);
    bool check;
    std::cout << "Unesite tri broja: ";
    std::cin >> a >> b >> c;
    if(a>=0 && b>=0 && c>=0 && (a+b>c) && (b+c>a) && (c+a>b))
    check=true;
    else 
    check=false;
    if(check){
        double s=(a+b+c)/2;
        double P=std::sqrt(s*(s-a)*(s-b)*(s-c));
        std::cout << "Obim trougla sa duzinama stranica " << a << ", " << b << " i " << c << " iznosi " << a+b+c << "." << std::endl;
        std::cout << "Njegova povrsina iznosi " << P << "." << std::endl;
        if(a<b && a<c)
        m=a;
        else if(b<a && b<c)
        m=b;
        else if(c<b && c<a)
        m=c;
        else if ((a==b && a==c) && (b==a && b==c) && (c==b && c==a)) {
            std::cout << "Njegov najmanji ugao ima " << 60 << " stepeni, " << 0 << " minuta i " << 0 << " sekundi.";
            return 0;
        }
        else if(a==b){
          std::cout << "Njegov najmanji ugao ima " << 45 << " stepeni, " << 0 << " minuta i " << 0 << " sekundi.";
            return 0;  
        }
        if(m==a){
            deg=std::acos((c*c+b*b-a*a)/(2*b*c));
            deg=deg*(180/pi);
            mins=(deg-floor(deg))*60;
            sec=(mins-floor(mins))*60;
            std::cout << "Njegov najmanji ugao ima " << floor(deg) << " stepeni, " << floor(mins) << " minuta i " << floor(sec) << " sekundi.";
            return 0;
        }
        else if(m==b){
            deg=std::acos((c*c+a*a-b*b)/(2*c*a));
            deg=deg*(180/pi);
            mins=(deg-floor(deg))*60;
            sec=(mins-floor(mins))*60;
            std::cout << "Njegov najmanji ugao ima " << floor(deg) << " stepeni, " << floor(mins) << " minuta i " << floor(sec) << " sekundi.";
            return 0;

        }
        else if(m==c){
            deg=std::acos((a*a+b*b-c*c)/(2*b*a));
            deg=deg*(180/pi);
            mins=(deg-floor(deg))*60;
            sec=(mins-floor(mins))*60;

            std::cout << "Njegov najmanji ugao ima " << floor(deg) << " stepeni, " << floor(mins) << " minuta i " << floor(sec) << " sekundi.";
            return 0;

        }
        
    }
    else{
        std::cout << "Ne postoji trougao cije su duzine stranica " << a << ", " << b << " i " << c << "!";
        return 0;
    }
	return 0;
}