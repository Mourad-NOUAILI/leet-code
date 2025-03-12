/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 */

// @lc code=start
/*
    Monotonic deque
    Time complexity: O(n)
    Space complexity: O(n)
*/
typedef std::pair<long long,int> ii;
typedef std::vector<ii> vii;

class Solution {
    public:
        int shortestSubarray(std::vector<int>& nums, int k) {
            int n=nums.size();

            // Create a deque
            std::deque<ii> q;

            int ans=INT_MAX;
            long long s=0;
            for (int i=0;i<n;++i){
              s+=nums[i];
              // If s>=k, minimize the actual length with previous lengths
              if(s>=k) ans=std::min(ans,i+1);

              // Always take the minimum prefix sum before i, trying to hold ps[i]-ps[x]>=k
              while(!q.empty() && s-q.front().first>=k){
                ans=std::min(ans,i-q.front().second);
                q.pop_front();
              }
              
              // Remove any prefix sum > s, to ensure that the deque stay
              // monotonically increasing
              while(!q.empty() && q.back().first>=s) q.pop_back();
              
              // Here, we are sure that s is the greatest value
              q.push_back({s,i});
            }
            
            return (ans != INT_MAX)?ans:-1;
        }
};
// @lc code=end

