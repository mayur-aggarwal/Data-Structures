/**
 * @file Valid_Anagram.cpp
 * @brief Given two strings s and t, return true 
 * if the two strings are anagrams of each other, otherwise return false.

 * An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.
 * 
 * Example 1:
 * 
 * Input: s = "racecar", t = "carrace"
 * 
 * Output: true
 *
 * Reference: Neetcode150
 */


/**
 *  @brief: isAnagram
 *  @param IN: string : s
 *  @param IN: string : t
 *  @return: bool
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        
        unordered_map<char, int> su;
        unordered_map<char, int> tu;
        for(int i = 0; i < s.length(); i++)
        {
            su[s[i]]++;
            tu[t[i]]++;
        }
        return (su == tu);
    }
};

