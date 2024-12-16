//TP 2021/2022: LV 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <limits>

int Cifre(long long int n,int &c_min, int &c_max){
    int ostatak,min_temp=0,max_temp=0,br=0;
    n=std::abs(n);
    if(n==0){
    c_min=0;
    c_max=0;
    return 1;
    }
    if(n==std::numeric_limits<long long int>::min()){
    c_min=0;
    c_max=9;
    return 19;
    }
    while(n>0){
        ostatak=n%10;
        n=n/10;
        br++;
        if(br==1){
            min_temp=ostatak;
            max_temp=ostatak;
        }
        if(min_temp>ostatak)
        min_temp=ostatak;
        if(max_temp<ostatak)
        max_temp=ostatak;
    }
    c_min=min_temp;
    c_max=max_temp;
    return br;
}

int main ()
{
    long long int a;
    int b,c,d;
    std::cout << "Unesite broj: ";
    std::cin >> a;
    d=Cifre(a,b,c);
    std::cout << "Broj "<< a << " ima "<< d << " cifara, najveca je "<< c << " a najmanja " << b << ".";
	return 0;
}
