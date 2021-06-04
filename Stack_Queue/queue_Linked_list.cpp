/**
 * @file queue_Linked_list.cpp
 * @brief create queue using linked list
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
	struct qnode *next;
};

struct q{
	struct qnode *front, *rear;
};

struct q* createQ()
{
	struct q* q = new q;
	q->front = q->rear = NULL;
	return q;
}

void enq(struct q* q, int data)
{
	struct qnode* temp = (struct q*)malloc(sizeof(qnode));
	temp->data = data;
	temp->next = NULL;
	if(q->rear == NULL)
	{
		q->rear = q->front = temp;
		return;
	}
	q->rear->next = temp;
	q->rear = temp;
}

void deq(struct q* q)
{
	if(q->front == NULL)
		return;
	struct q* temp = q->front;
	q->front = q->front->next;
	free(temp);
}