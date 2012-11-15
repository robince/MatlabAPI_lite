  integer*4, parameter :: mxREAL = 0
  integer*4, parameter :: mxCOMPLEX = 1

  integer*4, parameter :: mxUNKNOWN_CLASS  =  0
  integer*4, parameter :: mxCELL_CLASS     =  1
  integer*4, parameter :: mxSTRUCT_CLASS   =  2
  integer*4, parameter :: mxLOGICAL_CLASS  =  3
  integer*4, parameter :: mxCHAR_CLASS     =  4
  integer*4, parameter :: mxVOID_CLASS     =  5
  integer*4, parameter :: mxDOUBLE_CLASS   =  6
  integer*4, parameter :: mxSINGLE_CLASS   =  7
  integer*4, parameter :: mxINT8_CLASS     =  8
  integer*4, parameter :: mxUINT8_CLASS    =  9
  integer*4, parameter :: mxINT16_CLASS    = 10
  integer*4, parameter :: mxUINT16_CLASS   = 11
  integer*4, parameter :: mxINT32_CLASS    = 12
  integer*4, parameter :: mxUINT32_CLASS   = 13
  integer*4, parameter :: mxINT64_CLASS    = 14
  integer*4, parameter :: mxUINT64_CLASS   = 15
  integer*4, parameter :: mxFUNCTION_CLASS = 16
  integer*4, parameter :: mxOPAQUE_CLASS   = 17
  integer*4, parameter :: mxOBJECT_CLASS   = 18
  integer*4, parameter :: mxINDEX_CLASS    = 19
  integer*4, parameter :: mxSPARSE_CLASS   = 20

  integer, parameter :: NameLengthMax_ = 63


interface
!-----
      integer(4) function mxAddField(pm, fieldname)
      mwPointer, intent(in) :: pm
      character(len=*), intent(in) :: fieldname
      end function mxAddField
!-----

!mxArrayToString (C)

!-----

!mxAssert (C)

!-----

!mxAssertS (C)

!-----
      mwIndex function mxCalcSingleSubscript(pm, nsubs, subs)
      mwPointer, intent(in) :: pm
      mwSize, intent(in) :: nsubs
      mwIndex, intent(in) :: subs
      end function mxCalcSingleSubscript
!-----
      mwPointer function mxCalloc(n, elementsize)
      mwSize, intent(in) :: n, elementsize
      end function mxCalloc
!-----
      integer(4) function mxClassIDFromClassName(classname)
      character(len=*), intent(in) :: classname
      end function mxClassIDFromClassName
!-----
      subroutine mxCopyCharacterToPtr(y, px, n)  ! Ptr is to a C-style string
      character(len=*), intent(in) :: y
      mwPointer, intent(out) :: px
      mwSize, intent(in) :: n
      end subroutine mxCopyCharacterToPtr
!-----
!      subroutine mxCopyComplex32ToPtr(y, pr, pi, n)  ! New code below
!      complex(16), intent(in) :: y(n)
!      mwPointer, intent(out) :: pr, pi
!      mwSize, intent(in) :: n
!      end subroutine mxCopyComplex32ToPtr
!-----
      subroutine mxCopyComplex16ToPtr(y, pr, pi, n)
      complex(8), intent(in) :: y(n)
      mwPointer, intent(out) :: pr, pi
      mwSize, intent(in) :: n
      end subroutine mxCopyComplex16ToPtr
!-----
      subroutine mxCopyComplex8ToPtr(y, pr, pi, n)
      complex(4), intent(in) :: y(n)
      mwPointer, intent(out) :: pr, pi
      mwSize, intent(in) :: n
      end subroutine mxCopyComplex8ToPtr
!-----
      subroutine mxCopyInteger1ToPtr(y, px, n)
      integer(1), intent(in) :: y(n)
      mwPointer, intent(out) :: px
      mwSize, intent(in) :: n
      end subroutine mxCopyInteger1ToPtr
