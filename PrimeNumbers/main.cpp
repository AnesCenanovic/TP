//TP 2020/2021: Tutorijal 2, Zadatak 1
#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
bool DaLiJeProst(int n){
    bool flag=true;
    if(n<=1)
    return false;
    for(int i=2;i<n;i++){
        if(n % i == 0)
        {
        flag=false;
        break;
        }
    }
    if(flag)
    return true;
    else
    return false;
}
    std::vector<int> ProstiBrojeviUOpsegu(int a, int b){
    int maxi = std::numeric_limits<int>::max();
    bool flag;
    std::vector<int> prosti;
    int k=0;
    if(a==maxi || b==maxi){
        prosti.push_back(maxi);
        return prosti;
    }
    if(a<0)
    a=0;
    if(a>=100000000){
      for(int i=a;i<=b;i++){
        flag=true;
    if(i==0 || i==1)
    continue;
        for(int j=2; j<=sqrt(i); ++j){
        if(i % j == 0)
        {   
        flag=false;
        break;
            }
        }
        if(flag)
        if(flag==true) {
          prosti.push_back(i);
        } 
     }   
    }
    else{
        for(int i=a;i<=b;i++){
        flag=true;
    if(i==0 || i==1)
    continue;
        for(int j=2; j<=i/2; ++j){
        if(i % j == 0)
        {   
        flag=false;
        break;
            }
        }
        if(flag)
        if(flag==true) {
          prosti.push_back(i);
        } 
     }
    }
   
         return prosti;
    }

int main ()
{
    int a,b,i;
    std::vector<int> prosti;
    std::cout << "Unesite pocetnu i krajnju vrijednost: ";
    std::cin >> a >> b;
    prosti=ProstiBrojeviUOpsegu(a,b);
    if(prosti.size()==0){
    std::cout << "Nema prostih brojeva u rasponu od " << a << " do " << b << "!";
    return 0;    
    }
    std::cout << "Prosti brojevi u rasponu od " << a << " do " << b << " su: ";
    for(int i=0;i<prosti.size();i++){
        if(i==prosti.size()-1){
          std::cout<< prosti[i] << std::endl;
          return 0;  
        }
     std::cout<< prosti[i] << ", ";   
    }
    
    
    return 0;
}
