/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start

/*
    Compare with sorted array
    Time complexity: O(nlogn+n^2)
    Space complexity: O(n+logn)
*/
class Solution {
    public:
        bool check(std::vector<int>& nums) {
            int n=nums.size();
            std::vector<int> sorted=nums;
            std::sort(sorted.begin(),sorted.end());
            for(int rot_index=0;rot_index<n;++rot_index){
                int i=0;
                while(i<n && nums[(rot_index+i)%n]==sorted[i]) i++;
                if(i==n) return true;
            }
            return false;
        }
};
// @lc code=end

