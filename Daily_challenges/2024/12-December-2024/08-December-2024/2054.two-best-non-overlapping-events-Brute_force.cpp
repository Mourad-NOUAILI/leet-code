/*
 * @lc app=leetcode id=2054 lang=cpp
 *
 * [2054] Two Best Non-Overlapping Events
 */

// @lc code=start
/*
    Brute Force
    Time complexity: O(n^2)
    Space compelxity: O(1)
*/
class Solution {
    public:
        int maxTwoEvents(std::vector<std::vector<int>>& events){
            int n=events.size();

            int ans=INT_MIN;
            for(int cur_index=0;cur_index<n;++cur_index){
                int val=events[cur_index][2];
                ans=std::max(ans,val);
                for(int next_index=0;next_index<n;++next_index){
                    // If next event overlaps with the current event, then skip it
                    if(cur_index==next_index || events[cur_index][1]>=events[next_index][0]) continue;

                    // Otherwise, take it
                    ans=std::max(ans,val+events[next_index][2]);
                }
            }
            return ans;
        }
};
// @lc code=end

