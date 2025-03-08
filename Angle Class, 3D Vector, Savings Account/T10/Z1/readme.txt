# Klasa StedniRacun u C++-u

Ovaj C++ kod definira klasu `StedniRacun` koja predstavlja štedni račun.

## Značajke

* **Reprezentacija stanja:** Unutarnje pohranjuje stanje računa kao `double` vrijednost.
* **Konstruktori:**
    * `StedniRacun()`: Stvara štedni račun s početnim stanjem 0.
    * `StedniRacun(double x)`: Stvara štedni račun s početnim stanjem `x`. Baca `std::logic_error` ako je početno stanje negativno.
* **Metode:**
    * `void Ulozi(double x)`: Uplaćuje `x` na račun. Baca `std::logic_error` ako se pokušava podići više novca nego što je na računu.
    * `void Podigni(double x)`: Podiže `x` s računa. Baca `std::logic_error` ako nema dovoljno novca na računu.
    * `double DajStanje() const`: Vraća trenutno stanje računa.
    * `void ObracunajKamatu(double x)`: Obračunava kamatu na račun koristeći kamatnu stopu `x`. Baca `std::logic_error` ako je kamatna stopa negativna.

## Korištenje

Kompajlirajte i pokrenite kod za rad sa štednim računima.

```bash
g++ stedni_racun.cpp -o stedni_racun -lm
./stedni_racun