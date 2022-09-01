/**
 * @file stack_2queue.cpp
 * @brief create stack using 2 queues (Array version)
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */
#include <iostream>

using namespace std;


/*
Usage :
-------
	Queue* q1 = createQueue(capacity);
	Queue* q2 = createQueue(capacity);
	push(q1, q2, 10);
	push(q1, q2, 20);
	push(q1, q2, 30);
	
	pop(q1);	// return 30
	
Note:
-----
	We can make q1 and q2 as global then push and pop api would like below:
	push(10);
	push(20);
	push(30);
	pop();	// return 30
	top();	// will give top element in stack
*/

typedef struct Queue{
	int data;
	int front, rear, size;
	int capacity;
	int *arr;
}Queue;

Queue* createQueue(int capacity)
{
	Queue* q = new Queue;
	q->front = q->rear = q->size = 0;
	q->capacity = capacity;
	q->arr = (int *)malloc(q->capacity*sizeof(int));
	return q;
}

int isEmpty(Queue* q)
{
	return (q->size == 0);
}

int isFull(Queue* q)
{
	return(q->size == q->capacity-1);
}

void enqueue(Queue* q, int data)
{
	if(isFull(q))
	{
		cout << "Queue is Full\n";
		if(q->front > q->rear)
		{
			q->front = q->rear = 0;
			cout << "Queue front > rear, reset.. Now add data\n";
		}
		return;
	}
	q->arr[q->rear++] = data;
	q->size = q->size + 1;
}

void dequeue(Queue* q)
{
	if(isEmpty(q))
	{
		cout << "Empty!!\n";
		return;
	}
	int item = q->arr[q->front++];
	q->size = q->size - 1;
}

int front(Queue* q)
{
	if(isEmpty(q))
	{
		return -1;
	}
	return q->arr[q->front];
}

void push(Queue* q1, Queue* q2, int data)
{
	enqueue(q2, data);
	while(!isEmpty(q1))
	{
		enqueue(q2, front(q1));
		dequeue(q1);
	}
	Queue q = *q1;
	*q1 = *q2;
	*q2 = q;
}

int pop(Queue* q)
{
	int popped = front(q);
	dequeue(q);
	return popped;
}

// Enable below function after making q1 and q2 as global
/*
int top()
{
    int topped = front(q1);
    return topped;
}*/