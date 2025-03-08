/* 
    TP 16/17 (LV 11, Zadatak 3)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cstring>
#include <iomanip>
class Tim{
    char ime_tima[20];
    int broj_odigranih,broj_pobjeda,broj_poraza,broj_nerijesenih,broj_datih,broj_primljenih,broj_poena;
    public:
    Tim(const char ime[]){
        if(std::strlen(ime) > 19)
        throw std::range_error("Predugacko ime tima");
        std::strcpy(Tim::ime_tima, ime);
        broj_odigranih=0;broj_pobjeda=0;broj_poraza=0;broj_nerijesenih=0;broj_datih=0;broj_primljenih=0;broj_poena=0;
    };
    void ObradiUtakmicu(int broj_dati, int broj_primljeni){
        if(broj_dati < 0 || broj_primljeni < 0)
        throw std::range_error("Neispravan broj golova");
        if(broj_dati>broj_primljeni){
            broj_pobjeda++;
            broj_datih+=broj_dati;
            broj_primljenih+=broj_primljeni;
            broj_poena+=3;
        }
        else if(broj_dati<broj_primljeni){
            broj_poraza++;
            broj_datih+=broj_dati;
            broj_primljenih+=broj_primljeni;
        }
        else{
            broj_nerijesenih++;
            broj_datih+=broj_dati;
            broj_primljenih+=broj_primljeni;
            broj_poena+=1;
        }
        broj_odigranih++;
    }
    const char *DajImeTima() const{
        return ime_tima;
    }
    int DajBrojPoena() const{
        return broj_poena;
    };
    int DajGolRazliku() const{
        return broj_datih-broj_primljenih;
    };
    void IspisiPodatke() const{
        std::cout<<DajImeTima()<<std::setw(20-strlen(ime_tima)+4)<<broj_odigranih<<std::setw(4)<<broj_pobjeda<<std::setw(4)<<
        broj_nerijesenih<<std::setw(4)<<broj_poraza<<std::setw(4)<<broj_datih<<std::setw(4)<<broj_primljenih<<std::setw(4)<<DajBrojPoena()<<std::endl;
    };
};
int main ()
{
	return 0;
}