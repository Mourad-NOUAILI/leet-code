/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start

/*
    DP with 1D array: Include/Exclude technique
    Time complexity: O(n.m)
    Space complexity: O(m) 
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int s=std::accumulate(nums.begin(),nums.end(),0);

        if(abs(target)>s) return 0;

        int m=2*s+1;
        std::vector<int> prev_row(m,0);

        prev_row[s+nums[0]]=1;
        prev_row[s-nums[0]]+=1;

        for(int i=1;i<n;++i){
            std::vector<int> cur_row(m,0);
            for(int cur_sum=-s;cur_sum<=s;++cur_sum){
                if(cur_sum-nums[i]<-s || cur_sum+nums[i]>s) continue;
                cur_row[cur_sum+nums[i]+s]+=prev_row[cur_sum+s];
                cur_row[cur_sum-nums[i]+s]+=prev_row[cur_sum+s];
            }
            prev_row=cur_row;
        }

        return prev_row[target+s];
    }
};
// @lc code=end

