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

#include "myclass.hpp"
#include "myclass_capi.h"

// Constructor
myclassC *new_myclassC(const int size, const int i,
                       const double d, const double stdev)
{
	return new myclass(size, i, d, stdev);
}

// Destructor
void delete_myclassC(myclassC *in)
{
	delete in;
}

// Functions
void infoC(myclassC *in)
{
	in->info();
}

int getIrandC(myclassC *in)
{
	return in->getIrand();
}
double getDrandC(myclassC *in)
{
	return in->getDrand();
}

bool getIrandVC(myclassC *in, int *arr, size_t size)
{
	return in->getIrand(arr, size);
}

bool getDrandVC(myclassC *in, double *arr, size_t size)
{
	return in->getDrand(arr, size);
}
