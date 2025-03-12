/*
 * @lc app=leetcode id=1593 lang=cpp
 *
 * [1593] Split a String Into the Max Number of Unique Substrings
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Backtracking+pruning
    Time complexity: O(n.2^n)
    Space complexity: O(n)
*/
class Solution {
    public:
        int maxUniqueSplit(std::string s){
            int n=s.size();
            std::unordered_map<std::string,bool> list;
            int ans=0;

            auto solve=[&](int start,int count,auto& self)->void{
                // Prune: If the current count plus remaining characters can't exceed
                // No need to go further
                if(count+(n-start)<=ans) return;

                if(start==n) ans=std::max(ans,count);

                for(int end=start+1;end<=n;++end){
                    std::string sub=s.substr(start,end-start);
                    if(!list[sub]){
                        list[sub]=true;
                        self(end,count+1,self);
                        list[sub]=false;
                    }
                }
            };

            solve(0,0,solve);
            return ans;
        }
};
// @lc code=end

