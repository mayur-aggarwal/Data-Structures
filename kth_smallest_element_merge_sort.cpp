/**
 * @file kth_smallest_element_merge_sort.cpp
 * @brief Find Kth position smallest element in an unsorted array by Merge Sort Approach
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */

#if 0
#include <iostream>
#include <climits>
using namespace std;

#define HSIZE 100001

// Main array having actual elements
int arr[HSIZE];
// Auxilary array
int aux[HSIZE];

void merged(int l, int m, int r)
{
    for(int i = l; i <= r; i++)
    {
        aux[i] = arr[i];
    }
    int h = m+1;
    int cpAt = l;
    while(l <= m && h <= r)
    {
        if(aux[l] < aux[h])
            arr[cpAt++] = aux[l++];
        else
            arr[cpAt++] = aux[h++];
    }
    while(l <= m)
        arr[cpAt++] = aux[l++];

    while(h <= r)
        arr[cpAt++] = aux[h++];
}

void mergesort(int l, int r)
{
    if(l == r) return;
    int mid = (r+l)/2;
    mergesort(l, mid);
    mergesort(mid+1, r);
    merged(l,mid, r);
}

int main() {
	//code
	freopen("input.txt","r",stdin);
	/* ######## TEST CASES #########
        3   ==> No of Test Cases
        6   => No of elements
        7 10 4 3 20 15
        3   => [2nd Test Cases ]No of elements
        5
        7 10 4 20 15
        4
        37
        772 468 507 463 877 690 721 656 126 739 647 161 445 159 162 244 125 84 560 398 329 525 257 158 545 580 990 843 348 456 69 376 897 518 197 51 968
        4
        ############ Expected Output ############
        1st test case : 7
        2nd test case : 15
        3rd test case : 125
	*/
	int T;
	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++)
    {
        int N;
        cin >> N;
        for(int i = 0; i < N; i++)
        {
           cin >> arr[i];
        }
        int K;
        cin >> K;
        mergesort(0, N-1);
        cout << arr[K-1] << endl;
    }
	return 0;
}
#endif
