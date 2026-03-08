/**
 * @file remove_every_kth_node.cpp
 * @brief remove_every_kth_node
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */
#include <include.h>

/*
Example:
Input: LinkedList: 1 -> 2 -> 3 -> 4 -> 5 -> 6, k = 2
Output: 1 -> 3 -> 5 
*/

typedef struct _node node;

struct _node{
    int data;
    node *next;
};

void print_list(node* head)
{
    node* curr = head;
    while(curr != NULL)
    {
        printf("%d->"curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

node* sortedInsert(node* head, int data)
{
    node* curr;
    node* newnode = new node;
    newnode->data = data;
    newnode->next = NULL;
    while(head == NULL || head->data > data)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    curr = head;
    while(curr->next != NULL && curr->next->data < data)
    {
        curr = curr->next;
    }
    newnode->next = curr->next;
    curr->next = newnode;
    return head;
}

node* remove_every_kth_node(node* head, int k)
{
	node* curr = head;
	node* prev = NULL;
	int count = 0;
	while(curr != NULL){
		count++;
		if(count % k == 0)
		{
			if(prev != NULL){
				prev->next = curr->next;
			}
			else{
				head = curr->next;
			}
			curr = prev != NULL ? prev->next : head;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
	return head;
}

int main(int argc, char** argv)
{
    node* head = NULL;
    head = sortedInsert(head, 5);
    head = sortedInsert(head, 1);
    head = sortedInsert(head, 3);
    head = sortedInsert(head, 6);
    head = sortedInsert(head, 4);
    head = sortedInsert(head, 2);
    print_list(head);
    head = remove_every_kth_node(head, 2, true);
    print_list(head);
  return 0;
}
