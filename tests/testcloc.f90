
program testloc
  use iso_c_binding
  implicit none
  real, pointer :: x
  integer(8) :: add1, add2

  allocate(x)
  x = 2
  add1 = transfer(c_loc(x),0_C_INTPTR_T)
  call get_add(x,add2)
  write(*,*) add1
  write(*,*) add2
  deallocate(x)
contains
  subroutine get_add(x,add)
      use iso_c_binding
      real, pointer, intent(in) :: x
      integer(8), intent(out) :: add
      add = transfer(c_loc(x),0_C_INTPTR_T)
  end subroutine
end program
