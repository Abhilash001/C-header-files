/*
* Author: Abhilash Misra 
* Version: v1.0
* 
* Created: Thursday, September 1, 2016, 9:51:31 PM
* Copyright (C) 2016 under the GNU General Public License. All rights reserved.
* 
*/

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

/*
* Custom header file for algorithmic syntax, i.e, now you can write C programs using (almost) plain english, 
* which is used to write algorithms.
* Examples:-
* 1) if(a==b && a<c) 
*    { 
*     a=c; 
*    } 
*	 can be written as:
*
*    if a is b and a less_than c then
*    a set_to c;
*    END
*
* 2) for(i=0; i<n; i+=2) can be written as: for in_range(i, 0, n, 2)
*
* Many such syntaxes are possible. Keep using to discover. The macros defined below will give you some ideas.
*
* Some functions implemented for ease of code include:
* 1) swap(x,y): swaps values x and y given as parameter.
* 2) min(any number of integers, separated by ','):     finds minimum of integers, return type int.
* 3) max(any number of integers, separated by ','):     finds maximum of integers, return type int.
* 4) sum(any number of integers, separated by ','):     finds sum     of integers, return type int.
* 5) average(any number of integers, separated by ','): finds average of integers, return type float.
* 6) in : checks whether a number is in the Array provided. Syntax is as follows:-
*    if in <array_name> of size <array_size>, <value> _then
*        <some codes to execute>
*    END
*    Example:-
*    if in arr of size 10, 4 _then
*        print "Search successful!" done
*    END
* 
*/

#include <stdio.h>
#include <stdarg.h>
#include "cstio.h"

/*
* Renamed functions of cstio.h header file for simpler code. Previous names can still be used.
*/

#define input_array(x, y, z) arrinput(x, y, z);
#define Input_array(z)       arrinput("", "%d", z);
#define integer_input(x)     Int(input(x));
#define decimal_input(x)     Float(input(x));
#define Integer_input        Int(input(""));
#define Decimal_input        Float(input(""));
#define print_array(x, y, z, w) print_array(x , y, z, w);

/*
* Macros for Algorithmic syntax
*/

#define BOOLEAN int
#define TRUE 1
#define FALSE 0
#define and &&
#define or ||
#define not !
#define is ==
#define isnot !=
#define less_than <
#define greater_than >
#define equals =
#define AND &
#define OR |
#define xor ^
#define mod %
#define set_to =
#define also ,
#define of ,
#define size 
#define Initialize 
#define newline printf("\n");
#define START int main(void){
#define END }
#define Then {
#define Increment ++
#define Decrement --
#define To
#define add +=
#define sub -=
#define multiply *=
#define divide /=
#define integer int
#define decimal float
#define int_array int *
#define integer_array int_array
#define float_array float *
#define String char *
#define if if(
#define then ){
#define _then )){
#define while while(
#define done );
#define print printf(
#define Do )
#define in_range(x, a, b, c) ( (x) = (a); (x) < (b); (x) += (c) )

/*
* Functions for ease of code
*/

#define __swap__(x, y) ({(x) ^= (y); (y) ^= (x); (x) ^= (y);})
#define swap(x, y) __swap__(x, y);
#define min(...) int_functions(1, __VA_ARGS__, -12345)
#define max(...) int_functions(2, __VA_ARGS__, -12345)
#define sum(...) int_functions(3, __VA_ARGS__, -12345)
#define average(...) float_functions(1, __VA_ARGS__, -12345)
#define in isin(


/*
* Defining some constants
*/

#define pi 3.1415926535
#define ep 2.71828
#define INT_MIN -2147483648
#define INT_MAX  2147483647


/*
* Common varidaic function (with variable no. of arguments) for integer return type
* n = 1 for finding min of numbers, 2 for finding max of numbers, 3 for finding sum of numbers
*/

int int_functions(int n, ...)
{
	va_list valist;
	int i, ans;
	n*=1000;
	va_start(valist, n);
	n/=1000;
	if n is 1 then
		ans = INT_MAX;
		for(i = va_arg(valist, int); i!=-12345 ; i = va_arg(valist, int))
		{
			if i<ans Do ans=i;
		}
	END
	else if n is 2 then
		ans = INT_MIN;
		for(i = va_arg(valist, int); i!=-12345 ; i = va_arg(valist, int))
		{
			if i>ans Do ans=i;
		}
	END
	else if n is 3 then
		ans = 0;
		for(i = va_arg(valist, int); i!=-12345 ; i = va_arg(valist, int)) 
			ans = ans + i;
	END
	return ans;
	va_end(valist);
}

/*
* Common varidaic function (with variable no. of arguments) for float return type
* n = 1 for finding average of numbers
*/

float float_functions(int n, ...)
{
	va_list valist;
	int i, c;
	float ans;
	n*=1000;
	va_start(valist, n);
	n/=1000;
	if n is 1 then
		ans = c = 0;
		for(i = va_arg(valist, int); i!=-12345 ; i = va_arg(valist, int),c++) 
			ans = ans + i;
		ans = ans/c;
	END
	return ans;
	va_end(valist);
}

BOOLEAN isin(int *a, int n, int v)
{
	int i;
	for(i=0; i<n; i++)
	{
		if a[i] is v then 
			return i;
		END
	}
	return FALSE;
}

#endif