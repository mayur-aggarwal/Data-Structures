/**
 * @file rotate_LL.cpp
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
	if(head == NULL || head->next || k <= 0)
		return head;
	Node* front;
	Node* back = head;
	Node* temp;
	for(int i = 0; i < k-1 && back->next != NULL; i++)
	{
		back = back->next;
	}
	if(back->next != NULL)
	{
		front = back->next;
		temp = front;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = head;
		back->next = NULL;
		head = front;
	}
	
	return head;
}