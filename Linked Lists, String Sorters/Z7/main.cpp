/* 
    TP 16/17 (LV 7, Zadatak 7)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <algorithm>
#include <set>
template <typename T>
std::set<T> Unija(std::set<T> set1, std::set<T> set2){
    std::set<T> rez;
    typename std::set<T>::iterator itr;
    for (itr = set1.begin(); itr != set1.end(); itr++) {
        rez.insert(*itr);
    }
     for (itr = set2.begin(); itr != set2.end(); itr++) {
        rez.insert(*itr);
    }
    return rez;
}
template <typename T>
std::set<T> Presjek(std::set<T> set1, std::set<T> set2){
    std::set<T> rez;
    typename std::set<T>::iterator itr1,itr2;
    for (itr1 = set1.begin(); itr1 != set1.end(); itr1++) {
        for(itr2=set2.begin();itr2 !=set2.end();itr2++)
        if(*itr1==*itr2)
        rez.insert(*itr1);
    }
    for (itr2 = set2.begin(); itr2 != set2.end(); itr2++) {
        for(itr1=set1.begin();itr1 !=set1.end();itr1++)
        if(*itr2==*itr1) 
        rez.insert(*itr2);
       
    }
    return rez;
}

int main ()
{
    
	return 0;
}