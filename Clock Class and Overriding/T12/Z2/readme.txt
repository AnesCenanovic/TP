# Operacije nad skupovima u C++-u

Ovaj C++ kod definira nekoliko template funkcija za rad sa skupovima (`std::set`).

## Značajke

* **`JeLiPrazan(std::set<T> a, std::set<T> b)`:** Provjerava jesu li dva skupa disjunktna (nemaju zajedničkih elemenata).
* **`operator+(std::set<T> a, std::set<T> b)`:** Vraća uniju dva skupa.
* **`operator*(std::set<T> a, std::set<T> b)`:** Vraća presjek dva skupa.
* **`operator<<(std::ostream &rijeka, std::pair<a, b> par)`:** Ispisuje par (`std::pair`) u `std::ostream`.
* **`operator<<(std::ostream &rijeka, std::set<T> set)`:** Ispisuje skup (`std::set`) u `std::ostream`.
* **`operator+=(std::set<T> &a, const std::set<T> &b)`:** Dodaje elemente skupa `b` u skup `a`.
* **`operator*=(std::set<T> &a, const std::set<T> &b)`:** Postavlja skup `a` na presjek skupova `a` i `b`.
* **`operator%(std::set<a> x, std::set<b> y)`:** Vraća Kartezijev produkt dva skupa kao skup parova.

## Korištenje

Kompajlirajte i pokrenite kod za korištenje ovih funkcija.

```bash
g++ set_operations.cpp -o set_operations
./set_operations