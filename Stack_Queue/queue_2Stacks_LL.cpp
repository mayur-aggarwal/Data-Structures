/**
 * @file queue_2Stacks_LL.cpp
 * @brief Implement Queue using 2 stacks (linked list Version)
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */

#include <iostream>

using namespace std;

struct stacknode {
    int data;
    struct stacknode* next;
};

struct stack {
    struct stacknode* top;
};

struct stack* createS(void)
{
    struct stack* s = new struct stack;
    s->top = NULL;
    return s;
}

struct stack* s1 = createS();
struct stack* s2 = createS();

void push(struct stack* s, int data)
{
    struct stacknode* snode = new struct stacknode;
    snode->data = data;
    snode->next = s->top;
    s->top = snode;
}

void pop(struct stack* s)
{
    if (s->top != NULL) {
        struct stacknode* temp = s->top;
        s->top = s->top->next;
        delete temp;
    }
}

int top(struct stack* s)
{
    return s->top->data;
}

void enQ(int data)
{
    while (s1->top != NULL)
    {
        push(s2, top(s1));
        pop(s1);
    }
    push(s1, data);
    while (s2->top != NULL)
    {
        push(s1, top(s2));
        pop(s2);
    }
}

void deQ(void)
{
    pop(s1);
}

int main()
{
    enQ(1);
    enQ(4);
    enQ(2);
    deQ();
    deQ();
    return 0;
}