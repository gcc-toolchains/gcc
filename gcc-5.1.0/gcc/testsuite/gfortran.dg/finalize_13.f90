! { dg-do run }
!
! PR fortran/37336
!
module m
  implicit none
  type t
    integer :: i
  contains
    final :: fini3, fini2, fini_elm
  end type t

  type, extends(t) :: t2
    integer :: j
  contains
    final :: f2ini2, f2ini_elm
  end type t2

  logical :: elem_call
  logical :: rank2_call
  logical :: rank3_call
  integer :: cnt, cnt2
  integer :: fini_call

contains
  subroutine fini2 (x)
    type(t), intent(in), contiguous :: x(:,:)
    if (.not. rank2_call) call abort ()
    if (size(x,1) /= 2 .or. size(x,2) /= 3) call abort()
    !print *, 'fini2:', x%i
    if (any (x%i /= reshape([11, 12, 21, 22, 31, 32], [2,3]))) call abort()
    fini_call = fini_call + 1
  end subroutine

  subroutine fini3 (x)
    type(t), intent(in) :: x(2,2,*)
    integer :: i,j,k
    if (.not. elem_call) call abort ()
    if (.not. rank3_call) call abort ()
    if (cnt2 /= 9) call abort()
    if (cnt /= 1) call abort()
      do i = 1, 2
        do j = 1, 2
          do k = 1, 2
            !print *, k,j,i,x(k,j,i)%i
            if (x(k,j,i)%i /= k+10*j+100*i) call abort()
          end do 
        end do
      end do
    fini_call = fini_call + 1
  end subroutine

  impure elemental subroutine fini_elm (x)
    type(t), intent(in) :: x
    if (.not. elem_call) call abort ()
    if (rank3_call) call abort ()
    if (cnt2 /= 6) call abort()
    if (cnt /= x%i) call abort()
    !print *, 'fini_elm:', cnt, x%i
    fini_call = fini_call + 1
    cnt = cnt + 1
  end subroutine

  subroutine f2ini2 (x)
    type(t2), intent(in), target :: x(:,:)
    if (.not. rank2_call) call abort ()
    if (size(x,1) /= 2 .or. size(x,2) /= 3) call abort()
    !print *, 'f2ini2:', x%i
    !print *, 'f2ini2:', x%j
    if (any (x%i /= reshape([11, 12, 21, 22, 31, 32], [2,3]))) call abort()
    if (any (x%j /= 100*reshape([11, 12, 21, 22, 31, 32], [2,3]))) call abort()
    fini_call = fini_call + 1
  end subroutine

  impure elemental subroutine f2ini_elm (x)
    type(t2), intent(in) :: x
    integer, parameter :: exprected(*) &
            = [111, 112, 121, 122, 211, 212, 221, 222]

    if (.not. elem_call) call abort ()
    !print *, 'f2ini_elm:', cnt2, x%i, x%j
    if (rank3_call) then
      if (x%i /= exprected(cnt2)) call abort ()  
      if (x%j /= 1000*exprected(cnt2)) call abort ()  
    else
      if (cnt2 /= x%i .or. cnt2*10 /= x%j) call abort()
    end if
    cnt2 = cnt2 + 1
    fini_call = fini_call + 1
  end subroutine
end module m


program test
  use m
  implicit none
  class(t), save, allocatable :: y(:), z(:,:), zz(:,:,:)
  target :: z, zz
  integer :: i,j,k

  elem_call = .false.
  rank2_call = .false.
  rank3_call = .false.
  allocate (t2 :: y(5))
  select type (y)
    type is (t2)
      do i = 1, 5
        y(i)%i = i
        y(i)%j = i*10
      end do
  end select
  cnt = 1
  cnt2 = 1
  fini_call = 0
  elem_call = .true.
  deallocate (y)
  if (fini_call /= 10) call abort ()

  elem_call = .false.
  rank2_call = .false.
  rank3_call = .false.
  allocate (t2 :: z(2,3))
  select type (z)
    type is (t2)
      do i = 1, 3
        do j = 1, 2
          z(j,i)%i = j+10*i
          z(j,i)%j = (j+10*i)*100
        end do
      end do
  end select
  cnt = 1
  cnt2 = 1
  fini_call = 0
  rank2_call = .true.
  deallocate (z)
  if (fini_call /= 2) call abort ()

  elem_call = .false.
  rank2_call = .false.
  rank3_call = .false.
  allocate (t2 :: zz(2,2,2))
  select type (zz)
    type is (t2)
      do i = 1, 2
        do j = 1, 2
          do k = 1, 2
            zz(k,j,i)%i = k+10*j+100*i
            zz(k,j,i)%j = (k+10*j+100*i)*1000
          end do 
        end do
      end do
  end select
  cnt = 1
  cnt2 = 1
  fini_call = 0
  rank3_call = .true.
  elem_call = .true.
  deallocate (zz)
  if (fini_call /= 2*2*2+1) call abort ()
end program test
