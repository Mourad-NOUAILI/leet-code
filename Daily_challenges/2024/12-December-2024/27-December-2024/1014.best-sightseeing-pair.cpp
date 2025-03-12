/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
/*
    Prefix Max
    Time compelxity: O(n)
    Space compelxity: O(1)
*/
class Solution {
    public:
        int maxScoreSightseeingPair(std::vector<int>& values) {
            int n=values.size();

            int ans=INT_MIN;
            int prefix_max=values[0];
            for(int i=1;i<n;++i){
                ans=std::max(ans,prefix_max+values[i]-i);
                prefix_max=std::max(prefix_max,values[i]+i);
            }

            return ans;
        }
};
// @lc code=end

