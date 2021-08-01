/**
 * @file reverse_alternate_k_nodes.cpp
 * @brief reverse_alternate_k_nodes
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */
#include <iostream>

using namespace std;

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
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "NULL\n";
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

node* rev_alternate_k_nodes(node* head, int k, bool b)
{
    int cnt = 0;
    node* curr = head;
    node* prev = NULL;
    node* temp;
    if(head == NULL) return NULL;
    while(curr != NULL && cnt++ < k)
    {
        temp = curr->next;
        if(b == true)
            curr->next = prev;
        prev = curr;
        curr = temp;
    }
    if(b == true)
    {
        head->next = alternate_k(curr, k, !b);
        return prev;
    }
    else{
        prev->next = alternate_k(curr, k, !b);
        return head;
    }
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
    head = rev_alternate_k_nodes(head, 2, true);
    print_list(head);
  return 0;
}