!-----
      subroutine mxCopyInteger2ToPtr(y, px, n)
      integer(2), intent(in) :: y(n)
      mwPointer, intent(out) :: px
      mwSize, intent(in) :: n
      end subroutine mxCopyInteger2ToPtr
!-----
      subroutine mxCopyInteger4ToPtr(y, px, n)
      integer(4), intent(in) :: y(n)
      mwPointer, intent(out) :: px
      mwSize, intent(in) :: n
      end subroutine mxCopyInteger4ToPtr
!-----
!      subroutine mxCopyInteger8ToPtr(y, px, n) ! New code below
!      integer(8), intent(in) :: y(n)
!      mwPointer, intent(out) :: px
!      mwSize, intent(in) :: n
!      end subroutine mxCopyInteger8ToPtr
!-----
      subroutine mxCopyPtrToCharacter(px, y, n) ! Ptr is to a C-style string
      mwPointer, intent(in) :: px
      character(len=*), intent(out) :: y
      mwSize, intent(in) :: n
      end subroutine mxCopyPtrToCharacter
!-----
!      subroutine mxCopyPtrToComplex32(pr, pi, y, n) ! New code below
!      mwPointer, intent(in) :: pr, pi
!      complex(16), intent(out) :: y(n)
!      mwSize, intent(in) :: n
!      end subroutine mxCopyPtrToComplex32
!-----
      subroutine mxCopyPtrToComplex16(pr, pi, y, n)
      mwPointer, intent(in) :: pr, pi
      complex(8), intent(out) :: y(n)
      mwSize, intent(in) :: n
      end subroutine mxCopyPtrToComplex16
!-----
      subroutine mxCopyPtrToComplex8(pr, pi, y, n)
      mwPointer, intent(in) :: pr, pi
      complex(4), intent(out) :: y(n)
      mwSize, intent(in) :: n
      end subroutine mxCopyPtrToComplex8
!-----
      subroutine mxCopyPtrToInteger1(px, y, n)
      mwPointer, intent(in) :: px
      integer(1), intent(out) :: y(n)
      mwSize, intent(in) :: n
      end subroutine mxCopyPtrToInteger1
!-----
      subroutine mxCopyPtrToInteger2(px, y, n)
      mwPointer, intent(in) :: px
      integer(2), intent(out) :: y(n)
      mwSize, intent(in) :: n
      end subroutine mxCopyPtrToInteger2
!-----
      subroutine mxCopyPtrToInteger4(px, y, n)
      mwPointer, intent(in) :: px
      integer(4), intent(out) :: y(n)
      mwSize, intent(in) :: n
      end subroutine mxCopyPtrToInteger4
!-----
!      subroutine mxCopyPtrToInteger8(px, y, n) ! New code below
!      mwPointer, intent(in) :: px
!      integer(8), intent(out) :: y(n)
!      mwSize, intent(in) :: n
!      end subroutine mxCopyPtrToInteger8
!-----
      subroutine mxCopyPtrToPtrArray(px, y, n)
      mwPointer, intent(in) :: px
      mwPointer, intent(out) :: y(n)
      mwSize, intent(in) :: n
      end subroutine mxCopyPtrToPtrArray
!-----
      subroutine mxCopyPtrToReal4(px, y, n)
      mwPointer, intent(in) :: px
      real(4), intent(out) :: y(n)
      mwSize, intent(in) :: n
      end subroutine mxCopyPtrToReal4
!-----
      subroutine mxCopyPtrToReal8(px, y, n)
      mwPointer, intent(in) :: px
      real(8), intent(out) :: y(n)
      mwSize, intent(in) :: n
      end subroutine mxCopyPtrToReal8
!-----
!      subroutine mxCopyPtrToReal16(px, y, n) ! New code below
!      mwPointer, intent(in) :: px
!      real(16), intent(out) :: y(n)
!      mwSize, intent(in) :: n
!      end subroutine mxCopyPtrToReal16
!-----
      subroutine mxCopyReal4ToPtr(y, px, n)
      real(4), intent(in) :: y(n)
      mwPointer, intent(out) :: px
      mwSize, intent(in) :: n
      end subroutine mxCopyReal4ToPtr
