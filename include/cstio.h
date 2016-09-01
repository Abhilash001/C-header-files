/*
* Author: Abhilash Misra 
* Version: v1.1
* 
* Created: Monday, August 14, 2016, 2:41:36 PM
* Copyright (C) 2016 under the GNU General Public License. All rights reserved.
* 
*/

#ifndef CSTIO_H_
#define CSTIO_H_

/*
* The following functions have been implemented:
*
* 1) input(char *s):										return type string.
* 2) arrinput(char *s, const char *cs int sz):				return type depls on control string cs.
* 4) print_array(char *s, const char *cs int *a, int sz):		return type void.
*
* Additional definitions for use:
* 1) Int(x): can be used to convert string returned by input() to integer.
* 2) Float(x): can be used to convert string returned by input() to float.
* 3) arrlen(x): can be used to find length of pre-sized array.
* 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Additional Function definitions for ease of code and performing certain tasks
*/

#define arrlen(x) (sizeof(x)/sizeof((x)[0]))
#define Int(x) atoi(x)
#define Float(x) atof(x)

/*
* For removing leading and trailing whitespaces in strings. Here, it has been used for trimming control strings.
* Custom created for internal use only.
*/
size_t trim(char *s, char *s2)
{
	char *l;
	size_t ans;
	while(isspace(*s2)) s2++;
	l = s2 + strlen(s2) - 1;
	while(l>s2 && isspace(*l)) l--;
	l++;
	ans = l-s2;
	memcpy(s, s2, ans);
	s[ans] = 0;
	return ans;
}

/*
* Takes string to be printed before input and prints it. Then takes user input as string and returns it.
* For integer or float input, consider using Int and Float functions to convert the string returned.
* Eg:-
* int n = Int(input("")); will print nothing and store integer input of user in n.
*
* float m = Float(input("Enter m: ")); will print given string and store float input given by user in m.
*
* char *s = input(""); will print nothing and store string input given by user in s.
*
*/
char *input(char *s)
{
	printf("%s", s);
	char *n = (char *)malloc(1000*sizeof(char));
	fgets(n, sizeof(n), stdin);
	return n;
}

/*
* Takes string to be printed and prints it. Then uses control string 'cnstr' and size 'sz' of array provided
* to return an array of required datatype and size, along with user input.
* Eg:-
* int *a = arrinput("Enter array: ", "%d", 5); will print the given string, take 5 integers as input from user
* 											   and return the array of 5 integers.
* For float, use control string "%f".
* Different forms of control string can also be passed, like "%2d", "%.3f", etc.
*
*/
void *arrinput(char *s, char *cnstr, int sz)
{
	char cs[32];
	trim(cs, cnstr);
	printf("%s", s);
	int i;
	if(strlen(cs)>1&&(cs[0]=='%'&&(cs[strlen(cs)-1]=='d')))
	{
		int *a = (int *)malloc(sz*sizeof(int));
		for(i=0; i<sz; i++) scanf((const char*)(cs), &a[i]);
		return a;
	}
	else if(strlen(cs)>1&&(cs[0]=='%'&&(cs[strlen(cs)-1]=='f')))
	{
		float *a = (float *)malloc(sz*sizeof(float));
		for(i=0; i<sz; i++) scanf((const char*)(cs), &a[i]);
		return a;
	}
}

/*
* Takes string to be printed and prints it, then takes control string 'cnstr', array 'a' and its size 'sz'
* to print the given array.
* Eg:-
* print_array("The array is: \n", "%d", a, 5); will first print the given string, then print the given integer
* 											array of size 5. Each integer will be separated be space.
* For float, use control string "%f".
* Different forms of control string can also be passed, like "%2d", "%.3f", etc.
*
*/
void print_array(char *s, char *cnstr, void *a, int sz)
{
	printf("%s", s);
	char cs[32];
	trim(cs, cnstr);
	strcat(cs, " ");
	int i;
	for(i=0; i<sz; i++) 
	{
		if(strlen(cs)>1&&(cs[0]=='%'&&(cs[strlen(cs)-2]=='d')))
		{
			printf((const char*)(cs), *((int *)a+i));
		}
		else if(strlen(cs)>1&&(cs[0]=='%'&&(cs[strlen(cs)-2]=='f')))
		{
			printf((const char*)(cs), *((float *)a+i));
		}
	}
	printf("\n");
}

#endif
