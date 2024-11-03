/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(*2^target)
    Space complexity: O(target+n)
*/

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
public:
    vvi combinationSum(vi& candidates, int target){
        int n=candidates.size();
        vvi ans;

        auto solve=[&](int i,vi& tmp, int sum,auto& self)->void{
            if(sum==0) {
                ans.push_back(tmp);
                return;
            }

            if(i>=n || sum<0) return;

            // Include candidates[i]
            tmp.push_back(candidates[i]);
            
            // Explore
            self(i,tmp,sum-candidates[i],self);

            // Exclude candidates[i]
            tmp.pop_back();
            self(i+1,tmp,sum,self);
        };

        vi tmp;

        solve(0,tmp,target,solve);
        
        return ans;
    }
};
// @lc code=end

