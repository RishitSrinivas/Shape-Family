# Shape Family Renderer (C++)

## Overview
A C++ object-oriented program that models and renders different geometric shapes
using inheritance and polymorphism. Shape data is read from an input file and
processed dynamically at runtime.

This project was designed to demonstrate core OOP concepts such as abstraction,
virtual functions, dynamic binding, and memory management.

---

## Features
- Abstract base class (`Shape`) with a pure virtual `draw()` method
- Derived classes:
  - `Circle`
  - `Rectangle`
  - `Square`
  - `Spray`
- Polymorphic rendering of shapes using base-class pointers
- Dynamic memory allocation and cleanup
- Shape data loaded from an external file (`shaperecords.txt`)
- ASCII-based rendering of shapes to the console
- Randomized density rendering for spray shapes

---

## Technologies & Concepts
- **Language:** C++
- **Concepts:**  
  - Object-Oriented Programming (OOP)  
  - Inheritance & Polymorphism  
  - Abstract Classes & Virtual Functions  
  - Dynamic Memory Management (`new` / `delete`)  
  - File I/O  
- **Libraries Used:** `<iostream>`, `<fstream>`, `<cmath>`, `<cstdlib>`, `<ctime>`

---

## Input File Format
The program reads shape data from `shaperecords.txt`.

Each line follows this format:
<ShapeType> <SerialNumber> <Value1> <Value2>

### Shape Type Codes
- `C` → Circle (radius)
- `R` → Rectangle (width, height)
- `Q` → Square (side length)
- `S` → Spray (radius, density)

### Example
C 101 5 0
R 102 6 4
Q 103 5 0
S 104 6 40

---

## How to Run
1. Clone the repository
2. Ensure `shaperecords.txt` is in the same directory as the executable
3. Compile the program: g++ main.cpp -o shapes
4. Run: ./shapes


---

## What This Project Demonstrates
- Proper use of inheritance hierarchies
- Runtime polymorphism through base-class pointers
- Separation of responsibilities across classes
- Handling external input data safely
- Manual memory management and destructor usage

---

## Future Improvements
- Replace raw pointers with smart pointers
- Add support for additional shape types
- Modularize rendering logic
- Improve error handling for malformed input files
