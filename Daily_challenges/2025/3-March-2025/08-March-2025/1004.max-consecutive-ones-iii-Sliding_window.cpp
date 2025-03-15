/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start

/*
    Dynamic sliding indow
    Time complexity: O(n) (AC)
    Space complexity: O(1)
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MIN;
        int cnt_zeros=0;

        // Expand the window to the right
        int l=0;
        for(int r=0;r<n;++r){
            cnt_zeros+=(nums[r]==0); // Add 1, if we encounter a 0

            // While number of zeros is greater than k
            while(cnt_zeros>k){
                cnt_zeros-=(nums[l]==0); // Subtract 1, if we encounter a 0, while ...
                l++; // ... shrinking the window from the left
            }

            ans=std::max(ans,r-l+1); // Maximize the answer
        }
        return ans;
    }
};
// @lc code=end

