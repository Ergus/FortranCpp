#
# This file is part of the Fortran_C++ program.
# Copyright (c) 2018 Jimmy Aguilar Mena.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, version 3.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#

cmake_minimum_required(VERSION 3.0)

project(FortranCpp LANGUAGES C CXX Fortran)
enable_testing()

# library with C++ and C functions with extern C
add_library(myclass SHARED myclass.cpp myclass_capi.cpp)

# C++ example
add_executable(main_cpp main.cpp)
target_link_libraries(main_cpp myclass)
add_test(test_C++ main_cpp)

# C example
add_executable(main_c main.c)
target_link_libraries(main_c myclass)
add_test(test_C main_c)

# Fortran clasic
add_executable(main_f90 main.f90)
target_link_libraries(main_f90 myclass)
add_test(test_F90 main_f90)

# Object Oriented Fortran
file(GLOB Fsources *.f95)
add_executable(main_f95 ${Fsources})
target_link_libraries(main_f95 myclass)
add_test(test_F95 main_f95)
