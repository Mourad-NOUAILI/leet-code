/*
 * @lc app=leetcode id=2560 lang=cpp
 *
 * [2560] House Robber IV
 */

// @lc code=start
/*
    Binary search one the answer
    Time complexity:O(n log hi)
    Space complexity: o(1)
*/
class Solution {
    public:
        int minCapability(std::vector<int>& nums, int k) {
            int n=nums.size();
            int hi=*std::max_element(nums.begin(),nums.end());

            auto is_possible=[&](int capability)->bool{
                int robbed_houses=0;
                int i=0;
                while(i<n){
                    // If we take the current house
                    if(nums[i]<=capability){
                        robbed_houses++; // Count it
                        i+=2; // Sskip adjacent house
                    }
                    // If we skip the current house, take the next one
                    else i++;

                    // At least we robbed k houses
                    if(robbed_houses>=k) return true;
                }
                
                return false;
            };

            int lo=1;
            while(lo<hi){
                int capability=(lo+hi)>>1;
                if(is_possible(capability)) hi=capability;
                else lo=capability+1;
            }
            return lo;    
        }
};
// @lc code=end

