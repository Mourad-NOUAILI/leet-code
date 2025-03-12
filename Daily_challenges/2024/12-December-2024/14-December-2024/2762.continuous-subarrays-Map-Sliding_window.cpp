/*
 * @lc app=leetcode id=2762 lang=cpp
 *
 * [2762] Continuous Subarrays
 */

// @lc code=start
/*
    Sliding window + map
    Time complexity: O(nlog3)=O(n)
    Space complexity: O(3)=O(1)
*/

class Solution {
    public:
        long long continuousSubarrays(vector<int>& nums){
            int n=nums.size();
            std::map<int,int> freq;
            long long ans=0;
            int l=0;
            for(int r=0;r<n;++r){
                freq[nums[r]]++; // Expand the window

                // While window violates mx-mi] ≤ 2 condition
                while(freq.rbegin()->first - freq.begin()->first > 2){
                    // Shrink the window
                    freq[nums[l]]--; // reduce the count of the element at left pointer 
                    
                    // the count of the element at left pointer become 0
                    // remove it from the window
                    if(freq[nums[l]]==0) freq.erase(nums[l]);

                    l++; 
                }
                
                ans+=r-l+1;
            }
            return ans;
        }
};

// @lc code=end

