
#include <iostream>
#include <vector>
#include <stdexcept>
#include <deque>
#include <new>
typedef std::vector<std::deque<int>> Matrica;

template <typename collection>
auto KreirajDinamickuKopiju2D(collection col)->decltype(col.at(0).at(0)+col.at(0).at(0))**{
    try{
        int br=0;
        for(int i=0;i<col.size();i++){
            br+=col.at(i).size();
        }
        auto mat=new decltype(&col.at(0).at(0))[col.size()];
        try{
            mat[0]=new decltype(col.at(0).at(0)+col.at(0).at(0))[br];
            for(int i=1;i<col.size();i++)
                mat[i]=mat[i-1] + col.at(i-1).size();
                for(int i=0;i<col.size();i++)
                for(int j=0;j<col.at(i).size();j++){
                    mat[i][j]=col.at(i).at(j);
                }
            }
        
        catch(...){
            delete[] mat;
            throw;
        }
        return mat;
    }
    catch(std::bad_alloc){
        throw std::bad_alloc();
    }
}

int main ()
{
    try{
        int n;
        std::cout << "Unesite broj redova kvadratne matrice: ";
        std::cin >> n;
        Matrica mat(n,std::deque<int>(n));
        std::cout << "Unesite elemente matrice: ";
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                std::cin >> mat.at(i).at(j);
            }
        }
        auto rez=KreirajDinamickuKopiju2D(mat);
         for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                std::cout << rez[i][j] << " ";
            }
            std::cout << std::endl;
        }
        delete[] rez[0];
        delete[] rez;
    }
    catch(std::bad_alloc){
        std::cout << "Nedovoljno memorije";
    }
	return 0;
}