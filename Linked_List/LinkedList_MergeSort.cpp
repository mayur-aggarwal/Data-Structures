/**
 * @file LinkedList_MergeSort.cpp
 * @brief Sort the unsorted linked list
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

/**
 *  @brief: Function to insert node in linked list
 *  @param IN: Node* head : linked list node
 *  @param IN: int data : data
 *  @return: Node*
 */
Node* insert(Node* head, int data)
{
    Node* newnode = new Node;
    newnode->data = data;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        return head;
    }
    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    return head;
}
/**
 *  @brief: Function to print linked list
 *  @param IN: Node* head : linked list node
 *  @return: void
 */
void printlist(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


/**
 *  @brief: Function to merge two parts of linked list
 *  @param IN: Node* a
 *  @param IN: Node* b
 *  @return Node*
 */

Node* Merged(Node*a, Node*b)
{
    Node* mergedlist = NULL;
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    if(a->data <= b->data)
    {
        mergedlist = a;
        mergedlist->next = Merged(a->next, b);
    }
    else
    {
        mergedlist = b;
        mergedlist->next = Merged(a, b->next);
    }
    return mergedlist;
}


/**
 *  @brief: Function to split the linked list in two parts
 *  @param IN: Node* head : head of linked list
 *  @param OUT: Node** a
 *  @param OUT: Node** b
 *  @return void
 */

void splitlist(Node* head, Node** firsthalf, Node** secondhalf)
{
    Node* slow = head;
    Node* fast = head->next;
    /* we can directly run the while loop with
        slow by 1 & fast by 2 steps but need to check the
        base condition for slow pointer for last & 2nd last node
    */
    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    /* we have found the mid of the list */
    *firsthalf = head; // point to head
    *secondhalf = slow->next;   // point to mid of list
    slow->next = NULL;
}

/**
 *  @brief: Function calls recursively, splits list, sort & finally merged
 *  @param IN: Node** head : linked list node
 *  @return: void
 */

void MergeSort(Node** head)
{
    Node* temp = *head;
    /* Base condition for 0 & 1st node*/
    if(temp == NULL || temp->next == NULL){
        return;
    }
    Node* a;
    Node* b;
    /* split the list, head to middle, mid+1 to NULL*/
    splitlist(temp, &a, &b);

    MergeSort(&a);
    MergeSort(&b);
    /* Sort the data & start merging */
    *head = Merged(a, b);
}

int main()
{
    /*
        Example:
        Create unsorted linked list

        28->6->4->15->30
    */
    /* Creating Unsorted Linked list */
    Node* head = NULL;
    head = insert(head, 20);
    head = insert(head, 6);
    head = insert(head, 4);
    head = insert(head, 15);
    head = insert(head, 30);
    /*******************************/
    cout << "Unsorted Linked List: \n";
    printlist(head);
    /* call my merge sort function to sort the list based on data */
    MergeSort(&head);
    cout << "Sorted Linked List: \n";
    printlist(head);
    return 0;
}
