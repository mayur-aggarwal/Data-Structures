#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int> &arr)
{
	for(int &val:arr)
	{
		cout << val << " ";
	}
	cout <<"\n";
}

void stable_sortedArr(vector<int> &arr)
{
	for(int i = 0; i < n - 1; i++)
	{
		int min_idx = i;
		for(j = i+1; j < n; j++)
		{
			if(arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}
		int key = arr[min_idx];
		for(int k = min_idx; k > i; k--)
		{
			arr[k] = arr[k-1];
		}
		arr[i] = key;
	}
}

void sortedArr(vector<int> &arr)
{
	for(int i = 0; i < n - 1; i++)
	{
		int min_idx = i;
		for(j = i+1; j < n; j++)
		{
			if(arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}
		swap(arr[i], arr[min_idx]);
	}
}

int main(void)
{
	vector<int> arr = {54, 15, 27, 22, 10};
	cout << "Orignal Arr: "
	printArr(arr);
	sortedArr(arr);
	cout << "Sorted Arr: "
	printArr(arr);
	return 0;
}