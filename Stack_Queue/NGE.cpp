/**
 * @file NGE.cpp
 * @brief Get the next greater element in the array
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */

#include <iostream>
#include <stack>

using namespace std;

void NGE(int *arr, size_t n)
{
  stack<int> s;
  s.push(arr[0]);
  for(int i = 1; i < n; i++)
  {
    if(s.empty())
    {
      s.push(arr[i]);
    }
    while(!s.empty() && arr[i] > s.top())
    {
      cout << s.top() << " --> " << arr[i] << endl;
      s.pop();
    }
    s.push(arr[i]);
  }
  while(!s.empty())
  {
    cout << s.top() << " --> -1" << endl;
    s.pop();
  }
}

int main()
{
  int arr[] = {11, 23, 21, 26, 3};
  int n = sizeof(arr)/sizeof(arr[0]);
  NGE(arr, n);
  return 0;
}
