/**
 * @file kth_smallest_element_heap_sort.cpp
 * @brief Find Kth position smallest element in an unsorted array by minheap Sort Approach
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */
#include <iostream>
#include <climits>
using namespace std;

#define HSIZE 100001
#define PARENT(i) (i-1)/2

int arr[HSIZE];
int heapsize = 0;

int get_min()
{
    return arr[0];
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void min_heapify(int i)
{
    int smallest = INT_MIN;
    cout << "shouldn't come here " << smallest << endl;
    do{
        int l = 2*i + 1;
        int r = 2*i + 2;
        smallest = i;
        if(l < heapsize && arr[i] > arr[l])
            smallest = l;
        else
            smallest = i;
        if(r < heapsize && arr[smallest] > arr[r])
            smallest = r;
        if(smallest!=i)
        {
            swap(&arr[smallest], &arr[i]);
            i = smallest;
            smallest = INT_MIN;
           //min_heapify(smallest);
        }
    }while(smallest!=i);
}

void extract_min()
{
    if(heapsize == 0)
        return ;
    if(heapsize == 1)
    {
        heapsize--;
        //return arr[0];
        return;
    }
    arr[0] = arr[heapsize-1];
    heapsize--;
    min_heapify(0);
}

void kth_min_elem(int arr[], int heapsize, int k)
{
    for(register int i = 0; i < k; i++)
    {
        extract_min();
    }
    cout << get_min() << endl;
}

void insert(int data)
{
    heapsize++;
    int i = heapsize-1;
    arr[i] = data;
    while(i != 0 && arr[PARENT(i)] > arr[i])
    {
        swap(&arr[PARENT(i)], &arr[i]);
        i = PARENT(i);
    }
}

int main() {
	//code
	freopen("input.txt","r",stdin);
	/* Test cases provided in kth_smallest_element_merge_sort.cpp file*/
	int T;
	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++)
    {
        int N;
        cin >> N;
        int data;
        heapsize = 0;
        for(int i = 0; i < N; i++)
        {
           cin >> data;
           insert(data); //7 10 4 3 20 15
        }
        int K;
        cin >> K;
        kth_min_elem(arr, N, K-1);
    }
	return 0;
}

