/*
 * This file is part of the Fortran_C++ program.
 * Copyright (c) 2018 Jimmy Aguilar Mena.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>

#include "myclass.hpp"

random_device myclass::rd;

myclass::myclass(const int size, const int i,
                 const double d, const double stdev):
	_size(size), _ivar(i), _dvar(d),
	_iarray(new int[size]),
	_darray(new double[size]),
	idist(i), ddist(d, stdev)
{
	for (size_t i = 0; i < size; ++i) {
		_iarray[i] = idist(gen);
		_darray[i] = ddist(gen);
	}
}

myclass::~myclass()
{
	delete [] _iarray;
	delete [] _darray;
}

void myclass::info()
{
	cout << "# size: " << _size << endl;
	cout << "# ivar: " << _ivar << endl;
	cout << "# dvar: " << _dvar << endl;

	for (size_t i = 0; i < _size; ++i)
		cout << _iarray[i] << "\t"<< _darray[i] << endl;
}


bool myclass::getIrand(int *arr, size_t size)
{
	for (size_t i = 0; i < size; ++i)
		arr[i] = idist(gen);
	return true;
}

bool myclass::getDrand(double *arr, size_t size)
{
	for (size_t i = 0; i < size; ++i)
		arr[i] = ddist(gen);
	return true;
}

