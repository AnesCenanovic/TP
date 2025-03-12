/* 
    TP 16/17 (LV 13, Zadatak 4)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <string>
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
class Student{
    ApstraktniStudent *student;
    public:
    Student(): student(nullptr) {}
    ~Student(){delete student;}
    Student( ApstraktniStudent &ok): student(ok.DajKopiju()){}
    Student(const Student &s){
            if(!s.student) student=nullptr;
            else student=s.student->DajKopiju();
        }
    Student(Student &&s){
            student=s.student; 
            s.student=nullptr;
    }
    Student &operator=(const Student &s){
        ApstraktniStudent *novi=nullptr;
        if(s.student!=nullptr) novi=s.student->DajKopiju();
        delete student;
        student=novi;
        return *this;
    }
    Student &operator=(Student &&s){
        std::swap(student,s.student);
        return *this;
    }
    void IspisiPodatke() const {student->IspisiPodatke();}
    void RegistrirajIspit(int ocjena) {student->RegistrirajIspit(ocjena);}
    std::string DajIme() const{ return student->DajIme();}
    std::string DajPrezime() const{ return student->DajPrezime();}
    int DajBrojIndeksa() const{ return student->DajBrojIndeksa();}
    int DajBrojPolozenih() const{ return student->DajBrojPolozenih();}
    double DajProsjek() const{ return student->DajProsjek();}
    void PonistiOcjene(){student->PonistiOcjene();}
};
    
int main ()
{
	return 0;
}