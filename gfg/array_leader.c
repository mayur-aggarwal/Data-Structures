/**
 * @file array_leader.c
 * @brief Find leaders in an array.
 * https://www.geeksforgeeks.org/dsa/leaders-in-an-array/
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>

// Function to find the leaders in an array
int* leaders(int* arr, int n, int* returnSize) {
    // code here
    int* res = (int*)malloc(n * sizeof(int));
    int count = 0;
    int max_right = arr[n-1];
    res[count++] = max_right;
    for(int i = n - 2; i >= 0; i--)
    {
        if(arr[i] >= max_right)
        {
            max_right = arr[i];
            res[count++] = max_right;
        }
    }
    for(int i = 0; i < count/2; i++)
    {
        int temp = res[i];
        res[i] = res[count-i-1];
        res[count-i-i] = temp;
    }
    *returnSize = count;
    return res;
}

int main() {
    int arr[] = { 61, 61, 17 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int resSize;

    int* result = leaders(arr, n, &resSize);
    for (int i = 0; i < resSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}