# Vektor3d Class in C++

This C++ code defines a `Vektor3d` class for 3D vector operations.

## Features

* **3D Vector:** Represents a 3D vector with x, y, and z coordinates.
* **Constructors:**
    * Default constructor (initializes to (0, 0, 0)).
    * Constructor with coordinates (initializes with given values).
    * Copy constructor.
* **Basic Operations:**
    * Set coordinates (`Postavi`).
    * Get coordinates (`Ocitaj`, `DajX`, `DajY`, `DajZ`).
    * Modify coordinates (`PostaviX`, `PostaviY`, `PostaviZ`).
    * Calculate magnitude (`DajDuzinu`).
    * Scalar multiplication (`PomnoziSaSkalarom`).
    * Vector addition (`SaberiSa`, `ZbirVektora`).
    * Print vector (`Ispisi`).
    * Count number of times the vector has been printed (`DajBrojIspisa`).
* **Mutable Counter:** Includes a mutable counter to track the number of times the `Ispisi` method is called.

## Usage

Compile and run the code to perform 3D vector operations.

```bash
g++ vektor3d.cpp -o vektor3d -lm
./vektor3d