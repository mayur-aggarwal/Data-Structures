#include <iostream>

using namespace std;

//A structure to represent stack
struct stack{
	int data;
	struct stack* next;
};

struct stack* top;

int isEmpty()
{
	return (top == NULL);
}

void push(int data)
{
	struct stack* temp;
	temp = new stack();
	temp->data = data;
	temp->next = top;
	top = temp;
}

int pop()
{
	if(top == NULL) return -1;
	struct stack* temp;
	temp = top;
	int popped = temp->data;
	top = top->next;
	free(temp);
	return popped;
}

int peek()
{
	if(!isEmpty())
	{
		return top->data;
	}
	return -1;
}

int main()
{
	push(10);	//[10]
	push(20);	//[20, 10]
	push(30);	//[30, 20, 10]
	cout << pop();	//[20, 10]
	return 0;
}