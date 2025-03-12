/*
 * @lc app=leetcode id=2779 lang=cpp
 *
 * [2779] Maximum Beauty of an Array After Applying Operation
 */

// @lc code=start
/*
    Difference array + Prefix sum array
    Time complexity: O(m+n)
    Space complexity: O(m+k)
*/
class Solution {
    public:
        int maximumBeauty(std::vector<int>& nums, int k) {
            int n=nums.size();

            // Get the min element nums
            int mi=*std::min_element(nums.begin(),nums.end());

            // If min element-k is negative add |min| to all elemnts of nums
            // To enure that e-k>=0
            mi=mi-k;
            if(mi<0){
                mi=-mi;
                for(int i=0;i<n;++i) nums[i]+=mi;
            }

            // Get max element
            int mx=*std::max_element(nums.begin(),nums.end());

            // Size of the array
            int m=mx+k+2;

            // Prefix sum array to store the frequency of each element
            std::vector<int> prefix_sum(m,0);
            
            // Use Difference array techique to compute the frequency of each element in
            // ranges [e-k,e+k]
            for(auto& e: nums){
                prefix_sum[e-k]++;
                prefix_sum[e+k+1]--;
                
            }

            // Cumulate the frequencies using the previous computations
            // same time, update the ans.
            int ans=0;
            for(int i=1;i<m;++i){
                prefix_sum[i]+=prefix_sum[i-1];
                ans=std::max(ans,prefix_sum[i]);
            }

            return ans;
        }
};
// @lc code=end

