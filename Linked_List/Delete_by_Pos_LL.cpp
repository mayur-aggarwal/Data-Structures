/**
 * @file delete_By_pos.cpp
 * @brief delete the node by given position
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
list[] = {1,2,3,4,5,6,7,8}
position = 4
Output: 1 2 3 4 6 7 8
*/
/**
 *  @brief: Function to delete the node from the given position
 *  @param IN: Node* head : linked list head pointer
 *  @param IN: int pos	  : position (0-len of ll)
 *  @return: int
 */
Node* deleteByPosition(Node* head, int pos)
{
	if(head == NULL)
		return head;
	Node* temp = head;
	Node* prev;
	if(pos == 0)
	{
		head = head->next;
		free(temp);
		return head;
	}
	for(int i = 0; temp != NULL && i < pos; i++)
	{
		prev = temp;
		temp = temp->next;
	}
	if(temp == NULL)
		return head;
	prev->next = temp->next;
	free(temp);
	return head;
}