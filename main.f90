!
! This file is part of the Fortran_C++ program.
! Copyright (c) 2018 Jimmy Aguilar Mena.
!
! This program is free software: you can redistribute it and/or modify
! it under the terms of the GNU General Public License as published by
! the Free Software Foundation, version 3.
!
! This program is distributed in the hope that it will be useful, but
! WITHOUT ANY WARRANTY; without even the implied warranty of
! MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
! General Public License for more details.
!
! You should have received a copy of the GNU General Public License
! along with this program. If not, see <http://www.gnu.org/licenses/>.
!

program main
  use iso_c_binding
  implicit none

  include "myclass_F.INC"

  type(c_ptr) :: a
  integer :: i
  integer, parameter :: size = 5
  double precision :: x
  integer :: ai(size)
  double precision :: ax(size)
  logical :: l

  a = new_myclassF(10, 5, real(0.0,c_double), real(1.0,c_double))
  call infoF(a)

  i = getIrandF(a)
  x = getDrandF(a)

  l = getIrandVF(a, ai, size)
  l = getDrandVF(a, ax, size)

  write(*,*) "External"
  write(*,*) i
  write(*,*) x
  do i = 1,size
     write(*,*) i, ai(i), ax(i)
  end do

end program main
