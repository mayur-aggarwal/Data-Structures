/**
 * @file intersection_linkedlist.cpp
 * @brief Get Intersection point of two linked list
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
    struct Node* next;
};

int _get_Intersection_Node(int dist, Node* head1, Node* head2)
{
    for(int i = 0; i < dist; i++)
    {
        if(head1 == NULL)
            return -1;      // if list finishes then return -1
        head1 = head1->next;
    }
    while(head1 != NULL && head2 != NULL)
    {
        head1 = head1->next;
        head2 = head2->next;
        if(head1 == head2)
            return head1->data;
    }
    return -1;
}

/**
 *  @brief: Function to get intersection point of 2 linked list
 *  @param IN: Node* head1 : 1st linked list head pointer
 *  @param IN: Node* head1 : 1st linked list head pointer
 *  @return: int
 */
int getIntesectionNode(Node* head1, Node* head2)
{
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    int len1 = 0, len2 = 0;
    int len = 0;

    if(head1 == NULL || head2 == NULL)  //base condition
        return -1;
    while(ptr1 != NULL)     // can make separate function
    {                       // to calculate length of LL
        len1++;             // but this way speed up the time
        ptr1 = ptr1->next;  // saving stack overhead
    }
    while(ptr2 != NULL)
    {
        len2++;
        ptr2 = ptr2->next;
    }
    if(len1 > len2)
    {
        len = len1 - len2;
        return _get_Intersection_Node(len, head1, head2);
    }
    else
    {
        len = len2 - len1;
        return _get_Intersection_Node(len, head2, head1);
    }
}

int main()
{
    /*
        Create two linked lists

        1st 28->6->4->15->30
        2nd 10->15->30

        15 is the intersection point
    */

    Node* newNode;

    // Addition of new nodes
    Node* head1 = new Node();
    head1->data = 10;

    Node* head2 = new Node();
    head2->data = 28;

    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;

    newNode = new Node();
    newNode->data = 4;
    head2->next->next = newNode;

    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;  // Link 1st list to 2nd list

    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;

    head1->next->next->next = NULL;

    cout << "The Node of intersection is " << getIntesectionNode(head1, head2);
    return 0;
}