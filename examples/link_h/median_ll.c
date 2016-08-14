/*
* Prints median of an unsorted list.
*/
#include <stdio.h>
#include <link.h>

void main()
{
	struct link *list = newList("4 3 1 5 2"); // list provided in parameter.
	printf("Median = %d.\n", data_in(sorted(list), len(list)/2));
}

/* Output:
* Median = 3.
*/