!-----
      subroutine mxCopyReal8ToPtr(y, px, n)
      real(8), intent(in) :: y(n)
      mwPointer, intent(out) :: px
      mwSize, intent(in) :: n
      end subroutine mxCopyReal8ToPtr
!-----
!      subroutine mxCopyReal16ToPtr(y, px, n) ! New code below
!      real(16), intent(in) :: y(n)
!      mwPointer, intent(out) :: px
!      mwSize, intent(in) :: n
!      end subroutine mxCopyReal16ToPtr
!-----
      mwPointer function mxCreateCellArray(ndim, dims)
      mwSize, intent(in) :: ndim
      mwSize, intent(in) :: dims(ndim)
      end function mxCreateCellArray
!-----
      mwPointer function mxCreateCellMatrix(m, n)
      mwSize, intent(in) :: m, n
      end function mxCreateCellMatrix
!-----
      mwPointer function mxCreateCharArray(ndim, dims)
      mwSize, intent(in) :: ndim
      mwSize, intent(in) :: dims(ndim)
      end function mxCreateCharArray
!-----
      mwPointer function mxCreateCharMatrixFromStrings(m, str)
      mwSize, intent(in) :: m
      character(len=*), intent(in) :: str(m)
      end function mxCreateCharMatrixFromStrings
!-----
      mwPointer function mxCreateDoubleMatrix(m, n, ComplexFlag)
      mwSize, intent(in) :: m, n
      integer(4), intent(in) :: ComplexFlag
      end function mxCreateDoubleMatrix
!-----
      mwPointer function mxCreateDoubleScalar(number)
      real(8), intent(in) :: number
      end function mxCreateDoubleScalar
!-----
!      mwPointer function mxCreateLogicalArray( ndim, dims ) ! New code below
!      mwSize, intent(in) :: ndim
!      mwSize, intent(in) :: dims(ndim)
!      end function mxCreateLogicalArray
!-----
!      mwPointer function mxCreateLogicalMatrix( m, n ) ! New code below
!      mwSize, intent(in) :: m, n
!      end function mxCreateLogicalMatrix
!-----
!      mwPointer function mxCreateLogicalScalar( number ) ! New code below
!      logical, intent(in) :: number
!      end function mxCreateLogicalScalar
!-----
      mwPointer function mxCreateNumericArray(ndim, dims,               &
     &                                        idclass, ComplexFlag)
      mwSize, intent(in) :: ndim
      mwSize, intent(in) :: dims(ndim)
      integer(4), intent(in) :: idclass, ComplexFlag
      end function mxCreateNumericArray
!-----
      mwPointer function mxCreateNumericMatrix(m, n,                    &
     &                                         idclass, ComplexFlag)
      mwSize, intent(in) :: m, n
      integer(4), intent(in) :: idclass, ComplexFlag
      end function mxCreateNumericMatrix
!-----
      mwPointer function mxCreateSparse(m, n, nzmax, ComplexFlag)
      mwSize, intent(in) :: m, n, nzmax
      integer(4), intent(in) :: ComplexFlag
      end function mxCreateSparse
!-----
!      mwPointer function mxCreateSparseLogicalMatrix(m, n, nzmax) ! See MatlabAPImex, MatlabAPIeng
!      mwSize, intent(in) :: m, n, nzmax                           ! mexCreateSparseLogicalMatrix
!      end function mxCreateSparseLogicalMatrix                    ! engCreateSparseLogicalMatrix
!-----
      mwPointer function mxCreateString(str)
      character(len=*), intent(in) :: str
      end function mxCreateString
!-----
      mwPointer function mxCreateStructArray(ndim, dims,                &
     &                                       nfields, fieldnames)
      mwSize, intent(in) :: ndim
      mwSize, intent(in) :: dims(ndim)
      integer(4), intent(in) :: nfields
      character(len=*), intent(in) :: fieldnames(nfields)
      end function mxCreateStructArray
