/**
 * @file findSqRoot.cpp
 * @brief Using Binary Search
 *
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */

 unsigned int findroot(unsigned int n)
 {
     if(n == 0 || n == 1)
     {
         return n;
     }
     int start = 1, end = n, ans = 0, mid;
     while(start <= end)
     {
         mid = start + (end - start)/2;
         if(mid * mid == n)
         {
             return mid;
         }
         else if(mid * mid < n)
         {
            start = mid + 1;
            ans = mid;
         }
         else if(mid * mid > n)
         {
             end = mid - 1;
         }
     }
     return ans;
 }