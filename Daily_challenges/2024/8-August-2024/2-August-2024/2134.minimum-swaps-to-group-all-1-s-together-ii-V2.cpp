/*
 * @lc app=leetcode id=2134 lang=cpp
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Sliding window
    Time complexity: O(4n)=O(n)
    Space complexity: O(n)
*/
typedef std::vector<int> vi;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // Count total number of ones
        int nb_ones=0;
        for(auto& e: nums) if(e==1) nb_ones++;

        // Extend the array for circularity
        int n=nums.size();
        for(int i=0;i<n;++i) nums.push_back(nums[i]);

        n=2*n;

        //Create a window of size nb_ones
        int cnt_ones_in_win=0;
        for(int i=0;i<nb_ones;++i){
            if (nums[i]==1) cnt_ones_in_win++;
        }
        
        // Slide the window
        int i=0,max_ones_in_win=INT_MIN;
        for(int i=0;i<n-nb_ones;++i){
            max_ones_in_win=std::max(max_ones_in_win,cnt_ones_in_win);
            cnt_ones_in_win-=nums[i];
            cnt_ones_in_win+=nums[i+nb_ones];
        }
        
        return nb_ones-max_ones_in_win;
    }
};
// @lc code=end

