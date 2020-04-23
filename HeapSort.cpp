/**
 * @file heapsort.cpp
 * @brief Building MinHeap, MaxHeap and other asscoiated API's like delete, change, getMin, getMax etc
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */

#include <iostream>

using namespace std;

#define MAX_SIZE 100000
#define DEBUG 0

#define MUL(i) (i<<1)   //(2*i)

#define PARENT(i) (i-1)/2
#define LCHILD(i) (2*i)+1
#define RCHILD(i) (2*i)+2

/* heap related vars */
int arr[7];
int hsize;

#if 0
struct heapsort{
    int hsize;
    int capacity;
    int *arr;   //can dynamic memory
};
#endif // 0

void MinHeapify(int );
int extractMin();
void changeValue(int , int );
void deleteKey(int );

/**
 *  @brief: Init the Heap
 *  @param: void
 *  @return: void
 */
void initHeap()
{
    hsize = 0;
}

/**
 *  @brief: Swaps two values
 *  @param IN: int* : x
 *  @param IN: int* : y
 *  @return: void
 */
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 *  @brief: Maintains the Max heap property
 *  @param IN: int : index
 *  @return: void
 */
void MaxHeapify(int i)
{
    int l = LCHILD(i);
    int r = RCHILD(i);
    int largest = i;
    if(l < hsize && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    if(r < hsize && arr[r] > arr[largest])
        largest = r;
    if(largest != i)
    {
        swap(&arr[i],&arr[largest]);
        MaxHeapify(largest);
    }
}

/**
 *  @brief: removes minimum node from the tree and maintain heap property
 *  @param: void
 *  @return: int
 */
int extractMin()
{
    if(hsize <= 0)return INT_MAX;
    if(hsize == 1)
    {
        hsize--;
        return arr[0];
    }
    int temp = arr[0];
    arr[0] = arr[hsize-1];
    hsize--;
    MinHeapify(0);
    return temp;
}

/**
 *  @brief: changes values of given index by new value
 *  @param IN: int : index to delete
 *  @param IN: int : new value
 *  @return: void
 */
void changeValue(int i, int newvalue)
{
    arr[i] = newvalue;
    while(i != 0 && arr[PARENT(i)] > arr[i])
    {
        swap(&arr[PARENT(i)], &arr[i]);
        i = PARENT(i);
    }
}

/**
 *  @brief: deletes the specified index
 *  @param IN: int : index to delete
 *  @return: void
 */
void deleteKey(int i)
{
    changeValue(i, INT_MIN);
    extractMin();
}

/**
 *  @brief: Maintains the Min heap property
 *  @param IN: int : index
 *  @return: void
 */

void MinHeapify(int i)
{
    int l = LCHILD(i);
    int r = RCHILD(i);
    int smallest = i;
    if(l < hsize && arr[l] < arr[i])
        smallest = l;
    else
        smallest = i;
    if(r < hsize && arr[r] < arr[smallest])
        smallest = r;
    if(smallest != i)
    {
        swap(&arr[i],&arr[smallest]);
        MinHeapify(smallest);
    }
}

/**
 *  @brief: building MinHeap
 *  @param IN: int : Key to add
 *  @return: void
 */

 void insertNode(int data)
 {
     if(hsize >= MAX_SIZE)
     {
         cout << "overflow, couldn't add key\n";
         return;
     }
     hsize++;
     int i = hsize - 1;
     arr[i] = data;
     while(i != 0 && arr[PARENT(i)] > arr[i])
     {
         swap(&arr[PARENT(i)], &arr[i]);
         i = PARENT(i);
     }
 }

 int getMin()
 {
     return arr[0];
 }

 int getMax()
 {

     return arr[0];
 }

int main()
{
    initHeap();
    insertNode(3);
    insertNode(2);
    insertNode(5);
    insertNode(15);
    insertNode(4);
    insertNode(45);
    cout << getMin() << endl;
#if DEBUG
    cout << "MinHeap\n";
    for(int i = 0; i < hsize; i++)
        cout << arr[i] << " ";
    cout << endl;
#endif // DEBUG
    deleteKey(1);
#if DEBUG
    cout << "1st index key is deleted\n";
    for(int i = 0; i < hsize; i++)
        cout << arr[i] << " ";
    cout << endl;
#endif // DEBUG
    changeValue(4, 20);
#if DEBUG
    cout << "Change value of 4th index to 20\n";
    for(int i = 0; i < hsize; i++)
        cout << arr[i] << " ";
    cout << endl;
#endif // DEBUG
    cout << extractMin() << endl;
#if DEBUG
    cout << "Min node is extracted/removed\n";
    for(int i = 0; i < hsize; i++)
        cout << arr[i] << " ";
    cout << endl;
#endif // DEBUG

    /*  Now build MaxHeap from MinHeap  of
        height of tree i = (hsize/2)-1 : if hsize = 6
        index = 10/2 = 5 - 1 = 4
        -------------------------
        |   |   |   |   |   |   |
        -------------------------
          0 | 1   2   3   4   5 => hsize = 6
    */

    for(int i = (hsize/2)-1; i >= 0; i--)
    {
        MaxHeapify(i);
    }
    cout << getMax() << endl;
#if DEBUG
    cout << "MaxHeap\n";
    for(int i = 0; i < hsize; i++)
        cout << arr[i] << " ";
    cout << endl;
#endif // DEBUG
    return 0;
}
