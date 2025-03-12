/*
 * @lc app=leetcode id=2491 lang=cpp
 *
 * [2491] Divide Players Into Teams of Equal Skill
 */

// @lc code=start

#include<bits/stdc++.h>
/*
    Brute force
    Time complexity: O(n^2),assume serach in unordered set is O(1) 
    Space complexity: O(n)
*/

class Solution {
    public:
        long long dividePlayers(std::vector<int>& skill) {
            int n=skill.size();
            int s=0;
            for(auto& e: skill) s+=e;

            if(2*s%n!=0) return -1;
            
            std::unordered_set<int> taken;
            int target=2*s/n;
            long long ans=0;
            int cnt=0;
            for(int i=0;i<n-1;++i){
                for(int j=i+1;j<n;++j){
                    if(taken.find(i)==taken.end() && taken.find(j)==taken.end() && skill[i]+skill[j]==target){
                        ans+=(skill[i]*skill[j]);
                        taken.insert(i);
                        taken.insert(j);
                        cnt++;
                    }
                }
            }
            return cnt<n/2||ans==0?-1:ans;
        }
};
// @lc code=end

