/*
 * @lc app=leetcode id=2017 lang=cpp
 *
 * [2017] Grid Game
 */

// @lc code=start
/*
    Prefix sum+suffix sum+sliding path
    Time complexity: O(2n)
    Space compelxity: O(1)
*/

typedef long long ll;
class Solution{
    public:
        ll gridGame(std::vector<std::vector<int>>& grid) {
            int m=grid.size(); // m=2
            int n=grid[0].size();

            // Suffix sum for upper row
            ll upper_portion_sum=std::accumulate(grid[0].begin(),grid[0].end(),0LL);

            // Prefix sum for lower row
            ll lower_portion_sum=0;

            // Slide the path
            ll ans=LONG_LONG_MAX;
            for(int i=0;i<n;++i){
                // Substract the current value in the 1st row from the upper row's suffix sum
                upper_portion_sum-=grid[0][i];

                // Update the answer by minmizing the maximum of boths sums
                ans=std::min(ans,std::max(upper_portion_sum,lower_portion_sum));

                // Add the current value in the 2nd row to the lower row's prefix sum
                lower_portion_sum+=grid[1][i]; 
            }
            return ans;
        }
};
// @lc code=end

