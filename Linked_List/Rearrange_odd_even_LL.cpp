/**
 * @file Rearrange_odd_even_LL.cpp
 * @brief Rearrange the odd and even nodes in a linked list
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Date : 13-Mar-2022
 * Copyright (C) 2022-23 {Mayur Aggarwal} <{aga.mayur@gmail.com}> - All Rights Reserved
 * 
 * This file can not be copied and/or distributed without the express
 * permission of {Mayur Aggarwal}
 *
 */

typedef struct _node{
    int data;
    struct _node *next;
}Node;

Node* odd_even(Node* head)
{
    if(head == NULL || head->next == NULL ||
        head->next->next == NULL)
        return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenfirst = head->next;

    while(even != NULL && even->next != NULL && odd != NULL)
    {
        odd->next = even->next;
        odd = even->next;

        even->next = odd->next;
        even = odd->next;
    }
    odd->next = evenfirst;
    return head;
}
