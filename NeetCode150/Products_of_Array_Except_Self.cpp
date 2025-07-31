/**
 * @file Products_of_Array_Except_Self.cpp
 * @brief Given an integer array nums, return an array output
 * where output[i] is the product of all the elements of nums except nums[i].

 * 	Each product is guaranteed to fit in a 32-bit integer.
 * 
 * 	Follow-up: Could you solve it in 
 * 	O(n)
 * 	O(n) time without using the division operation?
 * 
 * 	Example 1:
 * 
 * 	Input: nums = [1,2,4,6]
 * 
 *  Output: [48,24,12,8]
 *
 * Reference: Neetcode150
 */


/**
 *  @brief: productExceptSelf
 *  @param IN: int : vector<int>& nums
 *  @return: vector<int>
 */

class Solution{
	public:
		vector<int> productExceptSelf(vector<int>& nums){
			int n = nums.size();
			vector<int> res(n);
			vector<int> pref(n);
			vector<int> suff(n);
			pref[0] = 1;
			suff[n-1] = 1;
			for(int i = 1; i < n; i++){
				pref[i] = nums[i-1] * pref[i-1];
			}
			for(int i = n - 2; i >= 0; i--){
				suff[i] = nums[i+1] * suff[i+1];
			}
			for(int i = 0; i < n; i++){
				res[i] = pref[i] * suff[i];
			}
			return res;
		}
};