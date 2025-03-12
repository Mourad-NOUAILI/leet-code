/*
 * @lc app=leetcode id=2461 lang=cpp
 *
 * [2461] Maximum Sum of Distinct Subarrays With Length K
 */

// @lc code=start
/*
    Sliding window (bad version)
    Time complexity:O(n.k)=O(n^2)
    Space complexity: O(1)
*/
class Solution {
public:
    // Function to check if the all the frequencies are equal to 1
    // means, check if all elements are distincts
    bool is_distinct(std::unordered_map<int,int>& freq){
        for(auto& [e,f]: freq){
            if(f>1) return false;
        }
        return true;
    }

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
        if(is_distinct(freq)) ans=win;

        // For each window
        for(int i=0;i<n-k;++i){
            // Slide the window to the right
            win-=nums[i];
            win+=nums[i+k];

            // Update frequencies
            freq[nums[i]]--;
            freq[nums[i+k]]++;

            // If all elemnts of the window are distincts, maximize the ans
            if(is_distinct(freq)) ans=std::max(ans,win);
        }
        return ans;
    }
};
// @lc code=end

