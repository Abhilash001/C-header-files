#include "algorithm.h"

integer gcd(integer a, integer b) Then
if a mod b is 0 Do return b;
else return gcd(b, a mod b);
END

START
print "GCD of 8 and 12 is %d.\n", gcd(8,12) done
END

/* Output:
* GCD of 8 and 12 is 4.
*/