/**
 * @file Group_Anagram.cpp
 * @brief Given an array of strings strs, group all anagrams 
 * together into sublists. You may return the output in any order.
 * 
 * An anagram is a string that contains the exact same characters as 
 * another string, but the order of the characters can be different.
 * 
 * Example 1:
 * 
 * Input: strs = ["act","pots","tops","cat","stop","hat"]
 * 
 * Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]
 *
 * Reference: Neetcode150
 */


/**
 *  @brief: groupAnagrams
 *  @param IN: vector<string>& strs
 *  @return: vector<vector<string>>
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> um;
	for(auto str:strs){
		vector<int> count(26,0);
		for(char c:str){
			count[c - 'a']++;
		}
		string key;// = to_string(count[0]);
		for(int i = 0; i < 26; i++){
			key += ',' + to_string(count[i]);
		}
		um[key].push_back(str);
	}
	vector<vector<string>> res;
	for(auto pair:um){
		res.push_back(pair.second);
	}
	return res;
};
