# Vektor3d Class in C++

This C++ code defines a `Vektor3d` class, representing a 3D vector. It provides various functionalities for manipulating and performing operations on 3D vectors.

## Features

* **3D Vector Representation:** Stores 3D vector coordinates (x, y, z) as double values.
* **Initialization:**
    * `Postavi(double x, double y, double z)`: Sets the vector coordinates.
* **Accessors:**
    * `Ocitaj(double &x, double &y, double &z) const`: Reads the vector coordinates.
    * `DajX() const`, `DajY() const`, `DajZ() const`: Returns individual coordinates.
    * `DajDuzinu() const`: Returns the magnitude (length) of the vector.
* **Mutators:**
    * `PostaviX(double x)`, `PostaviY(double x)`, `PostaviZ(double x)`: Sets individual coordinates.
    * `PomnoziSaSkalarom(double s)`: Multiplies the vector by a scalar.
    * `SaberiSa(const Vektor3d &v)`: Adds another vector to the current vector.
* **Output:**
    * `Ispisi() const`: Prints the vector coordinates in the format `{x,y,z}`.
* **Friend Function:**
    * `ZbirVektora(const Vektor3d &v1, const Vektor3d &v2)`: A friend function that returns the sum of two vectors.

## Usage

To use the `Vektor3d` class, include the code in your C++ project and create instances of the class.

```c++
#include <iostream>
#include <cmath>

// ... (Vektor3d class definition) ...

int main() {
    Vektor3d vector1, vector2, result;

    vector1.Postavi(1.0, 2.0, 3.0);
    vector2.Postavi(4.0, 5.0, 6.0);

    std::cout << "Vector 1: ";
    vector1.Ispisi();
    std::cout << std::endl;

    std::cout << "Vector 2: ";
    vector2.Ispisi();
    std::cout << std::endl;

    result = ZbirVektora(vector1, vector2);
    std::cout << "Sum: ";
    result.Ispisi();
    std::cout << std::endl;

    std::cout << "Length of Vector 1: " << vector1.DajDuzinu() << std::endl;

    vector1.PomnoziSaSkalarom(2.0);
    std::cout << "Vector 1 multiplied by 2: ";
    vector1.Ispisi();
    std::cout << std::endl;

    return 0;
}