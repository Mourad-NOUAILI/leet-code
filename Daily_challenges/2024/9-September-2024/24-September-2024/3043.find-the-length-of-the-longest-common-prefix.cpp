/*
 * @lc app=leetcode id=3043 lang=cpp
 *
 * [3043] Find the Length of the Longest Common Prefix
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Hash set
    Time complexity: O(nlogx+mlogy)
    Space complexity: 
    n: size of arr1
    m: size of arr2
    x: elements of arr1
    y: elements of arr2
*/
class Solution {
    public:
        std::unordered_set<int> get_prefixes(std::vector<int>& arr1){
            std::unordered_set<int> prefixes;
            for(auto& x: arr1){
                while(x!=0){
                    prefixes.insert(x);
                    x/=10;
                }         
            }
            return prefixes;
        }

        int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
            std::unordered_set<int> prefixes=get_prefixes(arr1);
            int ans=0;
            for(auto& y: arr2){
              while(y!=0 && prefixes.find(y)==prefixes.end()) y/=10;
              if(prefixes.find(y)!=prefixes.end()) ans=std::max(ans,(int)floor(log10(y)+1));
            }
            return ans;
        }
};

// @lc code=end

