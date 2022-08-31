/**
 * @file min_elem_using_two_vars.cpp
 * @brief Get the minimum element from the stack in O(1)
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */

#include <iostream>
#include <limits.h>

using namespace std;

typedef struct stack{
    int val;
    int min;
}stack;

static int top = -1;

stack* createStack(int size)
{
    stack* s = (stack *)malloc(sizeof(stack)*size);
    s[0].min = INT_MAX;
    return s; 
}

void push(stack *s, int data)
{
    int minVal = (top == -1) ? data : std::min(data, s[top].min);
    s[++top].val = data;
    s[top].min = minVal;
}

void pop(stack* s)
{
    if(top != -1)
    {
        int popped = s[top--].val;
    }
}

int getMin(stack* s)
{
    if(top != -1)
    {
        return s[top].min;
    }
    return -1;
}

int main()
{
    stack *s = createStack(4);
    push(s, 3);
    push(s, 4);
    push(s, 2);
    push(s, 1);
    cout << getMin(s) << endl;
    pop(s);
    pop(s);
    cout << getMin(s) << endl;
    return 0;
}