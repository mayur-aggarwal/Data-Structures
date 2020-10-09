#if 0
#include <iostream>

using namespace std;

typedef struct _node{
    int data;
    struct _node *next;
}Node;

Node* new_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

Node *sorted_insert_node(Node *head, Node *new_node)
{
    Node* curr;
     cout << "sorted_insert_node -> DEBUG\n";
     cout << "new_node = " << new_node->data << endl;
    if(head == NULL || head->data >= new_node->data)
    {
        new_node->next = head;
        head = new_node;
        return head;
    }
    else
    {
        curr = head;

        while(curr->next != NULL && curr->next->data < new_node->data)
        {
            curr = curr->next;
            cout << "curr = " << curr->data << ", " << "curr->next->data = " << curr->next->data << endl;
        }
        new_node->next = curr->next;
        curr->next = new_node;
        return head;
    }
}

int main()
{
    Node *head = NULL;
    Node *node = new_node(10);
    head = sorted_insert_node(head, node);
  //  print_list(head);
    node = new_node(2);
    head = sorted_insert_node(head, node);
    print_list(head);
    node = new_node(5);
    head = sorted_insert_node(head, node);
    print_list(head);
    node = new_node(1);
    head = sorted_insert_node(head, node);
    node = new_node(4);
    head = sorted_insert_node(head, node);
    print_list(head);
    return 0;
}
#endif
