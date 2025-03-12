/*
 * @lc app=leetcode id=1829 lang=cpp
 *
 * [1829] Maximum XOR for Each Query
 */

// @lc code=start
/*
    Prefix xor+Math
    Time complexity: O(2n)=O(n)
    Space complexity: O(n)
*/
class Solution {
    public:
        std::vector<int> getMaximumXor(std::vector<int>& nums, int maximumBit){
            int n=nums.size();
            std::vector<int> prefix_xor(n);
            prefix_xor[0]=nums[0];
            for(int i=1;i<n;++i) prefix_xor[i]=prefix_xor[i-1]^nums[i];
            std::vector<int> ans;
            int k=(1<<maximumBit)-1;
            for(int i=n-1;i>=0;--i) ans.push_back(prefix_xor[i]^k);
            return ans;
        }
};
// @lc code=end

