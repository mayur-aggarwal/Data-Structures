/**
 * @file array_rotation.cpp
 * @brief Rotate the array by k
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */

#include <iostream>

using namespace std;

/*
Example
arr[] = {1, 2, 3, 4, 5, 6}
n = 6
k = 4

output = 5, 6, 1, 2, 3, 4
*/

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

void arrayRotation(int *arr, int n, int d) 
{
	d = d%n;
	int g_c_d = gcd(n, d);
	int i, j, k, temp;
	for(i = 0; i < g_c_d; i++)
	{
		temp = arr[i];
		j = i;
		while(1)
		{
			k = j + d;
			if(k >= n)
				k = k - n;
			if(k == i)
				break;
			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}
}