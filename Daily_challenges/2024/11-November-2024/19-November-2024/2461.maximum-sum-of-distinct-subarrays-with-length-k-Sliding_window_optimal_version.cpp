/*
 * @lc app=leetcode id=2461 lang=cpp
 *
 * [2461] Maximum Sum of Distinct Subarrays With Length K
 */

// @lc code=start
/*
    Sliding window (optimal version)
    Time complexity:O(k+n)=O(n)
    Space complexity: O(n)
*/
class Solution {
    public:
        long long maximumSubarraySum(std::vector<int>& nums, int k) {
            int n=nums.size();
            long long ans=0;
            std::unordered_map<int,int> freq;

            // Create the window of size k
            long long win=0;
            for(int i=0;i<k;++i){
                win+=nums[i];
                freq[nums[i]]++;
            }

            // If all elemnts of the window are distincts, ans= sum of all elements of the window
            if(freq.size()==k) ans=win;

            // For each window
            for(int i=0;i<n-k;++i){
                // Slide the window to the right
                win-=nums[i]; 
                win+=nums[i+k];
                
                // Update frequencies
                freq[nums[i]]--;
                freq[nums[i+k]]++;

                // if the frequency of the kicked element become 0
                // means it does not exist in the actual window
                // so remove it
                if(freq[nums[i]]==0) freq.erase(nums[i]);

                // If all elemnts of the window are distincts, maximize the ans
                if(freq.size()==k) ans=std::max(ans,win);
            }
            return ans;
        }
};
// @lc code=end

