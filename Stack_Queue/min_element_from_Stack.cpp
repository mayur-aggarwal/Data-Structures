/**
 * @file min_element_from_Stack.cpp
 * @brief Get the minimum element from the stack in O(1)
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */
#include <iostream>

using namespace std;

stack<int> s;
int min_element;

int get_min_element(void)
{
	if(s.empty())
		return -1;
	return min_element;
}

void push(int x)
{
	if(s.empty())
	{
		min_element = x;
		s.push(x);
		return;
	}
	if(x < min_element)
	{
		s.push(2*x-min_element);
		min_element = x;
	}
	else
	{
		s.push(x);
	}
}

int pop(void)
{
	if(s.empty())
		return -1;
	int y = s.top();
	s.pop();
	if(y < min_element)
	{
		int popped = min_element;
		min_element = 2*min_element - y;	// make last minimum element using this formula
	}
	return temp;
}
