
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <new>
#include <vector>
template <typename T>
auto KreirajIzvrnutiNiz(T pocetak, T kraj) ->decltype(&*pocetak){
    try{
        int br=0;
        T temp=pocetak;
        auto a=*pocetak;
        while(temp!=kraj){
            br++;
            temp++;
        }
        decltype(&*pocetak) rez= new decltype(a)[br];
        for(int i=br-1;i>=0;i--){
           rez[i]=*pocetak;
           pocetak++;
        }
        return rez;
    }
    catch(std::bad_alloc){
        throw std::bad_alloc();
    }
}
int main ()
{
    try{
    int n;
    std::vector<double> niz;
    std::cout << "Koliko zelite elemenata: ";
    std::cin >> n;
    niz.resize(n);
    std::cout << "Unesite elemente: ";
    for(int i=0;i<n;i++){
        std::cin >> niz.at(i);
    }
    double *rez=KreirajIzvrnutiNiz(niz.begin(),niz.end());
    std::cout << "Kreirani niz: ";
     for(int i=0;i<n;i++){
        std::cout << rez[i] << " ";
    }
    delete[] rez;
    }
    catch (std::bad_alloc){
        std::cout<< "Nedovoljno memorije!";
    }
        return 0;
}