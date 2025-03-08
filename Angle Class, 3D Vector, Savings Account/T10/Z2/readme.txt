# Krug and Valjak Classes in C++

This C++ code defines two classes: `Krug` (Circle) and `Valjak` (Cylinder).

## Krug (Circle) Class

Represents a circle with a radius.

### Features

* **Constructor:**
    * `explicit Krug(double x)`: Initializes a circle with a given radius. Throws `std::domain_error` if the radius is not positive.
* **Methods:**
    * `void Postavi(double x)`: Sets the radius. Throws `std::domain_error` if the radius is not positive.
    * `double DajPoluprecnik() const`: Returns the radius.
    * `double DajPovrsinu() const`: Returns the area of the circle.
    * `double DajObim() const`: Returns the circumference of the circle.
    * `void Skaliraj(double x)`: Scales the circle by a given factor. Throws `std::domain_error` if the scaling factor is not positive.
    * `void Ispisi() const`: Prints the radius, circumference, and area of the circle.

## Valjak (Cylinder) Class

Represents a cylinder with a circular base and a height.

### Features

* **Constructor:**
    * `explicit Valjak(double x, double y)`: Initializes a cylinder with a given base radius and height. Throws `std::domain_error` if either the radius or height is not positive.
* **Methods:**
    * `void Postavi(double x, double y)`: Sets the base radius and height. Throws `std::domain_error` if either the radius or height is not positive.
    * `Krug DajBazu() const`: Returns the base circle.
    * `double DajPoluprecnikBaze() const`: Returns the base radius.
    * `double DajVisinu() const`: Returns the height.
    * `double DajPovrsinu() const`: Returns the surface area of the cylinder.
    * `double DajZapreminu() const`: Returns the volume of the cylinder.
    * `void Skaliraj(double x)`: Scales the cylinder by a given factor. Throws `std::domain_error` if the scaling factor is not positive.
    * `void Ispisi() const`: Prints the base radius, height, surface area, and volume of the cylinder.

## Usage

Compile and run the code to use the `Krug` and `Valjak` classes.

```bash
g++ krug_valjak.cpp -o krug_valjak -lm
./krug_valjak