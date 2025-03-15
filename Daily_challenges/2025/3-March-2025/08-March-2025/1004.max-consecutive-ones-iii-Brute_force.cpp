/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start

/*
    Brute Force: try all possibilities
    Time complexity: O(n^2) (TLE)
    Space complexity: O(1)
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();

        int ans=INT_MIN;

        // For each window
        for(int i=0;i<n;++i){
            int j=i; // starting from i
            
            // Expand it to the right, while counting the numbers of zeros 

            int cnt_zero=0; // Initialize the number of zeros to 0
            // While the end of the array is not reached and the number of zeros is
            // not out of the limit k
            // Otherwise, the actual window can not be expanded any more
            while(j<n && cnt_zero<=k){
                cnt_zero+=(nums[j]==0); // Update the number of zeros
                j++; // Expand it to the right
            }
            
            // If number of zeros is greater than k, means
            // we have an extra 0 in the length of the sequence
            // If number of zeros is less or equal to k, means
            // no xtra 0 in the length of the sequence is len=j-i
            int len=cnt_zero>k?j-i-1:j-i;

            
            ans=std::max(ans,len); // Maximize the answer
        }
        
        return ans;
    }
};
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

