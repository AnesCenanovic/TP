//TP 2021/2022: LV 4, Zadatak 4
#include <iostream>
#include <cmath>



template <class myType>
myType UnosBroja (std::string msg, std::string error, myType &a) {
 while(true){
    std::cout << msg;
    if(std::cin >> a && std::cin.peek()==10){
        break;
    }
        else{
        std::cout << error << std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');    
        }
 }
 std::cin.clear();
 std::cin.ignore(10000,'\n');
 return 1;
}

int main ()
{
    int a;
    double rez=1;
    double prvi_broj;
    int drugi_broj;
    
    UnosBroja("Unesite bazu: ", "Neispravan unos, pokusajte ponovo...\n", prvi_broj);
    UnosBroja("Unesite cjelobrojni eksponent: ", "Neispravan unos, pokusajte ponovo...\n", drugi_broj);
    if(drugi_broj==0)
    std::cout << prvi_broj << " na " << drugi_broj << " iznosi " << 1;
    else if(drugi_broj>0){
        for(int i=0;i<drugi_broj;i++)
        rez*=prvi_broj;
     std::cout << prvi_broj << " na " << drugi_broj << " iznosi " << rez;    
    }
    else if(drugi_broj<0){
        for(int i=0;i<abs(drugi_broj);i++)
        rez*=prvi_broj;
     std::cout << prvi_broj << " na " << drugi_broj << " iznosi " << (1/rez);    
    }
    

   
	return 0;
}
