/* 
    TP 16/17 (LV 7, Zadatak 6)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <list>
template <typename T>
void SortirajListu(std::list<T> &lista){
    std::list<T> rez;
    typename std::list<T>::iterator it1,it2;
    for(it1=lista.begin();it1!=lista.end();it1++){
        it2=rez.begin();
        while(it2!=rez.end() && *it2<*it1) it2++;
        rez.insert(it2,*it1);
    }
    lista=rez;
}
int main ()
{
    std::list<int> test;
    int n,a;
    std::cout<<"Koliko ima elemenata: ";
    std::cin>>n;
    std::cout<<"Unesite elemente: ";
    for(int i=0;i<n;i++){
        std::cin>>a;
        test.push_back(a);
    }
    SortirajListu(test);
    std::cout<<"Sortirana lista: ";
    for(int i=0;i<n;i++){
        std::cout << test.front() << " ";
        test.pop_front();
    }

    
	return 0;
}