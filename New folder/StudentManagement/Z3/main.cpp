/* 
    TP 16/17 (LV 13, Zadatak 3)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <vector>
class ApstraktniStudent{
    std::string ime,prezime;
    int index;
    int ispit;
    double prosjek;
    public:
    ApstraktniStudent(std::string ime,std::string prezime, int i): ime(ime),prezime(prezime),index(i),ispit(0),prosjek(5){}
    virtual ~ApstraktniStudent(){}
    std::string DajIme() const{ return ime;}
    std::string DajPrezime() const{ return prezime;}
    int DajBrojIndeksa() const{ return index;}
    int DajBrojPolozenih() const{ return ispit;}
    double DajProsjek() const{ return prosjek;}
    void RegistrirajIspit(int ocjena){
        if(ocjena <5 || ocjena >10) throw std::domain_error("Neispravna ocjena");
        else if(ocjena>5 && ocjena<=10){
            if(prosjek==5.){
                ispit++;
                prosjek=double(ocjena);
            }
            else{
                ispit++;
                prosjek=(prosjek*(ispit-1)+ocjena)/ispit;
            }
        }
    }
    void PonistiOcjene(){
        ispit=0;
        prosjek=5;
    }
    virtual void IspisiPodatke() const {}
    virtual ApstraktniStudent *DajKopiju(){ return new ApstraktniStudent(*this);}
    };
    bool Kriterij(ApstraktniStudent *s1,ApstraktniStudent *s2){
        if(s1->DajProsjek()>s2->DajProsjek()) return true;
        else if(s1->DajProsjek()==s2->DajProsjek() && s1->DajBrojIndeksa()<s2->DajBrojIndeksa()) return true;
        return false;
    }
class StudentBachelor: public ApstraktniStudent{
        public:
    StudentBachelor(std::string ime, std::string prezime, int index): ApstraktniStudent(ime,prezime,index){}
    void IspisiPodatke() const override{
        std::cout<<" Student bachelor studija " <<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()
        <<",\nima prosjek "<<DajProsjek()<<"."<<std::endl;
    }
    ApstraktniStudent *DajKopiju()override{ return new StudentBachelor(*this);}
    };
class StudentMaster: public ApstraktniStudent{
    int godina_dipl;
    public:
    StudentMaster(std::string ime, std::string prezime, int index,int a): ApstraktniStudent(ime,prezime,index),godina_dipl(a){}
    void IspisiPodatke() const override{
        std::cout<<" Student master studija " <<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()
        <<",\nzavrsio bachelor studij godine "<<godina_dipl<<",ima prosjek "<<DajProsjek()<<"."<<std::endl;
    }
    ApstraktniStudent *DajKopiju()override{ return new StudentMaster(*this);}
    };
    class Fakultet{
        mutable std::vector<ApstraktniStudent*> vec;
        public:
            Fakultet()=default;
            ~Fakultet(){for(int i=0;i<vec.size();i++) delete vec[i];}
            Fakultet(const Fakultet &f){
                for(int i=0;i<f.vec.size();i++){
                   vec.push_back(f.vec[i]->DajKopiju());
                }
            }
             Fakultet &operator=(const Fakultet &f){
                 if(&f!=this){
                     for(int i=0;i<vec.size();i++) delete vec[i];
                     while(vec.size()!=0) vec.erase(vec.begin());
                 }
                for(int i=0;i<f.vec.size();i++){
                   vec.push_back(f.vec[i]->DajKopiju());
                }
                return *this;
            }
            Fakultet (Fakultet && f)=default;
            Fakultet &operator=(const Fakultet &&f){
                 if(&f!=this){
                     for(int i=0;i<vec.size();i++) delete vec[i];
                     while(vec.size()!=0) vec.erase(vec.begin());
                     std::swap(vec,f.vec);
                }
                return *this;
            }
    
            void UpisiStudenta(std::string ime,std::string prezime, int index){
                for(int i=0;i<vec.size();i++){
                    if(vec[i]->DajBrojIndeksa()==index) throw std::domain_error ("Student sa zadanim brojem indeksa vec postoji");
                }
                vec.push_back(new StudentBachelor(ime,prezime,index));
            }
             void UpisiStudenta(std::string ime,std::string prezime, int index,int godina){
                for(int i=0;i<vec.size();i++){
                    if(vec[i]->DajBrojIndeksa()==index) throw std::domain_error ("Student sa zadanim brojem indeksa vec postoji");
                }
                vec.push_back(new StudentMaster(ime,prezime,index,godina));
            }
            void ObrisiStudenta(int index){
                bool deleted=false;
                for(int i = 0; i < vec.size(); i++){
                    if(vec[i]->DajBrojIndeksa()==index){
                        deleted=true;
                        delete vec[i];
                        vec.erase(vec.begin()+i);
                        break;
                    }
                    if(!deleted) throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
                }
            }
            ApstraktniStudent &operator [](int index) const{
                bool postoji=false;
                int a;
                 for(int i = 0; i < vec.size(); i++){
                    if(vec[i]->DajBrojIndeksa()==index){
                        postoji=true;
                        a=i;
                        break;
                    }
                 }
                    if(!postoji) throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
                    return *vec[a];
            }
            void IspisiSveStudente() const{
                std::sort(vec.begin(),vec.end(),Kriterij);
                for(auto x:vec) x->IspisiPodatke();
            }
    }; 
int main ()
{
	return 0;
}