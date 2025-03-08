# Klasa Tim u C++-u

Ovaj C++ kod definira klasu `Tim` za predstavljanje nogometnog tima.

## Značajke

* **Reprezentacija tima:** Pohranjuje ime tima, broj odigranih utakmica, broj pobjeda, poraza, neriješenih utakmica, broj datih i primljenih golova te broj poena.
* **Konstruktor:**
    * `Tim(const char ime[])`: Stvara tim s danim imenom. Baca `std::range_error` ako je ime predugačko (više od 19 znakova).
* **Metode:**
    * `void ObradiUtakmicu(int broj_dati, int broj_primljeni)`: Ažurira podatke tima nakon odigrane utakmice. Baca `std::range_error` ako je broj golova negativan.
    * `const char *DajImeTima() const`: Vraća ime tima.
    * `int DajBrojPoena() const`: Vraća broj poena tima.
    * `int DajGolRazliku() const`: Vraća gol razliku tima.
    * `void IspisiPodatke() const`: Ispisuje podatke o timu u formatiranom obliku.

## Korištenje

Kompajlirajte i pokrenite kod za rad s timovima.

```bash
g++ tim.cpp -o tim
./tim