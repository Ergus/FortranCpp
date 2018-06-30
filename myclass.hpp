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

#ifndef MYCLASS_H
#define MYCLASS_H

#include <cstddef>

#include <random>

using namespace std;

class myclass {
	private:
		size_t _size;
		int _ivar;
		int *_iarray;
		double _dvar;
		double *_darray;

		static random_device rd;  	   // Seed for the RNG
		mt19937 gen;              	   // Mersenne_twister
		poisson_distribution<> idist;
		normal_distribution<> ddist;

	public:
		myclass(const int size, const int i,
		        const double d, const double stdev);
		~myclass();

		void info();

		int getIrand() { return idist(gen); };
		double getDrand() { return ddist(gen); };

		bool getIrand(int *arr, size_t size);
		bool getDrand(double *arr, size_t size);
};

#endif //MYCLASS_H
