/*
 * @lc app=leetcode id=565 lang=cpp
 *
 * [565] Array Nesting
 */

// @lc code=start
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        long n = nums.size();
        int max_len = 0;
        vector<bool> visited(n, false);
        for (long i = 0 ; i < n ; ++i){
            if (!visited[i]) {
                visited[i] = true;
                long k = i;
                int len = 0;
                do {
                    k = nums[k];
                    visited[k] = true;
                    len++;
                    max_len = max(max_len, len);
                }while(k != i);
            }
        }
    
        return max_len;
    }
};
// @lc code=end

