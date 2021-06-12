/**
 * @file rotate_using_circular_LL.cpp
 * @brief Rotate the list from given k
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

Input:
N = 8
value[] = {1,2,3,4,5,6,7,8}
k = 4
Output: 5 6 7 8 1 2 3 4
*/

// This function should rotate list counter-clockwise
// by k and return new head (if changed)
Node* rotate(Node* head, int k)
{
	if(head == NULL) return head;
	Node* curr = head;
	while(curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = head;
	curr = head;
	for(int i = 0; i < k-1; i++)
		curr = curr->next;
	head = curr->next;
	curr->next = NULL;
	return head;
}