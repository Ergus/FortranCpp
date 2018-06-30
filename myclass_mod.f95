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

module libmyclass
  use iso_c_binding
  implicit none
  private :: new_myclass, delete_myclass, info, getIrand, getDrand, getIrandV, getDrandV

  public :: myclass

  include "myclass_F.INC"

  type myclass
     private
     type(c_ptr) :: ptr ! pointer to the Foo class
   contains
     procedure :: info
     procedure :: getIrand
     procedure :: getDrand
     procedure :: getIrandV
     procedure :: getDrandV
     generic :: getRandV => getIrandV, getDrandV
     final :: delete_myclass
  end type myclass

  interface myclass
     procedure new_myclass
  end interface myclass

contains
  function new_myclass(size, i, d, stdev)
    implicit none
    type(myclass) :: new_myclass
    integer, intent(in) :: size, i
    real(4), intent(in) :: d, stdev
    new_myclass%ptr = new_myclassF(size, i, real(d,8), real(stdev,8))
  end function new_myclass

  subroutine delete_myclass(this)
    implicit none
    type(myclass), intent(inout) :: this
    call delete_myclassF(this%ptr)
  end subroutine delete_myclass

  subroutine info(this)
    implicit none
    class(myclass), intent(inout) :: this
    call infoF(this%ptr)
  end subroutine info

  integer function getIrand(this)
    implicit none
    class(myclass), intent(inout) :: this
    getIrand = getIrandF(this%ptr)
  end function getIrand

  double precision function getDrand(this)
    implicit none
    class(myclass), intent(inout) :: this
    getDrand = getDrandF(this%ptr)
  end function getDrand

  logical function getIrandV(this, array, size)
    implicit none
    class(myclass), intent(inout) :: this
    integer, intent(in) :: size
    integer(c_int), intent(inout) :: array(size)
    getIrandV = getIrandVF(this%ptr, array, size)
  end function getIrandV

  logical function getDrandV(this, array, size)
    implicit none
    class(myclass), intent(inout) :: this
    integer, intent(in) :: size
    real(c_double), intent(inout) :: array(size)
    getDrandV = getDrandVF(this%ptr, array, size)
  end function getDrandV

end module libmyclass
