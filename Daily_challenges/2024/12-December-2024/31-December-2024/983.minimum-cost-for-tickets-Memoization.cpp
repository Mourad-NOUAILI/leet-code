/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start

/*
    Memoization
    Time complexity: O(m*(max_day+nlogn))
    Space complexity: O(2max_day+m)

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

            vi memo(max_day+1,-1);
            
            auto solve=[&](int day,auto& self)->int{
                if(day>max_day) return 0;
                if(memo[day]!=-1) return memo[day];

                // If day is not scheduled pass to the next day in the array of days
                if(!std::binary_search(days.begin(),days.end(),day)){
                    int i=std::upper_bound(days.begin(),days.end(),day)-days.begin();
                    if(i>=n) return 0;
                    return self(days[i],self);
                };

                
                int ans=INT_MAX;
                // For each cost in costs
                for(int i=0;i<m;++i){
                    // Determine the day-pass(1-day pass or 7-day pass or 30 day pass) 
                    int day_pass;
                    if(i==0) day_pass=1;
                    else if(i==1) day_pass=7;
                    else day_pass=30;
                    
                    // Compute the cost of the day just after the last day in days pass list
                    int cost=costs[i]+self(day+day_pass,self);

                    // Minimize the cost
                    ans=std::min(ans,cost);
                }

                return memo[day]=ans;
            };

            return solve(min_day,solve);
        }
};
// @lc code=end

