/*
 * @lc app=leetcode id=2379 lang=cpp
 *
 * [2379] Minimum Recolors to Get K Consecutive Black Blocks
 */

// @lc code=start
/*
    Naive approach: try all windows
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n=blocks.size();
            int ans=INT_MAX;
            // For each window starting from i
            for(int i=0;i<=n-k;++i){
                int cnt_white = 0; // Initilize the number of White blocks
                // Take a window of size k ( (k+i-1)-i+1 )
                for(int j=i;j<k+i;++j){
                    cnt_white+=(blocks[j]=='W'); // Update the number of White blocks
                }

                // Minimize the answer 
                ans=std::min(ans,cnt_white);
            }

            return ans;
        }
};
// @lc code=end

