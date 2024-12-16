//TP 2021/2022: LV 4, Zadatak 2
#include <iostream>
#include <cmath>

void IzvrniString(std::string &recenica){
    int a=recenica.size();
    for(int i=recenica.size()-1;i>=0;i--)
    recenica.push_back(recenica.at(i));
    recenica.erase(0,a);
}


int main ()
{
    std::string recenica;
    std::cout<<"Unesi string: ";
    std::cin >> recenica;
    IzvrniString(recenica);
    std::cout << "Izvrnuti string je: " << recenica;
	return 0;
}
