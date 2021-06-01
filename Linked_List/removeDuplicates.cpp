/**
 * @file removeDuplicates.cpp
 * @brief remove duplicate data nodes from the linked list
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
value[] = {1,2,2,4,5,5,7,8}

Output: 1 2 4 5 7 8
*/


Node* removeDuplicateNode(Node* head)
{
	Node* curr = head, *temp;
	while(curr->next != NULL)
	{
		if(curr->data == curr->next->data)
		{
			temp = curr->next;
			curr->next = curr->next->next;
			free(temp);
		}
		else
		{
			curr = curr->next;
		}
	}
	return head;
}