!-----
      mwPointer function mxCreateStructMatrix(m, n,                     &
     &                                        nfields, fieldnames)
      mwSize, intent(in) :: m, n
      integer(4), intent(in) :: nfields
      character(len=*), intent(in) :: fieldnames(nfields)
      end function mxCreateStructMatrix
!-----
      subroutine mxDestroyArray(pm)
      mwPointer, intent(in) :: pm
      end subroutine mxDestroyArray
!-----
      mwPointer function mxDuplicateArray(pm)
      mwPointer, intent(in) :: pm
      end function mxDuplicateArray
!-----
      subroutine mxFree(ptr)
      mwPointer, intent(in) :: ptr
      end subroutine mxFree
!-----
      mwPointer function mxGetCell(pm, cellindex)
      mwPointer, intent(in) :: pm
      mwIndex, intent(in) :: cellindex
      end function mxGetCell
!-----
!      mwPointer function mxGetChars(pm) ! New code below
!      mwPointer, intent(in) :: pm
!      end function mxGetChars
!-----
      integer(4) function mxGetClassID(pm)
      mwPointer, intent(in) :: pm
      end function mxGetClassID
!-----
      function mxGetClassName(pm)
      integer, parameter :: NameLengthMax_ = 63
      character(len=NameLengthMax_) :: mxGetClassName ! Doc is wrong
      mwPointer, intent(in) :: pm
      end function mxGetClassName
!-----
      mwPointer function mxGetData(pm)
      mwPointer, intent(in) :: pm
      end function mxGetData
!-----
      mwPointer function mxGetDimensions(pm)
      mwPointer, intent(in) :: pm
      end function mxGetDimensions
!-----
      mwSize function mxGetElementSize(pm) ! Doc is wrong
      mwPointer, intent(in) :: pm
      end function mxGetElementSize
!-----
      real(8) function mxGetEps()
      end function mxGetEps
!-----
      mwPointer function mxGetField(pm, fieldindex, fieldname)
      mwPointer, intent(in) :: pm
      mwIndex, intent(in) :: fieldindex
      character(len=*), intent(in) :: fieldname
      end function mxGetField
!-----
      mwPointer function mxGetFieldByNumber(pm, fieldindex,             &
     &                                      fieldnumber)
      mwPointer, intent(in) :: pm
      mwIndex, intent(in) :: fieldindex
      integer(4), intent(in) :: fieldnumber
      end function mxGetFieldByNumber
!-----
      function mxGetFieldNameByNumber(pm, fieldnumber) ! Doc is wrong
      integer, parameter :: NameLengthMax_ = 63
      character(len=NameLengthMax_) :: mxGetFieldNameByNumber
      mwPointer, intent(in) :: pm
      integer(4), intent(in) :: fieldnumber
      end function mxGetFieldNameByNumber
!-----
      integer(4) function mxGetFieldNumber(pm, fieldname)
      mwPointer, intent(in) :: pm
      character(len=*), intent(in) :: fieldname
      end function mxGetFieldNumber
!-----
      mwPointer function mxGetImagData(pm)
      mwPointer, intent(in) :: pm
      end function mxGetImagData
!-----
      real(8) function mxGetInf()
      end function mxGetInf
!-----
      mwPointer function mxGetIr(pm)
      mwPointer, intent(in) :: pm
      end function mxGetIr
!-----
      mwPointer function mxGetJc(pm)
      mwPointer, intent(in) :: pm
      end function mxGetJc
!-----
!      mwPointer function mxGetLogicals(pm) ! New code below
!      mwPointer, intent(in) :: pm
!      end function mxGetLogicals
!-----
      mwSize function mxGetM( mx )
      mwPointer, intent(in) :: mx
      end function mxGetM
