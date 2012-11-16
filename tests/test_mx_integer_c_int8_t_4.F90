!PyF95.start
!...............................................................................
!.
!. This code was pre-parsed by PyF95++, a block parser and code generator.
!. Website: http://blockit.sourceforge.net/
!. Wiki: http://blockit.sourceforge.net/wiki.html
!. Download: http://blockit.sourceforge.net/download.html
!.
!................................................................................
!PyF95.hash: 0
!PyF95.symbol: template_4303319312_integer_c_int8_t_4
!PyF95.symbol: mexFunction|template_4303319312_integer_c_int8_t_4
!PyF95.symbol: test_mx_integer_c_int8_t_4|template_4303319312_integer_c_int8_t_4
!PyF95.symbol: test_explicit_interface|mexFunction|template_4303319312_integer_c_int8_t_4
!PyF95.symbol: Foo_integer_c_int8_t_4|test_mx_integer_c_int8_t_4|template_4303319312_integer_c_int8_t_4
!PyF95.symbol: special_4303087760_integer_c_int8_t_4_4324997968|mexFunction|template_4303319312_integer_c_int8_t_4
!PyF95.end
#include "fintrf.h"
#include "repidx.h"

! this is a dummy module to give something to instantiate
! and trick PyF95++ into creating seperate templated files for
! each instantiation (each containing an un-mangled mexFunction
! outside the module)
module test_mx_integer_c_int8_t_4
  use iso_c_binding
  integer, parameter :: c_uint8_t = c_int8_t
  integer, parameter :: c_uint16_t = c_int16_t
  type Foo_integer_c_int8_t_4
    integer(kind=c_int8_t) :: REPIDX_4(x,1)
  end type Foo_integer_c_int8_t_4
end module test_mx_integer_c_int8_t_4

subroutine mexFunction(nlhs, plhs, nrhs, prhs)
    use iso_c_binding
    use MatlabAPImx
    use MatlabAPImex
    implicit none
! ARG
    mwPointer plhs(*), prhs(*)
    integer(4) nlhs, nrhs
! LOC
    integer, parameter :: c_uint8_t = c_int8_t
    integer, parameter :: c_uint16_t = c_int16_t
    integer(kind=c_int8_t), pointer :: REPIDX_4(X,:)
    integer(kind=c_int8_t), pointer :: REPIDX_4(Y,:)
    mwSize :: dims(4)
    mwPointer :: mxY, mxloc, fploc, subloc
        integer(kind=c_int8_t), parameter :: val = 2

    if( nrhs /= 1 ) then
      call mexErrMsgTxt("This function takes 1 inputs")
    endif
    if( nlhs /= 1) then
      call mexErrMsgTxt("This function returns 1 output")
    endif

    nullify(X)
    nullify(Y)
    mxY = 0

    ! get pointer to matlab argument
    call fpGetPr(X, prhs(1))
    if( .not. associated(X) ) then
      call mexErrMsgTxt("Could not get pointer to Matlab data")
    endif

    mxloc = mxGetData( prhs(1) )
    fploc = loc( REPIDX_4(X,1) )
    if( mxloc /= fploc ) then
      call mexErrMsgTxt("fp and mx locations not equal")
    endif

    ! test no copy with explicit interface
    call test_explicit_interface( X, subloc)
    if( subloc /= mxloc ) then
      call mexErrMsgTxt("copy occurred in subroutine")
    endif

    dims = shape(X)
    ! allocate Y
    call fpAllocate(Y, dims)
    if( .not. associated(Y) ) then
      call mexErrMsgTxt("Could not allocate from fortran")
    endif

    ! try writing
    Y = val
    ! now deallocate
    call fpDeallocate(Y)
    if( associated(Y) ) then
      call mexErrMsgTxt("Deallocation unsuccessful")
    endif

    ! allocate again this time for return value
    call fpAllocate(Y, dims)
    if( .not. associated(Y) ) then
      call mexErrMsgTxt("Could not allocate from fortran (second time)")
    endif
    ! fill
    Y = val * X
    ! attach
    mxY = mxArrayHeader(Y)
    if( mxY == 0 ) then
      call mexErrMsgTxt("mxArrayHeader failed")
    endif
    ! return
    plhs(1) = mxY

    contains

    subroutine test_explicit_interface(X, subloc)
      integer(kind=c_int8_t), pointer, intent(in) :: REPIDX_4(X,:)
      mwPointer, intent(out) :: subloc

      subloc = loc( REPIDX_4(X,1) )
    end subroutine test_explicit_interface

end subroutine mexFunction
