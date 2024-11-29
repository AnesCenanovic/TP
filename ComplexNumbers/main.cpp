//TP 2020/2021: Tutorijal 2, Zadatak 3
#include <iostream>
#include <vector>
#include <complex>
#include <cmath>


int main ()
{
    typedef std::complex<double> complex;
    complex z,suma;
    double re,im,a,b;
    char c1,c2,c3;
    int n;
    std::cout << "Unesite broj elemenata: \n";
    std::cin >> n;
    for(int i=0;i<n;i++){
    std::cout << "Z_" << i+1 << " = ";
    std::cin >> c1 >> re >> c2 >> im >> c3;
    z.real(re);
    z.imag(im);
    if(re==0 && im==0){
        std::cout << "\nParalelna veza ovih elemenata ima impedansu Z_ = (" << 0 <<","<< 0 <<").";
        return 0;
    }
    suma+=conj(z)/(re*re+im*im);
    }
    suma=conj(suma)/(suma.real()*suma.real()+suma.imag()*suma.imag());
    std::cout << "\nParalelna veza ovih elemenata ima impedansu Z_ = (" << suma.real() <<","<<suma.imag()<<").";
    return 0;
}
