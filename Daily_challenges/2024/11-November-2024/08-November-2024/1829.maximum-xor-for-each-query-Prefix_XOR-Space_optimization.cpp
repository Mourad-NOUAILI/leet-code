/*
 * @lc app=leetcode id=1829 lang=cpp
 *
 * [1829] Maximum XOR for Each Query
 */

// @lc code=start
/*
    Prefix xor space optimiation+Math
    Time complexity: O(2n)=O(n)
    Space complexity: O(1)
*/
class Solution{
    public:
        std::vector<int> getMaximumXor(std::vector<int>& nums, int maximumBit){
            int n=nums.size();
            int xor_prefix=0;
            for(int i=0;i<n;++i) xor_prefix^=nums[i];
            std::vector<int> ans(n);
            int k=(1<<maximumBit)-1;
            for(int i=0;i<n;++i){
                ans[i]=xor_prefix^k;
                xor_prefix^=nums[n-1-i];
            }
            return ans;
        }
};
// @lc code=end

