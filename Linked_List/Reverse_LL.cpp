/**
 * @file reverse_LL.cpp
 * @brief Reverse the list
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
Output: 8 7 6 5 4 3 2 1
*/

Node* reverse(Node* head)
{
	if(head == NULL || head->next == NULL)
		return head;
	Node* curr = head;
	Node* prev = NULL;
	Node* temp = NULL;
	
	while(curr != NULL)
	{
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	head = prev;
	return head;
}