/*
 * @lc app=leetcode id=3011 lang=cpp
 *
 * [3011] Find if Array Can Be Sorted
 */

// @lc code=start

/*
    divide the array into segments of consecutive 
    elements with the same number of set bits
    Time compelxity: O(257+n)=O(n)
    Space complexity: O(257)=O(1)
*/
class Solution {
    public:
        bool canSortArray(vector<int>& nums){
            // Preprocess counting the set bits for each number
            // from 1 to 256
            std::vector<int> count_set_bits(257);
            for(int i=1;i<=256;i++) count_set_bits[i]=__builtin_popcount(i);

            int cur_min=nums[0],cur_max=nums[0],prev_max=INT_MIN;
            for(auto& e: nums){
                // We are in same subarray
                if(count_set_bits[e]==count_set_bits[cur_min]){
                    // Update min and max
                    cur_min=std::min(cur_min,e);
                    cur_max=std::max(cur_max,e);
                }
                else{ // New subarray
                    if(cur_min<prev_max) return false; // No need to continue, it will never be sorted
                    // Save the max of the previous subarray
                    prev_max=cur_max;
                    // Start new subarray
                    cur_min=cur_max=e;
                }
            }
            // Check tha last subarary with the previous one
            return cur_min<prev_max?false:true;
        }
};
// @lc code=end

