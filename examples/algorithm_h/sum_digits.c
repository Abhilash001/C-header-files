#include "algorithm.h"

START
Initialize integer n set_to Integer_input
Initialize integer s set_to 0;
while n isnot 0 then
	integer t set_to n mod 10;
	To s add t;
	To n divide 10;
	END
print "Sum of digits is %d.\n", s done
END

/* Output:
* 1243
* Sum of digits is 10.
*/