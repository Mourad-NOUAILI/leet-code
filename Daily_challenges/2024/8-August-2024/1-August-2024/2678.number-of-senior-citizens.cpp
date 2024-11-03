/*
 * @lc app=leetcode id=2678 lang=cpp
 *
 * [2678] Number of Senior Citizens
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Time complexity: O(n)
    Extra space complexity: O(1)
*/
class Solution {
public:
    int countSeniors_v1(vector<string>& details) {
        int ans=0;
        for(auto& d: details){
            int tens=d[11]-'0';
            int units=d[12]-'0';
            if(units+tens*10>60) ans++;
       }
       return ans; 
    }

    int countSeniors_v2(std::vector<std::string>& details) {
        int ans=0;
        for(auto& d: details){
            char tens=d[11];
            char units=d[12];
            if(tens>'6' || tens=='6' && units>'0') ans++;
       }
       return ans; 
    }
};
// @lc code=end

