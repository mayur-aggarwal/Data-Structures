/**
 * @file find_Missing_no.cpp
 * @brief Missing number in an array
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */
#include <iostream>

using namespace std;

/**
 *  @brief: Function to find missing number in an array`
 *  @param IN: int arr[]
 *  @return: unsigned int
 */
 unsigned int missing_no(int *arr, int n)
 {
	 int a = arr[0];
	 int b = 1;
	 for(int i = 2; i <= n, i++)
	 {
		 b ^= i;
	 }
	 for(int i = 1; i < n; i++)
	 {
		 a ^= arr[i];
	 }
	 return (a^b);
 }