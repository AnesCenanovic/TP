/* 
    TP 16/17 (LV 12, Zadatak 2)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <set>
#include <utility>
template <typename T>
bool JeLiPrazan(std::set<T> a,std::set<T> b){
    auto it1=a.begin();
    auto it2=b.begin();
    while(it1!=a.end() && it2!=b.end()){
        if(*it1==*it2) return false;
        else if(*it1<*it2) it1++;
        else it2++;
    }
    return true;
}
template <typename T>
std::set<T> operator+(std::set<T> a,std::set<T> b){
    std::set<T> rez=a;
    auto it=b.begin();
    while(it!=b.end()){
        rez.insert(*it);
        it++;
    }
    return rez;
}
template <typename T>
std::set<T> operator*(std::set<T> a,std::set<T> b){
    std::set<T> rez{};
    if(JeLiPrazan(a,b)) return rez;
    auto it1=a.begin();
    auto it2=b.begin();
    while(it1!=a.end() && it2!=b.end()){
        if(*it1==*it2){
            rez.insert(*it1);
            it1++;
            it2++;
        }
        else if(*it1<*it2) it1++;
        else it2++;
    }
    return rez;
}
template <typename a, typename b>
std::ostream &operator <<(std::ostream &rijeka, std::pair<a, b> par){
    rijeka<<"("<<par.first<<","<<par.second<<")";
    return rijeka;
}
template <typename T>
std::ostream &operator <<(std::ostream &rijeka, std::set<T> set){
    rijeka<<"{";
    if(set.size()==0){
        rijeka<<"}";
        return rijeka;
    }
    auto it=set.begin();
    rijeka<<*it;
    it++;
    for(auto it1=it;it1!=set.end();it1++)
    rijeka<<","<<*it1;
    rijeka<<"}"<<std::endl;
    return rijeka;
}
template <typename T>
std::set<T> operator +=( std::set<T> &a, const std::set<T> &b){
    return a=a+b;
}
template <typename T>
std::set<T> operator *=( std::set<T> &a, const std::set<T> &b){
    return a=a*b;
}
template <typename a, typename b>
std::set<std::pair<a,b>> operator%(std::set<a> x, std::set<b> y){
    std::set<std::pair<a,b>> rez;
    auto it=x.begin();
    while(it!=x.end()){
        auto it1=y.begin();
        while(it1!=y.end()){
            std::pair<a,b> lol;
            lol.first=*it;
            lol.second=*it1;
            rez.insert(lol);
            it1++;
        }
        it++;
    }
    return rez;
}
int main ()
{
    
	return 0;
}