/*
 * @lc app=leetcode id=3066 lang=cpp
 *
 * [3066] Minimum Operations to Exceed Threshold Value II
 */

// @lc code=start
/*
    Min heap
    Time complexity: O(nlogn)
    Space complexity: O(n)
*/
typedef std::vector<int> vi;
typedef  long long ll;
typedef std::vector<ll> vll;

class Solution {
    public:
        int minOperations(vi& nums, int k){
            if(nums.size()<2) return 0;

            std::priority_queue<ll,vll,std::greater<ll>> min_heap;
            for(auto& e: nums) min_heap.push(e);

            int ans=0;
            while(min_heap.size()>=2 && min_heap.top()<k){
                ll x=min_heap.top();
                min_heap.pop();
                ll y=min_heap.top();
                min_heap.pop();
                min_heap.push(2*std::min(x,y)*1ll+std::max(x,y)*1ll);
                ans++;
            }
            
            return ans;
        }
};
// @lc code=end

