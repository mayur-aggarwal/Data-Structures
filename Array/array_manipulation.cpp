/**
 * @file ArrayManipulation.cpp
 * @brief Get max number after processing queries
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
n = 10
queries = [[1,5,3], [4,8,7], [6,9,1]]

Queries are interpreted as follows:

    a b k
    1 5 3
    4 8 7
    6 9 1
	
arrayManipulation has the following parameters:

int n - the number of elements in the array
int queries[q][3] - a two dimensional array of queries where each queries[i] contains three integers, a, b, and k.
*/

long arrayManipulation(int n, int m, int** queries) 
{
	long *arr = (int *)malloc(n*sizeof(int)+1);
	for(int i = 0; i <= n; i++) arr[i] = 0;
	long a, long b, long k;
	for(int i = 0; i < m; i++)
	{
		a = queries[i][0];
		b = queries[i][1];
		k = queries[i][2];
		arr[a] = arr[a] + k;
		if(b+1 <= n)
			arr[b+1] = arr[b+1] - k;
	}
	long max = 0, sum = 0;
	for(int i = 0; i <= n; i++)
	{
		sum +=arr[i];
		if(max < sum)
			max = sum;
	}
	return max;
}