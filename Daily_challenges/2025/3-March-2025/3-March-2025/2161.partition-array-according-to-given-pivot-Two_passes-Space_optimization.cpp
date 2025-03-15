/*
 * @lc app=leetcode id=2161 lang=cpp
 *
 * [2161] Partition Array According to Given Pivot
 */

// @lc code=start
/*
    Two passes: left to rigth+right to left
    Time complexity: O(2n)
    Space complexity: O(1)
*/
class Solution {
    public:
        std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
            int n=nums.size();

            // Create answer array initialized with pivot, in order to
            // focus on elements lesser and greater that pivot
            std::vector<int> ans(n,pivot);
            
            // Pass#1: Left to right

            int wl=0; // Pointer to track the next smaller element's position
            // Iterate on elements from left to right, to maintain the relative order of all lesser elements
            for(int cur_index=0;cur_index<n;++cur_index){
                // If the current element at the current index is lesser than pivot:
                if(nums[cur_index]<pivot){
                    ans[wl]=nums[cur_index]; // place at its correct position in answer array, pointed by wl
                    wl++; // Prepare the position for the next smaller in answer array
                }
            }

            // Pass#1: Left to right

            int wg=n-1; // Pointer to track the next greater element's position
            // Iterate on elements from right to left, to maintain the relative order of all greater elements
            for(int cur_index=n-1;cur_index>=0;--cur_index){
                // If the current element at the current index is greater than pivot:
                if(nums[cur_index]>pivot){
                    ans[wg]=nums[cur_index]; // place at its correct position in answer array, pointed by wg
                    wg--; // Prepare the position for the next greater in answer array
                }
            }
            return ans;
        }
};
// @lc code=end

