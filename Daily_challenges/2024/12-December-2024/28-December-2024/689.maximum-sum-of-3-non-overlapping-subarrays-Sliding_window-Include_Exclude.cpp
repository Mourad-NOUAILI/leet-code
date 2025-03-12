/*
 * @lc app=leetcode id=689 lang=cpp
 *
 * [689] Maximum Sum of 3 Non-Overlapping Subarrays
 */

// @lc code=start
/*
    Brute force: Sliding window+Include/Exlude technique
    Problem is reduced to determine the first three best non-overlapping events with maximum sum.
    Time compelxity: O(4n+nlogn)
    Space compelxity: O(4n+logn)
*/

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

typedef std::pair<int,int> ii;
typedef std::vector<ii> vii;

typedef std::pair<int,vi> ivi;


class Solution {
    public:
        // Function to create list of subarrays with their sums.
        // Use the sliding window technique to dtermine all subarrays,
        // we store them in a hash map
        // Time compelxity: O(3n)
        // Space complexity: O(n)
        vvi create_events(vi& nums,int k){
            int n=nums.size();       

            // Sliding window to determine the sum of all subarrays of size k
            // Create window of size k
            int win=0;
            for(int i=0;i<k;++i) win+=nums[i];

            // Store all the events with their sums 
            std::unordered_map<int,vii> sum_events;
            sum_events[win].push_back({0,k-1});

            for(int i=0;i<n-k;++i) {
                win-=nums[i];
                win+=nums[i+k];
                sum_events[win].push_back({i+1,i+k});
            }
           
            // Create the events[i]=[starti,endi,valuei]
            // starti: starting index of the subarray
            // endi: ending index of the subarray
            // valuei: sum of all elements of the subarray[starti,endi]
            vvi events;
            for(auto& se: sum_events){
                for(auto& ev: se.second){
                    vi e;
                    e.push_back(ev.first);
                    e.push_back(ev.second);
                    e.push_back(se.first);
                    events.push_back(e);
                }
            }

            return events;
        }

        // Function that determine the first three best non-overlapping events with maximum sum
        // Time complexty: O(nlogn+n)
        // Space complexity: O(logn+n+m+n)=O(logn+n+n+n)=O(3n+logn)
        vi max_tree_events(vvi& events){
            int m=events.size();
            std::sort(events.begin(),events.end());

            std::vector<std::vector<ivi>> memo(m,std::vector<ivi>(3,{-1,{}}));
            
            auto solve=[&](int cur_index,int chosen,auto& self)->ivi{
                if(cur_index>=m || chosen==3) return {0,{}};

                if(memo[cur_index][chosen].first!=-1) return memo[cur_index][chosen];

                // Get the next index of the event which is not overlap with the current event
                int next_index=std::upper_bound(events.begin(), events.end(),events[cur_index][1],
                            [](int value, const std::vector<int>& event) {
                                return value < event[0];
                            })-events.begin();

                // Include the next non overlapping event and solve it
                auto include=self(next_index,chosen+1,self);
                include.first+=events[cur_index][2];
                include.second.push_back(events[cur_index][0]);

                // Exclude te next non ovalapping event, and solve the next event 
                auto exclude=self(cur_index+1,chosen,self);

                // Choose the better option
                // include.first>=exclude.first, because results are returned from bottom
                if (include.first>=exclude.first) memo[cur_index][chosen]=include;
                else memo[cur_index][chosen]=exclude;

                return memo[cur_index][chosen];
            };

            // Solve the problem and return the events
            auto res=solve(0, 0, solve);
            std::reverse(res.second.begin(),res.second.end()); // Reverse to maintain the correct order
            return res.second;
        }

        vi maxSumOfThreeSubarrays(vi& nums, int k){          
            vvi events=create_events(nums,k);
            vi ans=max_tree_events(events);
            return ans;
        }
};
// @lc code=end

