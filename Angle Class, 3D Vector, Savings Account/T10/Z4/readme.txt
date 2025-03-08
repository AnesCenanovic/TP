# Klasa Ugao u C++-u

Ovaj C++ kod definira klasu `Ugao` koja predstavlja kut. Klasa omogućuje rad s kutovima u radijanima i klasičnim jedinicama (stupnjevi, minute, sekunde).

## Značajke

* **Reprezentacija kuta:** Unutarnje pohranjuje kut u radijanima.
* **Konstruktori:**
    * `Ugao(double radijani = 0)`: Stvara kut iz radijana.
    * `Ugao(int stepeni, int minute, int sekunde)`: Stvara kut iz klasičnih jedinica.
* **Postavljanje vrijednosti:**
    * `Postavi(double radijani)`: Postavlja kut iz radijana.
    * `Postavi(int stepeni, int minute, int sekunde)`: Postavlja kut iz klasičnih jedinica.
* **Dobavljanje vrijednosti:**
    * `DajRadijane() const`: Vraća kut u radijanima
    * `OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde)`: Dobavlja kut u klasičnim jedinicama.
    * `DajStepene() const`, `DajMinute() const`, `DajSekunde() const`: Dobavlja pojedinačne komponente kuta.
* **Ispis:**
    * `Ispisi() const`: Ispisuje kut u radijanima.
    * `IspisiKlasicno() const`: Ispisuje kut u klasičnim jedinicama.
* **Operacije:**
    * `SaberiSa(const Ugao &u)`: Zbraja kut s drugim kutom.
    * `PomnoziSa(double x)`: Množi kut sa skalarom.
    * `ZbirUglova(const Ugao &u1, const Ugao &u2)`: Funkcija prijatelj koja zbraja dva kuta.
    * `ProduktUglaSaBrojem(const Ugao &u, double x)`: Funkcija prijatelj koja množi kut sa skalarom.

## Korištenje

Kompajlirajte i pokrenite kod za rad s kutovima.

```bash
g++ ugao.cpp -o ugao -lm
./ugao