/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 */

// @lc code=start
/*
    Min heap
    Time complexity: O(nlog n)
    Space complexity: O(n)
*/
typedef std::pair<long long,int> ii;
typedef std::vector<ii> vii;

class Solution {
    public:
        int shortestSubarray(std::vector<int>& nums, int k) {
            int n=nums.size();

            std::priority_queue<ii,vii,std::greater<ii>> min_heap;

            int ans=INT_MAX;
            long long s=0;
            for (int i=0;i<n;++i){
              s+=nums[i];
              // If s>=k, minimize the actual length with previeus lengths
              if(s>=k) ans=std::min(ans,i+1);
              // Always take the minimum prefix sum before i, trying to hold ps[i]-ps[x]>=k
              while(!min_heap.empty() && s-min_heap.top().first>=k){
                ans=std::min(ans,i-min_heap.top().second);
                min_heap.pop(); // Not need to use this index for incoming indexes
              }
              
              min_heap.push({s,i});
            }
            return (ans != INT_MAX)?ans:-1;
        }
};
// @lc code=end

