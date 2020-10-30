/**
 * @file factorial.cpp
 * @brief Get factorial of a number
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */

#include <iostream>

using namespace std;

#define REC_FACT 0
#define ITER_FACT 0
#define FACT 1

#if REC_FACT
/* Recursion for small numbers */
int fact_rec(int n)
{
    if(n == 0) return 1;
    return n*fact_rec(n-1);
}
#endif

#if ITER_FACT
/* Iterative */
int fact_iter(int n)
{
    int res = 1;
    if(n == 0) return 0;
    if(n == 1) return 1;
    for(int i = 2; i <= n; i++)
    {
        res = res*i;
    }
    return res;
}

#endif



/* factorial for large numbers like !100 */

#if FACT

#define MAX_SIZE 150

int multiply(int, int, int);

int multiply(int x, int result[], int res_size)
{
    int carry = 0;
    for(int i = 0; i < res_size; i++)
    {
        int prod = result[i] * x + carry;
        result[i] = prod % 10;
        carry = prod / 10;
    }
    while(carry)
    {
        result[res_size] = carry % 10;
        res_size++;
        carry = carry/10;
    }
    return res_size;
}

void fact(int n)
{
    int result[MAX_SIZE];
    result[0] = 1;
    int res_size = 1;
    for(int i = 2; i <= n; i++)
    {
        res_size = multiply(i, result, res_size);
    }
    // print
    for(int j = res_size-1; j >= 0; j--)
    {
        cout << result[j];
    }
    cout << endl;
}

#endif
int main()
{
#if FACT
    fact(5);
    fact(100);
#endif // FACT
#if REC_FACT
    fact_rec(5);
#endif // REC_FACT
#if ITER_FACT
    fact_iter(5);
#endif // ITER_FACT
    return 0;
}
