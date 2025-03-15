/*
 * @lc app=leetcode id=2529 lang=cpp
 *
 * [2529] Maximum Count of Positive Integer and Negative Integer
 */

// @lc code=start
/*
    Two passes Binary search
    Time complexity: O(2logn)
    Space complexity: O(1)
*/
class Solution {
    public:
        int maximumCount(vector<int>& nums){
            int n=nums.size();

            // pos_1st_0: will contains
            // - the postion of the 1st zero, if zero exists
            // - the postion of the 1st positive intger, if zero does not exist
            int pos_1st_0=std::lower_bound(nums.begin(),nums.end(),0)-nums.begin();

            // pos_1st_0==n, means zero does not exists or all integer are negative: max(n,n-n)=n
            // nums[pos_1st_0]!=0, means zero does not exist, but we have the postion of the first positive integer:
            // pos_1st_0: is the number of negative integers
            // n-pos_1st_0: is the number of positive integers.
            if(pos_1st_0 == n || nums[pos_1st_0]!=0) return std::max(pos_1st_0,n-pos_1st_0);

            // If the arrays contains at least a zero, in this case:
            // search the position of the last zero
            int pos_last_0=std::upper_bound(nums.begin(),nums.end(),0)-nums.begin();

            // pos_1st_0: is the number of negative integers
            // n-pos_last_0: is the number of positive integers.
            return  std::max(pos_1st_0,n-pos_last_0);
        }
};
// @lc code=end

