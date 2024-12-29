/* 
    TP 16/17 (LV 7, Zadatak 2)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

int main ()
{
    int n;
    std::cout<<"Koliko zelite recenica: ";
    std::cin>>n;
    std::cin.clear();
    std::cin.ignore(100,'\n');
    try{
    std::cout<<"Unesite recenice: \n";
    std::string **recenice=new std::string*[n];
    for(int i = 0; i < n; i++) {
        try{
         recenice[i] = new std::string;
         std::getline(std::cin,*recenice[i]);
        }
        catch(std::bad_alloc){
        std::cout<<"Problemi s memorijom!";
        for(int j=0;j<i;j++)delete recenice[j];
            delete[] recenice;
            return 0;
        }
    }
    
    std::sort(recenice ,recenice + n,[](auto *first, auto*second){return *first<*second;});
    
    std::cout<<"Sortirane recenice: \n";
    for(int i=0;i<n;i++){
        std::cout<<*recenice[i]<<std::endl;
    }
    for(int i=0;i<n;i++)delete recenice[i];
    delete[] recenice;
    }
    catch(std::bad_alloc){
        std::cout<<"Problemi s memorijom!";
        return 0;
    }
    
	return 0;
}