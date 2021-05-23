/**
 * @file findLoop_LL.cpp
 * @brief find loop in the linked list
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
Output: Loop Detected
*/
/**
 *  @brief: Function to detect loop in the list
 *  @param IN: Node* head : linked list head pointer
 *  @return: bool
 */
bool findLoop(Node* head)
{
	if(head == NULL)
		return false;
	Node* slow = head;
	Node* fast = head;
	while(slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			return true;
	}
	return false;
}