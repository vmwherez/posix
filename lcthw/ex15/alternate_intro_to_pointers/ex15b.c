#include <stdio.h> 

// "Pointers are just values that happen to be addresses."
// https://www.youtube.com/watch?v=egRIkkBEttg&list=PLS_6jVRIVvTP8qUqYgXQrbUzUOdCO4NDF
/*
 *  ADDRESSS   VALUE      NAME
 *  0x7fff004  4          x
 *  0x7fff008  0x7fff004  my_ptr
 *  0x7fff00c  0x7fff004  m_d_ptr
 *
 *  ...
 *
 *  int **my_d_ptr = &my_ptr;
 *
 *
 */



int main(void) {
	int x = 4;
	int *my_ptr = &x;
       	int **my_d_ptr = &my_ptr;	

	printf("x=%d, my_ptr=%p\n", x, my_ptr);	

	printf("*my_ptr=%d\n", *my_ptr); //dereference, the the thing pointed to by my_ptr is 4.
	printf("**my_d_ptr=%d\n", **my_d_ptr); // double dereference

	
	return 0;
}
