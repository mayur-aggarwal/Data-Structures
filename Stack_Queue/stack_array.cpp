#include <iostream>

using namespace std;

//A structure to represent stack
struct stack{
	int top;
	int capacity;
	int *arr;
};

struct stack *createStack(int cap)
{
	struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
	stack->capacity = cap;
	stack->top = -1;
	stack->arr = (int *)malloc(stack->capacity * sizeof(int));
	return stack;
}

int isEmpty(struct stack *stack)
{
	return (stack->top == -1);
}

int isFull(struct stack *stack)
{
	return (stack->top == stack->capacity-1);
}

void push(struct stack *stack, int data)
{
	if(isFull(stack))
		return;
	stack->arr[++stack->top] = data;
}

int pop(struct stack *stack)
{
	if(isEmpty(stack))
		return -1;
	int popped = stack->arr[stack->top--];
	return popped;
}

int main()
{
	struct stack *stack = createStack(10);
	push(stack, 10);	//[10]
	push(stack, 20);	//[20, 10]
	push(stack, 30);	//[30, 20, 10]
	cout << pop(stack);	//[20, 10]
	return 0;
}