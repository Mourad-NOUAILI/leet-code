/*
 * @lc app=leetcode id=2053 lang=cpp
 *
 * [2053] Kth Distinct String in an Array
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Countig+Map
    Time complexity: O(nlogn)
    Space complexity: O(n)
*/
class Solution {
public:
    std::string kthDistinct(std::vector<std::string>& arr, int k) {
        std::map<std::string,int> freq;
        for(auto& s: arr) freq[s]++;
        for(auto& s: arr){
            if(freq[s]==1) k--;
            if(k==0) return s;
        }
        return "";
    }
};
// @lc code=end

