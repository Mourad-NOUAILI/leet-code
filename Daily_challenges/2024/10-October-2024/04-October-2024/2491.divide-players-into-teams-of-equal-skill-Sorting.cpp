/*
 * @lc app=leetcode id=2491 lang=cpp
 *
 * [2491] Divide Players Into Teams of Equal Skill
 */

// @lc code=start

#include<bits/stdc++.h>
/*
    Sorting
    Time complexity: O(nlogn)
    Space complexity: O(sorting method)
*/

class Solution {
    public:
        long long dividePlayers(std::vector<int>& skill) {
            std::sort(skill.begin(),skill.end());
            int i=0,j=skill.size()-1,total=skill[0]+skill.back();
            long long ans=0;
            while(i<j){
                if(skill[i]+skill[j]!=total) return -1;
                ans+=(skill[i]*skill[j]);
                i++;
                j--;
            }
            return ans;
        }
};
// @lc code=end

