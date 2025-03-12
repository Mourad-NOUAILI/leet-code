/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
/*
    Monotonic decreasing stack
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution {s
    public:
        std::vector<int> finalPrices(std::vector<int>& prices) {
            int n=prices.size();
            std::vector<int> ans=prices;
            std::stack<int> st;
            // For each prices[j]
            for(int j=0;j<n;++j){
                // check if it could be is a special discount of any previous element                     
                while(!st.empty() && prices[j]<=prices[st.top()]){
                    // Apply discount
                    ans[st.top()]-=prices[j];
                    st.pop(); // Pop the current prices[i], to be able to check for all previous encountered prices[i]
                }
                // In no, means prices[j]>prices[i], so push prices[j] 
                // because it could be a discount for any prices[i] in the future
                st.push(j);
            }
            return ans;
        }
};
// @lc code=end

