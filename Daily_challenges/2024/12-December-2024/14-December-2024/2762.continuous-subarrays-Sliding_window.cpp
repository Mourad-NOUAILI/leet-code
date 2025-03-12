/*
 * @lc app=leetcode id=2762 lang=cpp
 *
 * [2762] Continuous Subarrays
 */

// @lc code=start


/*
    Sliding window
    Time complexity: O(n)
    Space complexity: O(1)
*/

class Solution {
    public:
        long long continuousSubarrays(vector<int>& nums){
            int n=nums.size();
    
            long long ans=0;
            int l=0;
            int mi=INT_MAX,mx=INT_MIN;
            int win_len=0;
            int r;
            for(r=0;r<n;++r){
                mi=std::min(mi,nums[r]);
                mx=std::max(mx,nums[r]);

                // While window violates mx-mi] ≤ 2 condition
                while(mx-mi>2){
                    // Get previous valid window's length
                    win_len=r-l;

                    // Compute number of valid subarrays in that previous valid window 
                    ans+=(win_len*1ll*(win_len+1)*1ll/2);

                    // Search next valid window
                    l=r;
                    mi=mx=nums[r];
                    while(l>0 &&abs(nums[r]-nums[l-1])<=2){
                        l--;
                        mi=std::min(mi,nums[l]);
                        mx=std::max(mx,nums[l]);
                    }
                    // If next valid window is found
                    if(l<r){
                        // Subtract repeated subarrays
                        win_len=r-l;
                        ans-=(win_len*1ll*(win_len+1)*1ll/2);
                    }
                }
            }
            // If the last valid window is non computed
            win_len=r-l; // r-l>0
            // Add it the number of subarrays the the answer
            ans+=(win_len*1ll*(win_len+1)*1ll/2);
            
            return ans;
        }
};

// @lc code=end

