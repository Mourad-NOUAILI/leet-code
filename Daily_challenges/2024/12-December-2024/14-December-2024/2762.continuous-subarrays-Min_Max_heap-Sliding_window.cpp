/*
 * @lc app=leetcode id=2762 lang=cpp
 *
 * [2762] Continuous Subarrays
 */

// @lc code=start
typedef std::pair<int,int> ii;
typedef std::vector<ii> vii;
/*
    Min heap, max heap + sliding window
    Time complexity: O(nlogn)
    Space complexity: O(2n)
*/

class Solution {
    public:
        long long continuousSubarrays(std::vector<int>& nums){
            int n=nums.size();

            std::priority_queue<ii,vii> max_heap;
            std::priority_queue<ii,vii,std::greater<ii>> min_heap;

            int l=0;
            long long ans=0;
            for(int r=0;r<n;++r){
                min_heap.push({nums[r],r});
                max_heap.push({nums[r],r});
                // While window violates mx-mi ≤ 2 condition
                while(l<r && nums[max_heap.top().second]-nums[min_heap.top().second]>2){
                    l++; // Skrink the window

                    // Remove indices that are now outside window
                    while(!max_heap.empty() && max_heap.top().second<l) max_heap.pop();
                    while(!min_heap.empty() && min_heap.top().second<l) min_heap.pop();
                }

                // number of valid subarrays ending at the current r
                ans+=r-l+1;
            }
            return ans;
        }
};

// @lc code=end

