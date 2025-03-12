/*
 * @lc app=leetcode id=3011 lang=cpp
 *
 * [3011] Find if Array Can Be Sorted
 */

// @lc code=start

/*
    bubble sort concept
    Time compelxity: O(256+n²)=O(n²)
    Space complexity: O(257+n)=O(n)
*/
class Solution {
    public:
        bool canSortArray(vector<int>& nums){
            // Preprocess counting the set bits for each number
            // from 1 to 256
            std::vector<int> count_set_bits(257);
            for(int i=1;i<=256;i++) count_set_bits[i]=__builtin_popcount(i);

            // Use bubble sort to try sorting the array by swapping any two 
            // adjacent elements if they have the same number of set bits
            int n=nums.size();
            auto try_sorting=[&]()->bool{
                bool is_swapped=true;
                while(n>1 && is_swapped){
                    is_swapped=false;
                    for(int i=0;i<n-1;++i){
                        if(nums[i]>nums[i+1]){
                            if(count_set_bits[nums[i]]==count_set_bits[nums[i+1]]){
                                std::swap(nums[i],nums[i+1]);
                                is_swapped=true;
                            }
                            else return false; // No need to continue, it will never be sorted
                        } 
                    }
                    n--;
                }
                return true;
            };

            // Try to sort
            return try_sorting();
        }
};
// @lc code=end

