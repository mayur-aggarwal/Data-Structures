/**
 * @file Contains Duplicate.cpp
 * @brief Given an integer array nums, return true if any value 
 * appears more than once in the array, otherwise return false.

 * Example 1:
 * 
 * Input: nums = [1, 2, 3, 3]
 * 
 * Output: true
 *
 * Reference: Neetcode150
 */


/**
 *  @brief: hasDuplicate
 *  @param IN: vector<int>& nums
 *  @return: bool
 */
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for(int i = 0; i < nums.size(); i++)
        {
            if(us.count(nums[i])){
                return true;
            }
            us.insert(nums[i]);
        }
        return false;
    }
};
