/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time compelxity: (n*2^target)
    Space complexity: O(target+n)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();

        std::sort(candidates.begin(),candidates.end());

        vvi ans;

        auto solve=[&](int i,vi& tmp, int sum,auto& self)->void{
            if(sum==0) {
                ans.push_back(tmp);
                return;
            }
            if(sum<0) return;

            for(int j=i;j<n;++j){
                if(j>i&&candidates[j]==candidates[j-1]) continue;

                // Include candidates[i]
                tmp.push_back(candidates[j]);

                // Explore
                self(j+1,tmp,sum-candidates[j],self);

                // Exclude candidates[i]
                tmp.pop_back();
            }

            

        };

        vi tmp;
        solve(0,tmp,target,solve);

        return ans;
    }
};
// @lc code=end

