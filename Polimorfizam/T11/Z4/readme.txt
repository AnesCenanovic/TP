# Klasa Kugla u C++-u

Ovaj C++ kod definira klasu `Kugla` za predstavljanje kugle u 3D prostoru.

## Značajke

* **Reprezentacija kugle:** Pohranjuje koordinate centra (x, y, z) i polumjer kugle.
* **Konstruktori:**
    * `explicit Kugla(double r = 0)`: Stvara kuglu s centrom u (0, 0, 0) i danim polumjerom. Baca `std::domain_error` ako je polumjer negativan.
    * `Kugla(double x, double y, double z, double r = 0)`: Stvara kuglu s danim centrom i polumjerom. Baca `std::domain_error` ako je polumjer negativan.
    * `explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0)`: Stvara kuglu s centrom iz `std::tuple` i danim polumjerom. Baca `std::domain_error` ako je polumjer negativan.
* **Metode:**
    * `double DajX() const`, `double DajY() const`, `double DajZ() const`: Vraća koordinate centra.
    * `std::tuple<double, double, double> DajCentar() const`: Vraća centar kugle kao `std::tuple`.
    * `double DajPoluprecnik() const`: Vraća polumjer kugle.
    * `double DajPovrsinu() const`: Vraća površinu kugle.
    * `double DajZapreminu() const`: Vraća volumen kugle.
    * `Kugla &PostaviX(double x)`, `Kugla &PostaviY(double y)`, `Kugla &PostaviZ(double z)`: Postavlja koordinate centra.
    * `Kugla &PostaviCentar(double x, double y, double z)`, `Kugla &PostaviCentar(const std::tuple<double, double, double> &centar)`: Postavlja centar kugle.
    * `Kugla &PostaviPoluprecnik(double r)`: Postavlja polumjer kugle. Baca `std::domain_error` ako je polumjer negativan.
    * `void Ispisi() const`: Ispisuje podatke o kugli.
    * `void Transliraj(double delta_x, double delta_y, double delta_z)`: Translira kuglu za date vrijednosti.
    * **Prijateljske funkcije:**
        * `DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)`: Provjerava jesu li kugle identične.
        * `DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)`: Provjerava jesu li kugle podudarne.
        * `DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)`: Provjerava jesu li kugle koncentrične.
        * `DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)`: Provjerava dodiruju li se kugle izvana.
        * `DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)`: Provjerava dodiruju li se kugle iznutra.
        * `DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)`: Provjerava preklapaju li se kugle.
        * `DaLiSeSijeku(const Kugla &k1, const Kugla &k2)`: Provjerava sijeku li se kugle.
        * `RastojanjeCentara(const Kugla &k1, const Kugla &k2)`: Računa udaljenost centara kugli.
    * `bool DaLiSadrzi(const Kugla &k) const`: Provjerava sadrži li kugla drugu kuglu.

## Korištenje

Kompajlirajte i pokrenite kod za rad s kuglama.

```bash
g++ kugla.cpp -o kugla -lm
./kugla