!-----
      mwSize function mxGetN( mx )
      mwPointer, intent(in) :: mx
      end function mxGetN
!-----
      real(8) function mxGetNaN()
      end function mxGetNaN
!-----
      mwSize function mxGetNumberOfDimensions( mx )
      mwPointer, intent(in) :: mx
      end function mxGetNumberOfDimensions
!-----
      mwSize function mxGetNumberOfElements( mx )
      mwPointer, intent(in) :: mx
      end function mxGetNumberOfElements
!-----
      integer(4) function mxGetNumberOfFields(pm)
      mwPointer, intent(in) :: pm
      end function mxGetNumberOfFields
!-----
      mwSize function mxGetNzmax(pm)
      mwPointer, intent(in) :: pm
      end function mxGetNzmax
!-----
      mwPointer function mxGetPi( mx )
      mwPointer, intent(in) :: mx
      end function mxGetPi
!-----
      mwPointer function mxGetPr( mx )
      mwPointer, intent(in) :: mx
      end function mxGetPr
!-----
      mwPointer function mxGetProperty(pa, objectindex, propname)
      mwPointer, intent(in) :: pa
      mwIndex, intent(in) :: objectindex
      character(len=*), intent(in) :: propname
      end function mxGetProperty
!-----
      real(8) function mxGetScalar(pm)
      mwPointer, intent(in) :: pm
      end function mxGetScalar
!-----
      integer(4) function mxGetString(pm, str, strlen)
      mwPointer, intent(in) :: pm
      character(len=*), intent(in) :: str
      mwSize, intent(in) :: strlen
      end function mxGetString
!-----
      integer(4) function mxIsCell(pm)
      mwPointer, intent(in) :: pm
      end function mxIsCell
!-----
      integer(4) function mxIsChar(pm)
      mwPointer, intent(in) :: pm
      end function mxIsChar
!-----
      integer(4) function mxIsClass(pm, classname)
      mwPointer, intent(in) :: pm
      character(len=*), intent(in) :: classname
      end function mxIsClass
!-----
      integer(4) function mxIsComplex( mx )
      mwPointer, intent(in) :: mx
      end function mxIsComplex
!-----
      integer(4) function mxIsDouble( mx )
      mwPointer, intent(in) :: mx
      end function mxIsDouble
!-----
      integer(4) function mxIsEmpty(pm)
      mwPointer, intent(in) :: pm
      end function mxIsEmpty
!-----
      integer(4) function mxIsFinite(number)
      real(8), intent(in) :: number
      end function mxIsFinite
!-----
      integer(4) function mxIsFromGlobalWS(pm)
      mwPointer, intent(in) :: pm
      end function mxIsFromGlobalWS
!-----
      integer(4) function mxIsInf(number)
      real(8), intent(in) :: number
      end function mxIsInf
!-----
      integer(4) function mxIsInt16(pm)
      mwPointer, intent(in) :: pm
      end function mxIsInt16
!-----
      integer(4) function mxIsInt32(pm)
      mwPointer, intent(in) :: pm
      end function mxIsInt32
!-----
      integer(4) function mxIsInt64(pm)
      mwPointer, intent(in) :: pm
      end function mxIsInt64
!-----
      integer(4) function mxIsInt8(pm)
      mwPointer, intent(in) :: pm
      end function mxIsInt8
!-----
      integer(4) function mxIsLogical(pm)
      mwPointer, intent(in) :: pm
      end function mxIsLogical
!-----
!      integer(4) function mxIsLogicalScalar(pm) ! New code below
!      mwPointer, intent(in) :: pm
!      end function mxIsLogicalScalar
!-----
!      integer(4) function mxIsLogicalScalarTrue(pm) ! New code below
!      mwPointer, intent(in) :: pm
!      end function mxIsLogicalScalarTrue
!-----
      integer(4) function mxIsNaN(number)
      real(8), intent(in) :: number
      end function mxIsNaN
!-----
      integer(4) function mxIsNumeric(pm)
      mwPointer, intent(in) :: pm
      end function mxIsNumeric
