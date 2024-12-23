
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <new>
#include <vector>

int **KreirajTrougao(int n){
    try{
        if (n<=0) throw std::domain_error("Broj redova mora biti pozitivan");
        int **rez=new int*[n]{};
        try{
            for(int i=0;i<n;i++){
                int a=2*i+1;
                rez[i]=new int[a];
                for(int j=0; j<=a/2; j++){
                    rez[i][j]=i+1-j;
                    rez[i][a-1-j]=rez[i][j];
                }
            }
        }
        catch(...){
            for(int i=0;i<n;i++)
            delete[] rez[i];
            delete[] rez;
            throw;
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
    std::cout << "Koliko zelite redova: ";
    std::cin >> n;
    int **pok=KreirajTrougao(n);
    for(int i=0;i<n;i++){
       for(int j=0;j<2*i+1;j++){
           std::cout << pok[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for(int i=0; i<n; i++) {
        delete [] pok[i];
        }
        delete [] pok;
    }
    catch (std::bad_alloc){
        std::cout<< "Izuzetak: Nedovoljno memorije!";
    }
    catch (std::domain_error a){
        std::cout << "Izuzetak: " << a.what();
    }
        return 0;
}