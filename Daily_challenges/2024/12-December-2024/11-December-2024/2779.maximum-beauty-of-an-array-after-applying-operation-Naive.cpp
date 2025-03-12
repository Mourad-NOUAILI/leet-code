/*
 * @lc app=leetcode id=2779 lang=cpp
 *
 * [2779] Maximum Beauty of an Array After Applying Operation
 */

// @lc code=start
/*
    Naive
    Time complexity: O(n+n.m)=O(n.m)
    Space complexity: O(m)
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
            int m=mx+k+1;

            // Array to store the frequency of each element
            std::vector<int> count(m,0);
            int ans=0;
            for(auto& num: nums){
                for(int e=num-k;e<=num+k;++e){
                    count[e]++;
                    ans=std::max(ans,count[e]);
                }
            }
            return ans;
        }
};
// @lc code=end

