/**
 * @file Multiply_Two_Strings.cpp
 * @brief Multiply two int given in form of strings << 43. Multiply Strings>>
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
 *
 * Example 1:
 *
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * Example 2:
 *
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * Note:
 *
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0 itself.
 * You must not use any built-in BigInteger library or convert the inputs to integer directly.
 *
 * For more details please visit https://leetcode.com/problems/multiply-strings/
 *
 * @author Mayur Aggarwal
 * @bug No known bugs.
 * Contact: aga.mayur@gmail.com
 *
 */

#include <iostream>

using namespace std;

#define DEBUG 0

/**
 *  @brief: Multiplies two numbers in string format
 *  @param IN: string num1
 *  @param IN: string num2
 *  @return: string
 */

 /*
    Submission Detail
    311 / 311 test cases passed.            Status: Accepted
    Runtime: 4 ms
    Memory Usage: 6.7 MB
 */
 class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        int len = len1+len2;
#if DEBUG
        cout << len << " "<<len1 << " " << len2 << endl;
#endif // DEBUG
        string arr(len, '0');
        for(int i = len1-1; i >= 0; i--)
        {
            for(int j = len2-1; j >= 0; j--)
            {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = (arr[i+j+1]-'0') + mul;
                arr[i+j] = (arr[i+j] - '0') + sum/10 + '0';
                arr[i+j+1] = sum%10 + '0';
            }
        }
        int idx = -1;
        /*  Below logic to removes leading zeros if any
            like 056088 => 56088
        */
        for(int i = 0; i < len; i++)
         {
#if DEBUG
            cout << "Original :\n arr[i]: " << arr[i] << endl;
#endif // DEBUG
             if(arr[i] != '0')
             {
                 int j;
                 idx = i;
#if DEBUG
                cout << "idx = " << idx << endl;
#endif // DEBUG
                 for( j = 0; j < len-i; j++)
                 {
                     arr[j] = arr[idx++];
#if DEBUG
                    cout << "Modified after removing leading zeros\n arr[i]: " << arr[i] << endl;
#endif // DEBUG
                 }
#if DEBUG
                 cout << "idx:"<< idx << endl;
                 cout << "j => " << j <<endl;
#endif // DEBUG
                 arr[j] = '\0';
                 break;
             }
         }
#if DEBUG
        /* Below function is c++ utility function
            easy to implement with this */
        int it = arr.find_first_not_of("0");
        return ( it < 0  ? "0" : arr.substr(it) );
#else
        /* Need to handle explicitly for cases like
        1)
            "0"
            "0"
            Expected output: "0"
        2)
            "00"
            "00"
            Expected output: "000"
        3)
            "000"
            "000"
            Expected output: "00000"
        4)
            "1234"
            "0"
            Expected output: "0"
        5)
            "2"
            "3"
            Expected output: "6"
        */
        //All corner cases handled
        if((idx == -1) && ((len1 == 1) || (len2 == 1)))
        {
            return "0";
        }
        else if(idx == -1){
            arr[len-1] = '\0';
        }
        return arr;
#endif
    }
};
