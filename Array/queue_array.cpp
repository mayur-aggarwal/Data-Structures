/**
 * @file queue.cpp
 * @brief create queue
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */

#include <iostream>

using namespace std;

#define MAX 10

int q[MAX];
int front = -1, rear = -1;

int isEmpty()
{
	return (rear == -1);
}

int isFull()
{
	return (rear == MAX-1);
}

void enqueue(int data)
{
	if(isFull())
	{
		cout << "Queue is Full\n";
		return;
	}
	if(front == -1)front = 0;
	arr[++rear] = data;
}

int dequeue()
{
	if(isEmpty())
	{
		cout << "Queue is Empty\n";
		return;
	}
	int d = arr[front++];
	if(front >= rear)
	{
		front = rear = -1;
	}
	return d;
}