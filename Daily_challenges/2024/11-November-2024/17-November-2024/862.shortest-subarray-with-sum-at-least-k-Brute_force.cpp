/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 */

// @lc code=start
/*
    Brute force
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
class Solution {
    public:
        int shortestSubarray(std::vector<int>& nums, int k) {
            int n=nums.size();
            int INF=numeric_limits<int>::max();
            int ans=INF;
            
            for (int i=0;i<n;++i){
                long long s=0;
                int j=i;
                while(j<n && s<k){
                    s+=nums[j];
                    j++;
                }
                if(s>=k) ans=std::min(ans,j-i);
            }
            return (ans != INF)?ans:-1;
        }
};
// @lc code=end

