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

int main(int argc, char **argv)
{
	myclass a(10, 5, 0.0, 1);

	a.info();

	int i = a.getIrand();
	double x = a.getDrand();

	const  size_t size = 5;

	int ai[size];
	double ax[size];

	a.getIrand(ai, size);
	a.getDrand(ax, size);


	cout << "External" << endl;
	cout << i << endl;
	cout << x << endl;
	for (size_t i = 0; i < size; ++i) {
		cout << i << "\t" << ai[i] << "\t" << ax[i] << endl;
	}

	return 0;
}
