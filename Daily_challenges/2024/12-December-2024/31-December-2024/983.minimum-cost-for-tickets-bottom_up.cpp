/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start

/*
    Bottom up
    Time complexity: O(2max_day)
    Space complexity: O(max_day)

    Since n=365,m=365,max_day=365, we can say:
    Time complexity: O(1)
    Space complexity: O(1)

*/
typedef std::vector<int> vi;
class Solution {
    public:
        int mincostTickets(vi& days, vi& costs){
            int n=days.size();
            int m=costs.size();
            
            int min_day=days[0];
            int max_day=days[n-1];

            vi dp(max_day+1,0);
            
            int i=0;
            for(int day=1;day<=max_day;++day){
                if(day!=days[i]) dp[day]=dp[day-1];
                else{
                    i++;
                    dp[day]=std::min(   {costs[0]+dp[day-1],
                                        costs[1]+dp[std::max(0,day-7)],
                                        costs[2]+dp[std::max(0,day-30)]}
                                    );
                }
            }
            
            return dp[max_day];
        }
};
// @lc code=end

