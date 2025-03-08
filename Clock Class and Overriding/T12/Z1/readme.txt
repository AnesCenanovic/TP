# Klasa Sat u C++-u

Ovaj C++ kod definira klasu `Sat` koja predstavlja vrijeme u formatu sati, minuta i sekundi.

## Značajke

* **Reprezentacija vremena:** Pohranjuje sate, minute i sekunde kao cjelobrojne vrijednosti.
* **Konstruktori:**
    * `Sat()`: Stvara sat s početnim vremenom 00:00:00.
    * `Sat(int a, int b, int c)`: Stvara sat s danim satima, minutama i sekundama. Normalizira vrijeme ako su vrijednosti izvan raspona.
* **Statičke metode:**
    * `static bool DaLiJeIspravno(int a, int b, int c)`: Provjerava je li dano vrijeme ispravno.
* **Metode:**
    * `void Postavi(int a, int b, int c)`: Postavlja vrijeme na dane vrijednosti. Baca `std::domain_error` ako je vrijeme neispravno.
    * `void PostaviNormalizirano(int a, int b, int c)`: Postavlja vrijeme na dane vrijednosti i normalizira ga.
    * `Sat &Sljedeci()`: Povećava vrijeme za jednu sekundu.
    * `Sat &Prethodni()`: Smanjuje vrijeme za jednu sekundu.
    * `Sat PomjeriZa(int sek)`: Pomjera vrijeme za dani broj sekundi.
    * `void Ispisi() const`: Ispisuje vrijeme u formatu HH:MM:SS.
    * `static int Razmak(Sat a, Sat b)`: Vraća razliku u sekundama između dva sata.
    * `double DajSate() const`, `double DajMinute() const`, `double DajSekunde() const`: Vraća pojedinačne komponente vremena.
* **Preopterećeni operatori:**
    * `++` (prefiksni i postfiksni): Povećava vrijeme za jednu sekundu.
    * `--` (prefiksni i postfiksni): Smanjuje vrijeme za jednu sekundu.
    * `+=`, `-=`: Dodaje ili oduzima sekunde od sata.
    * `<<`: Ispisuje sat pomoću `std::ostream`.
    * `+`, `-` (s int): Dodaje ili oduzima sekunde od sata.
    * `+`, `-` (s Sat): Vraća razliku u sekundama između dva sata.
* **Prijateljska funkcija:**
    * `int BrojSekundiIzmedju(Sat s1, Sat s2)`: Vraća razliku u sekundama između dva sata.

## Korištenje

Kompajlirajte i pokrenite kod za rad s objektima klase `Sat`.

```bash
g++ sat.cpp -o sat -lm
./sat