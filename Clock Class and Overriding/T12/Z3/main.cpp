/* 
    TP 16/17 (LV 12, Zadatak 2)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
enum Dani{Ponedjeljak,Utorak,Srijeda,Cetvrtak,Petak,Subota,Nedjelja,nedan};
std::ostream &operator <<(std::ostream &rijeka,Dani dan){
switch(dan){
case Ponedjeljak:
rijeka<<"Ponedjeljak";
break;
case Utorak:
rijeka<<"Utorak";
break;
case Srijeda:
rijeka<<"Srijeda";
break;
case Cetvrtak:
rijeka<<"Cetvrtak";
break;
case Petak:
rijeka<<"Petak";
break;
case Subota:
rijeka<<"Subota";
break;
case Nedjelja:
rijeka<<"Ponedjeljak";
break;
case nedan:
rijeka<<"lol";
break;
}
return rijeka;
}
Dani &operator ++(Dani &d){
    return d=Dani((int(d)+1)%7);
}
Dani operator ++(Dani &d,int){
    Dani temp=d;
    ++d;
    return temp;
}
Dani operator +(Dani &d,int n){
    return Dani((int(d)+n)%7);
}
int main ()
{
    for(Dani dan=Ponedjeljak;dan<nedan;dan++)
    std::cout<<dan<<std::endl;
	return 0;
}