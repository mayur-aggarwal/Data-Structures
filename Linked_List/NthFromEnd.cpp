/**
 * @file NthFromEnd.cpp
 * @brief find the Nth node from the end
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */
#include <iostream>

using namespace std;

/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

/**
 *  @brief: Function to get Nth node from the end of linked list
 *  @param IN: node* //head pointer
 *	@param IN: int	//nth node position from end
 *  @return: int
 */
int nthFromEnd(node* head, int pos)
{
    if(head == NULL)return -1;
    int len = 0;
    node* curr = head;
    while(curr->next != NULL)
    {
        len++;
        curr = curr->next;
    }
    //cout << "len = "<< len << endl;
    curr = head;
    for(int i = 0; curr != NULL && i < len-pos+1; i++)
    {
        curr = curr->next;
    }
    if(curr == NULL) return -1;
    return curr->data;
}