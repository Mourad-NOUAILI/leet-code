/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(nlogn)
    Space complexity: O(1)
*/
class Solution {
public:
    std::string largestNumber(std::vector<int>& nums){
        int n=nums.size();
        std::sort(nums.begin(),nums.end(),[](int a,int b){
            std::string sa=std::to_string(a);
            std::string sb=std::to_string(b);
            return (sa+sb>sb+sa)?true:false;           
           
        });

        if(nums[0]==0) return "0";

        std::string ans="";
        for(auto& e: nums){
            ans+=std::to_string(e);
        }
      
        return ans;
    }
};
// @lc code=end

