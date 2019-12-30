#include <stdio.h>

#define N 10

int arr[N] = { 1,4,5,2,3, 3 };
int aux[N];

void merge(int l, int m, int r)
{
	for (int i = l; i <= r; i++)
		aux[i] = arr[i];
	int copyAtIndex = l;
	int h = m + 1;
	while (l <= m && h <= r)
	{
		if (aux[l] < aux[h])
			arr[copyAtIndex++] = aux[l++];
		else
			arr[copyAtIndex++] = aux[h++];
	}
	while (l <= m)
	{
		arr[copyAtIndex++] = aux[l++];
	}
	while (h <= r)
	{
		arr[copyAtIndex++] = aux[h++];
	}
}

void mergesort(int low, int high)
{
	if (low == high)
		return;
	int mid = (low + high) / 2;
	mergesort(low, mid);
	mergesort(mid + 1, high);
	merge(low, mid, high);
}

int main()
{
	mergesort(0, 5);
	return 0;
}