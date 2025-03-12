/*
 * @lc app=leetcode id=1593 lang=cpp
 *
 * [1593] Split a String Into the Max Number of Unique Substrings
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Backtracking
    Time complexity: O(n.2^n)
    Space complexity: O(n)
*/
class Solution {
public:
    int maxUniqueSplit(std::string s){
        int n=s.size();
        std::unordered_map<std::string,bool> list;

        auto solve=[&](int start,auto& self)->int{
            if(start==n) return 0;
            int ans=0;
            for(int end=start+1;end<=n;++end){
                std::string sub=s.substr(start,end-start);
                if(!list[sub]){
                    list[sub]=true;
                    ans=std::max(ans,1+self(end,self));
                    list[sub]=false;
                }
            }
            return ans;
        };

        return solve(0,solve);
    }
};
// @lc code=end

