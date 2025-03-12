/*
 * @lc app=leetcode id=2054 lang=cpp
 *
 * [2054] Two Best Non-Overlapping Events
 */

// @lc code=start
/*
    Recusrion: include/exclude technique+Memoization
    Time complexity: O(nlogn)
    Space complexity: O(logn+n+n^2)
*/
class Solution {
    public:
        int maxTwoEvents(std::vector<std::vector<int>>& events){
            int n=events.size();

            std::sort(events.begin(),events.end());

            std::vector<std::vector<int>> memo(n,std::vector<int>(2,-1));

            auto solve=[&](int cur_index,int chosen,auto& self)->int{
                if(cur_index>=n || chosen==2) return 0;

                if(memo[cur_index][chosen]!=-1) return memo[cur_index][chosen];

                // Get the next index of the event which is not overlap with the current event
                int next_index=std::upper_bound(events.begin(), events.end(),events[cur_index][1],
                            [](int value, const std::vector<int>& event) {
                                return value < event[0];
                            })-events.begin();

                // Include the next non overlapping event and solve it
                int include=events[cur_index][2]+self(next_index,chosen+1,self);

                // Exclude te next non ovalapping event, and solve the next event 
                int exclude=self(cur_index+1,chosen,self);

                return memo[cur_index][chosen]=std::max(include,exclude);
            };

            return solve(0,0,solve);
        }
};
// @lc code=end

