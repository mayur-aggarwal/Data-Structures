/**
 * @file find_transition_Point.cpp
 * @brief Find index where is the transition point where 1 begins
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
Input:
N = 5
arr[] = {0,0,0,1,1}
Output: 3
Explanation: index 3 is the transition 
point where 1 begins.

Input:
N = 4
arr[] = {0,0,0,0}
Output: -1
Explanation: Since, there is no "1",
the answer is -1.

*/

int transitionPoint(int arr[], int n) 
{
	int low = 0, high = n-1
	int ans = 0;
	while(low <= high)
	{
		int mid = low+(high-low)/2;
		if(arr[mid] == 1)
		{
			high = mid - 1;
			ans = mid;
			if(mid == 0 || (mid > 0 && arr[mid-1] == 0))	// to check the min idx of 1 at left side
				return ans;					// first occurence of '1' in an array after '0'
		}
		else
		{
			low = mid + 1;
		}
	}
    return -1;
}