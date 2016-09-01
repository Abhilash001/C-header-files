#include "algorithm.h"

START
Initialize integer n set_to integer_input("Enter n: ");
Initialize integer i also j;
int_array A set_to input_array("Enter the numbers: ", "%d", n);

for in_range(i, 0, n-1, 1) Then
	for in_range(j, 0, n-i-1, 1) Then
		if A[j] > A[j+1] then 
			swap(A[j], A[j+1]);
		END
	END
END
print_array("Sorted array: \n", "%d", A, n);
END

/* Output:
* Enter n: 5
* Enter the numbers: 3 2 5 1 4
* Sorted array:
* 1 2 3 4 5
*/