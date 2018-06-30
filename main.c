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

#include <stdio.h>

#include "myclass_capi.h"

int main(int argc, char **argv)
{
	struct myclassC *a = new_myclassC(10, 5, 0.0, 1);

	infoC(a);

	int i = getIrandC(a);
	double x = getDrandC(a);

	const  size_t size = 5;

	int ai[size];
	double ax[size];

	getIrandVC(a, ai, size);
	getDrandVC(a, ax, size);


	printf("External\n");
	printf("%d\n", i);
	printf("%lf\n", x);
	for (size_t i = 0; i < size; ++i) {
		printf("%lu \t %d \t %lf\n", i, ai[i], ax[i]);
	}

	return 0;
}
