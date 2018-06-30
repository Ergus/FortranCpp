README
======

This is an example to do a transversal interface from C++ to Object Oriented
Fortran.

The example creates a simple class in C++, then wrapped the class in pure C,
after that it makes an interface to simple Fortran90 and finally it wraps the
interface using OO Fortran.

There is a simple main test example for every of this steps. so there are 4 main
that can be automatically generated:

1. Object Oriented C++ (main_c++)
2. Simple C (main_c)
3. Simple Fortran 90 with traditional interface (iso\_c\_binds). (main_f90)
4. Modern Object Oriented Fortran. (main_f95)

Build steps:

- git clone https://github.com/Ergus/FortranCpp.git
- cd FortranCpp
- mkdir build
- cd build
- cmake ..
- make
- make test

In this point there will be the 4 executable in the build directory.

They should produce similar outputs.

Author: Jimmy Aguilar Mena
