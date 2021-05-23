/**
 * @file LoopRemove_LL.cpp
 * @brief find loop and remove from the linked list
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
list[] = {1,2,3,4,5}
			  |___|
Loop -> 5->3
Output: Loop Detected & then remove the loop
*/
/**
 *  @brief: Function to detect loop in the list & remove the loop
 *  @param IN: Node* head : linked list head pointer
 *  @return: Node*
 */
Node* findLoop_Remove(Node* head)
{
	if(head == NULL)
		return head;
	Node* slow = head;
	Node* fast = head;
	while(slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
		{
			break;
		}
	}
	if(slow == fast)
	{
		slow = head;
		if(slow == fast)
		{
			while(fast->next != slow)
			{
				fast = fast->next;
			}
		}
		else
		{
			while(slow->next != fast->next)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		fast->next = NULL;
	}
	return head;
}