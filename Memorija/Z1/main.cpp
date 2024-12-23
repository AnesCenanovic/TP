
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <new>
#include <limits>
template <typename T>
T* GenerirajStepeneDvojke(int n){
    try{
        
        if(n<=0)
        throw std::domain_error("Broj elemenata mora biti pozitivan");
        T *rez= new T[n];
        T stepen(1);
    for(int i=0;i<n;i++){
        if(i!=0) stepen*=2;
        
        if(std::numeric_limits<T>::max()/2<stepen && i!=n-1){
            delete[] rez;
            throw std::overflow_error("Prekoracen dozvoljeni opseg");
        }
    }
        for(int i=0;i<n;i++){
            rez[i]=T(pow(2,i));
        }
        return rez;
    }
    catch(std::bad_alloc){
        throw std::runtime_error("Alokacija nije uspjela");
    }
}

int main ()
{
    try{
    int n;
    std::cout << "Koliko zelite elemenata: ";
    std::cin >> n;
    long int *niz=GenerirajStepeneDvojke<long int>(n);
    for(int i=0;i<n;i++){
        std::cout << niz[i] << " ";
    }
    delete[] niz;
    }
    catch (std::domain_error a){
        std::cout<< "Izuzetak: " << a.what();
    }
    catch (std::overflow_error b){
         std::cout<< "Izuzetak: " << b.what();
    }
    catch (std::runtime_error c){
         std::cout<< "Izuzetak: " << c.what();
    }
    catch(...){
        std::cout<< "Pogresan izuzetak!\n";
    }
        return 0;
}