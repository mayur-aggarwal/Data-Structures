/**
 * @file Two_Sum.cpp
 * @brief Given an array of integers nums and an integer target, 
 * return the indices i and j such that nums[i] + nums[j] == target and i != j.
 * 
 * You may assume that every input has exactly one pair of 
 * indices i and j that satisfy the condition.
 * 
 * Return the answer with the smaller index first.
 * 
 * Example 1:
 * 
 * Input: 
 * nums = [3,4,5,6], target = 7
 * 
 * Output: [0,1]
 *
 * Reference: Neetcode150
 */


/**
 *  @brief: twoSum
 *  @param IN: vector<int>& nums
 *  @param IN: int target
 *  @return: vector<int>
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
		for(int i = 0; i < nums.size(); i++){
			int diff = target - nums[i];
			if(um.find(diff) != um.end()){
				return{um[diff], i};
			}
			um.insert({nums[i],i});
		}
    }
};

