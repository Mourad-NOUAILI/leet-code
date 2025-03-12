/*
 * @lc app=leetcode id=2054 lang=cpp
 *
 * [2054] Two Best Non-Overlapping Events
 */

// @lc code=start

/*
    Line sweep technique
    Time complexity: O(nlogn+n)=O(nlogn)
    Space complexity: O(logn+3n)
*/
class Solution {
    public:
        int maxTwoEvents(std::vector<std::vector<int>>& events){
            int n=events.size();

            std::vector<std::vector<int>> line_sweep;

            for(auto& event: events){
                line_sweep.push_back({event[0],1,event[2]});
                line_sweep.push_back({event[1]+1,-1,event[2]});
            }

            std::sort(line_sweep.begin(),line_sweep.end());

            int max_seen_val=0,ans=0;
            for(auto& point: line_sweep){
                int type=point[1];
                int val=point[2];

                // When we are at a start point
                // Passengers get on the bus, update the answer
                if(type==1) ans=std::max(ans,max_seen_val+val);

                // When we are at end point
                // Update the maximum seen value of all events
                else max_seen_val=std::max(max_seen_val,val);
            }
            
            return ans;
        }
};
// @lc code=end

