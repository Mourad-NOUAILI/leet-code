/*
 * @lc app=leetcode id=2379 lang=cpp
 *
 * [2379] Minimum Recolors to Get K Consecutive Black Blocks
 */

// @lc code=start
/*
    Static Sliding window
    Time complexity: O(k+n)=O(2n)=O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        int minimumRecolors(std::string blocks, int k) {
            int n=blocks.size();
            
            // Create a window of size k
            // This window will always contain the count of White blocks
            int win=0;
            for(int i=0;i<k;++i) win+=(blocks[i]=='W');

            int ans=INT_MAX;

            // Slide window to the left
            for(int i=0;i<=n-k;++i){
                // Minimize the answer
                ans=std::min(ans,win);

                // Update the White blocks count in the current window
                win-=(blocks[i]=='W');
                win+=(blocks[i+k]=='W');
            }

            return ans;
        }
};
// @lc code=end

