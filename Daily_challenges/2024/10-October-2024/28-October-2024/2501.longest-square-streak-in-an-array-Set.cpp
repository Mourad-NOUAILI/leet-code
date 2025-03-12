/*
 * @lc app=leetcode id=2501 lang=cpp
 *
 * [2501] Longest Square Streak in an Array
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Unordered Set
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
public:
    int longestSquareStreak(std::vector<int>& nums) {
        int n=nums.size();
        int mx=*std::max_element(nums.begin(),nums.end());
        std::unordered_set<int> numbers(nums.begin(),nums.end());
        int ans=0;
        for(auto& e: numbers){
            int cnt=0;
            long long x=e;
            while(x<=mx && numbers.find(x)!=numbers.end()){
                x*=x;
                cnt++;
            }
            ans=std::max(ans,cnt);
        }
        return ans>1?ans:-1;
    }
};
// @lc code=end

