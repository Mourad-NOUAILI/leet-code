/*
 * @lc app=leetcode id=2270 lang=cpp
 *
 * [2270] Number of Ways to Split Array
 */

// @lc code=start
/*
    Prefix sum
    Time compelxity: O(n)
    Space complexity: O(1)
*/
class Solution {
public:
    int waysToSplitArray(std::vector<int>& nums){
        int n=nums.size();
        long long total=std::accumulate(nums.begin(),nums.end(),0*1ll);
        long long prefix_sum=0,right_sum;
        int ans=0;
        for(int i=0;i<n-1;++i){
            prefix_sum+=nums[i];
            right_sum=total-prefix_sum;
            if(prefix_sum>=right_sum) ans++;
        }
        return ans;
    }
};
// @lc code=end

