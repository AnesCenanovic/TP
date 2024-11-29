//TP 2020/2021: Tutorijal 2, Zadatak 2
#include <iostream>
#include <vector>
const double EPSILON=0.001;
typedef std::vector<double> vektor;

bool TestPerioda(vektor slijed, int p){
    int i=0;
    i=0;
    if(slijed.size()==2 && slijed[0]==slijed[1] && p==1)
    return true;
    if(slijed.size()<3 || slijed.size()<=p)
    return false;
    if(p>slijed.size()/2){
        for(i=0;i<slijed.size()-p;i++)
        if(slijed[i]!=slijed[i+p])
        return false;
    }
    else if (p<=slijed.size()/2){
        for(i=0;i<=p;i++)
       if(slijed[i]!=slijed[i+p]){
            return false; 
    }
    }
    return true;
}
int OdrediOsnovniPeriod(vektor slijed){
    int rez=0,i=0;
    double temp=slijed[0];
    bool flag=true;
    for(i=0;i<slijed.size();i++){
        if(temp!=slijed[i])
        flag=false;
    }
    if(flag)
    return 1;
    for(i=1;i<=slijed.size();i++){
       if(TestPerioda(slijed,i))
       rez=i;
    }
    return rez;
}
int main ()
{
    double n,p;
    vektor slijed;
    std::cout << "Unesite slijed brojeva (0 za kraj): ";
    for(;;){
        std::cin >> n;
        if(n==0)
        break;
        slijed.push_back(n);
    }
    p=OdrediOsnovniPeriod(slijed);
    if(p==0)
    std::cout << "Slijed nije periodican!";
    else
    std::cout << "Slijed je periodican sa osnovnim periodom " << p << ".";

    return 0;
}
