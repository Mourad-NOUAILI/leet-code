/*
 * @lc app=leetcode id=2161 lang=cpp
 *
 * [2161] Partition Array According to Given Pivot
 */

// @lc code=start
/*
    One passe: two pointers
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
            int n=nums.size();

            // Create answer array initialized with pivot, in order to
            // focus on elements lesser and greater that pivot
            std::vector<int> ans(n,pivot);

            // Pointer wl to track the next smaller element's position
            // Pointer wg to track the next greater element's position
            int wl=0,wg=n-1;

            // Iterate over all elements from left to right
            for(int cur_index=0;cur_index<n;++cur_index){
                // If the leftmost current element at the current index is lesser than pivot:
                // place at its correct position in answer array, pointed by wl
                // and prepare the position for the next smaller in answer array
                if(nums[cur_index]<pivot) ans[wl]=nums[cur_index],wl++;

                // If the rightmost current element at the current index is greater than pivot:
                // place at its correct position in answer array, pointed by wg
                // and prepare the position for the next greater in answer array
                if(nums[n-1-cur_index]>pivot) ans[wg]=nums[n-1-cur_index],wg--;
            }

            return ans;
        }
};
// @lc code=end

