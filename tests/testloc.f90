
program testloc
  implicit none
  real, pointer :: x
  integer(8) :: add1, add2

  allocate(x)
  x = 2
  add1 = loc(x)
  call get_add(x,add2)
  write(*,*) add1
  write(*,*) add2
  deallocate(x)
contains
  subroutine get_add(x,add)
      real, pointer, intent(in) :: x
      integer(8), intent(out) :: add
      add = loc(x)
  end subroutine
end program
