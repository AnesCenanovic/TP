/* 
    TP 16/17 (LV 7, Zadatak 1)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cstring>
#include <algorithm>

void sortStrings(char **arr, int n){
    char temp[1000];
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-1-i; j++)
        {
            
            if (strcmp(arr[j],arr[j+1])>0)
            {
                std::swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main ()
{
    int n;

    std::cout<<"Koliko zelite recenica: ";
    std::cin>>n;
    std::cin.clear();
    std::cin.ignore(100,'\n');
    try{
    std::cout<<"Unesite recenice: \n";
    char **recenice=new char*[n];
    for(int i = 0; i < n; i++) {
        char radni_prostor[1000];
        std::cin.getline(radni_prostor, sizeof radni_prostor);
        try{
         recenice[i] = new char[std::strlen(radni_prostor) + 1];   
        }
        catch(std::bad_alloc){
        std::cout<<"Problemi s memorijom!";
           for(int j=0;j<i;j++)
            delete[] recenice[j];
            delete[] recenice;
            return 0;
        }
        std::strcpy(recenice[i], radni_prostor);
    }
    
    sortStrings(recenice,n);
    
    std::cout<<"Sortirane recenice: \n";
    for(int i=0;i<n;i++){
        std::cout<<recenice[i]<<std::endl;
    }
    for(int i=0;i<n;i++){
        delete[] recenice[i];
    }
    delete[] recenice;
    }
    catch(std::bad_alloc){
        std::cout<<"Problemi s memorijom!";
        return 0;
    }
    
	return 0;
}