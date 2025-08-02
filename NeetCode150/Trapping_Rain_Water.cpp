/**
 * @file Trapping_Rain_Water.cpp
 * @brief You are given an array of non-negative integers height 
 * which represent an elevation map. Each value height[i] 
 * represents the height of a bar, which has a width of 1.
 * 
 * Return the maximum area of water that can be trapped between the bars.
 *
 * Input: height = [0,2,0,3,1,0,1,3,2,1]
 *
 * Reference: Neetcode150
 */


/**
 *  @brief: trap
 *  @param IN: vector<strinting>& height
 *  @return: int
 */
class Solution {
public:
    int trap(vector<int>& height) {
		int l = 0, r = height.size()-1;
		int leftmax = height[l], rightmax = height[r];
		int result = 0;
		while(l < r){
			if(leftmax < rightmax){
				l++;
				leftmax = max(leftmax, height[l]);
				res += leftmax - height[l];
			}
			else{
				r--;
				rightmax = max(rightmax, height[r]);
				res += rightmax - height[r];
			}
		}
		return res;
	}
};
