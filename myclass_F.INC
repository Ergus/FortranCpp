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

interface
   function new_myclassF(size, i, d, stdev) bind(C, name="new_myclassC")
     use iso_c_binding
     implicit none
     type(c_ptr) :: new_myclassF
     integer(c_int), value :: size, i
     real(c_double), value :: d, stdev
   end function new_myclassF

   subroutine delete_myclassF(this) bind(C, name="delete_myclassC")
     use iso_c_binding
     implicit none
     type(c_ptr), value :: this
   end subroutine delete_myclassF

   subroutine infoF(this) bind(C, name="infoC")
     use iso_c_binding
     implicit none
     type(c_ptr), value :: this
   end subroutine infoF

   function getIrandF(this) bind(C, name="getIrandC")
     use iso_c_binding
     implicit none
     integer(c_int) :: getIrandF
     type(c_ptr), value :: this
   end function getIrandF

   function getDrandF(this) bind(C, name="getDrandC")
     use iso_c_binding
     implicit none
     real(c_double) :: getDrandF
     type(c_ptr), value :: this
   end function getDrandF

   function getIrandVF(this, arr, size) bind(C, name="getIrandVC")
     use iso_c_binding
     implicit none
     logical(c_bool) :: getIrandVF
     type(c_ptr), value :: this
     integer(c_int), intent(inout), dimension(*) :: arr
     integer(c_int), value :: size
   end function getIrandVF

   function getDrandVF(this, arr, size) bind(C, name="getDrandVC")
     use iso_c_binding
     implicit none
     logical(c_bool) :: getDrandVF
     type(c_ptr), value :: this
     real(c_double), intent(inout), dimension(*) :: arr
     integer( c_int), value :: size
   end function getDrandVF

end interface
