/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Stack
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution {
    public:
        int maxWidthRamp(std::vector<int>& nums) {
            int n=nums.size();
            std::stack<int> st;

            for (int i=0;i<n;++i) {
                if (st.empty() || nums[st.top()]>nums[i]) st.push(i);
            }

            int ans=0;
            for (int i=n-1;!st.empty()&&i>=0;--i){
                while (!st.empty() && nums[st.top()]<=nums[i]){
                    ans = std::max(ans,i-st.top());
                    st.pop();
                }
            }

            return ans;
    }
};
// @lc code=end

