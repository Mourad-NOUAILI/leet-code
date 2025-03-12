/*
 * @lc app=leetcode id=2762 lang=cpp
 *
 * [2762] Continuous Subarrays
 */

// @lc code=start
/*
    Sliding window + monotonic deque
    Time complexity: O(n)
    Space complexity: O(n)
*/
typedef std::pair<int,int> ii;

class Solution {
    public:
        long long continuousSubarrays(vector<int>& nums){
            int n=nums.size();
            
            std::deque<ii> min_deq; // Monotonically increasing (from front to back)
            std::deque<ii> max_deq; // Monotonically decreasing (from front to back)
            
            long long ans=0;
            int l=0;
            for(int r=0;r<n;++r){
                // Maintain the monotonicity of both deques
                while(!min_deq.empty() && min_deq.back().first>=nums[r]) min_deq.pop_back();
                while(!max_deq.empty() && max_deq.back().first<=nums[r]) max_deq.pop_back();

                // Expand the window
                min_deq.push_back({nums[r],r});
                max_deq.push_back({nums[r],r});

                // While window violates mx-mi] ≤ 2 condition
                while(!max_deq.empty() && !min_deq.empty() && max_deq.front().first-min_deq.front().first>2){
                    // Shrink the window and
                    // Move left pointer past the element that breaks the condition
                    if(max_deq.front().second<min_deq.front().second){
                        l=max_deq.front().second+1;
                        max_deq.pop_front();
                    }
                    else{
                        l=min_deq.front().second+1;
                        min_deq.pop_front();
                    }
                }
                
                ans+=r-l+1;
            }
            return ans;
        }
};

// @lc code=end

