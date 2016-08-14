/*
* Test all functions of cstio.h file.
*/
#include <cstio.h>

void main()
{
	int n = Int(input("Enter an integer: ")); // test for integer input

	float f = Float(input("Enter a float no.: ")); // test for float input

	char *s = input(""); // test for string input

	int *a = arrinput("Enter 5 integers: ", "%d ", 5); // test for integer array input
	float *b = arrinput("Enter 5 float no.s: ", " %f", 5); // test for float array input

	printf("n = %d\nf = %f\ns : %s\n", n, f, s);
	arrprint("a[] array is: \n", "  %d ", a, 5); // test for integer array print
	arrprint("b[] array is: \n", "%.2f", b, 5); // test for float array print
}

/* Output:
* Enter an integer: 12
* Enter a float no.: 34.5
* Some sentence^.
* Enter 5 integers: 1 2 3
* 4
* 5
* Enter 5 float no.s: 0.1 0.3 5 4
* 9
* n = 12
* f = 34.500000
* s : Some sentence^.
* a[] array is:
* 1 2 3 4 5
* b[] array is:
* 0.10 0.30 5.00 4.00 9.00
*/