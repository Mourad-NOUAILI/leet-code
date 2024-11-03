/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(2^target)
    Space complexity: O(target+n)
*/

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            int n=candidates.size();
            vvi ans;

            auto solve=[&](int i,vi& tmp, int sum,auto& self)->void{
                if(sum==0) {
                    ans.push_back(tmp);
                    return;
                }

                if(sum<0) return;

                for(int j=i;j<n;++j){
                    if(candidates[j]>target) continue;
                    
                    // Include candidates[j]
                    tmp.push_back(candidates[j]);

                    // Explore
                    self(j,tmp,sum-candidates[j],self);

                    // Exclude candidates[j]
                    tmp.pop_back();
                }
            };

            vi tmp;

            solve(0,tmp,target,solve);
            
            return ans;
        }
};
// @lc code=end