!-----
      integer(4) function mxIsSingle(pm)
      mwPointer, intent(in) :: pm
      end function mxIsSingle
!-----
      integer(4) function mxIsSparse(pm)
      mwPointer, intent(in) :: pm
      end function mxIsSparse
!-----
      integer(4) function mxIsStruct(pm)
      mwPointer, intent(in) :: pm
      end function mxIsStruct
!-----
      integer(4) function mxIsUint16(pm)
      mwPointer, intent(in) :: pm
      end function mxIsUint16
!-----
      integer(4) function mxIsUint32(pm)
      mwPointer, intent(in) :: pm
      end function mxIsUint32
!-----
      integer(4) function mxIsUint64(pm)
      mwPointer, intent(in) :: pm
      end function mxIsUint64
!-----
      integer(4) function mxIsUint8(pm)
      mwPointer, intent(in) :: pm
      end function mxIsUint8
!-----
      mwPointer function mxMalloc(n)
      mwSize, intent(in) :: n
      end function mxMalloc
!-----
      mwPointer function mxRealloc(ptr, elementsize)
      mwPointer, intent(in) :: ptr
      mwSize, intent(in) :: elementsize
      end function mxRealloc
!-----
      subroutine mxRemoveField(pm, fieldnumber)
      mwPointer, intent(in) :: pm
      integer(4), intent(in) :: fieldnumber
      end subroutine mxRemoveField
!-----
      subroutine mxSetCell(pm, cellindex, cellvalue)
      mwPointer, intent(in) :: pm, cellvalue
      mwIndex, intent(in) :: cellindex
      end subroutine mxSetCell
!-----

!mxSetClassName (C)

!-----
      subroutine mxSetData(pm, pr)
      mwPointer, intent(in) :: pm, pr
      end subroutine mxSetData
!-----
      integer(4) function mxSetDimensions(pm, dims, ndim)
      mwPointer, intent(in) :: pm
      mwSize, intent(in) :: ndim
      mwSize, intent(in) :: dims(ndim)
      end function mxSetDimensions
!-----
      subroutine mxSetField(pm, fieldindex, fieldname, pvalue)
      mwPointer, intent(in) :: pm, pvalue
      mwIndex, intent(in) :: fieldindex
      character(len=*), intent(in) :: fieldname
      end subroutine mxSetField
!-----
      subroutine mxSetFieldByNumber(pm, fieldindex,                     &
     &                              fieldnumber, pvalue)
      mwPointer, intent(in) :: pm, pvalue
      mwIndex, intent(in) :: fieldindex
      integer(4), intent(in) :: fieldnumber
      end subroutine mxSetFieldByNumber
!-----
      subroutine mxSetImagData(pm, pi)
      mwPointer, intent(in) :: pm, pi
      end subroutine mxSetImagData
!-----
      subroutine mxSetIr(pm, ir)
      mwPointer, intent(in) :: pm, ir
      end subroutine mxSetIr
!-----
      subroutine mxSetJc(pm, jc)
      mwPointer, intent(in) :: pm, jc
      end subroutine mxSetJc
!-----
      subroutine mxSetM(pm, m)
      mwPointer, intent(in) :: pm
      mwSize, intent(in) :: m
      end subroutine mxSetM
!-----
      subroutine mxSetN(pm, n)
      mwPointer, intent(in) :: pm
      mwSize, intent(in) :: n
      end subroutine mxSetN
!-----
      subroutine mxSetNzmax(pm, nzmax)
      mwPointer, intent(in) :: pm
      mwSize, intent(in) :: nzmax
      end subroutine mxSetNzmax
!-----
      subroutine mxSetPi(pm, pi)
      mwPointer, intent(in) :: pm, pi
      end subroutine mxSetPi
!-----
      subroutine mxSetPr(pm, pr)
      mwPointer, intent(in) :: pm, pr
      end subroutine mxSetPr
!-----
end interface

