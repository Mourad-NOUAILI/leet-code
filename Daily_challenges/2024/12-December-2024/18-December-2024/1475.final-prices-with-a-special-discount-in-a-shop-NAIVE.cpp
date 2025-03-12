/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
/*
    Brute force
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
class Solution {
    public:
        std::vector<int> finalPrices(std::vector<int>& prices) {
            int n=prices.size();
            std::vector<int> ans(n);
            // For each item prices[i]
            for(int i=0;i<n;++i){
                // Find the smallest prices[j], where j>i, and j is the smallest index
                int j;
                for(j=i+1;j<n && prices[j]>prices[i];++j);

                // If j is out of bound, means no discount found
                // Otherwise, we found a discoount, so compute the new prices[i]
                ans[i]=j<n?prices[i]-prices[j]:prices[i];
            }
            return ans;
        }
};
// @lc code=end

