/**
 * @file stack_2Q_LL.cpp
 * @brief Implement stack using 2 queues (linked list Version)
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */

#include <iostream>

using namespace std;

struct qnode{
    int data;
    struct qnode* next;
};

struct q{
    struct qnode *front, *rear;
};

struct q* createQ(void)
{
    struct q* q = new struct q;
    q->front = q->rear = NULL;
    return q;
}

struct q* q1 = createQ();
struct q* q2 = createQ();

void pop(void);

void enQ(struct q* q, int data)
{
    struct qnode* qnode = new struct qnode;
    qnode->data = data;
    qnode->next = NULL;
    if(q->front == NULL)
    {
        q->front = q->rear = qnode;
        return;
    }
    q->rear->next = qnode;
    q->rear = qnode;
}

int deQ(struct q* q)
{
    if(q->front == NULL)
        return -1;
    struct qnode* temp = q->front;
    int popped = temp->data;
    q->front = q->front->next;
    delete temp;
    return popped;
}

int top(void)
{
    if(q1->front != NULL)
        return q1->front->data;
    return -1;
}

void push(int data)
{
    enQ(q2, data);
    while(q1->front != NULL)
    {
        enQ(q2, top());
        pop();
    }
    struct q* temp = q1;
    q1 = q2;
    q2 = temp;
}

void pop(void)
{
    deQ(q1);
}

int main()
{
    push(1);
    push(4);
    push(2);
    pop();
    pop();
    return 0;
}