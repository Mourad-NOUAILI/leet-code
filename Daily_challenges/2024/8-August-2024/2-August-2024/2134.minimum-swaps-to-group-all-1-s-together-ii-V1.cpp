/*
 * @lc app=leetcode id=2134 lang=cpp
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Prercessing+Sliding window
    Time complexity: O(5n)=O(n)
    Space complexity: O(2n)=O(n)
*/
typedef std::vector<int> vi;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int nb_ones=0;
        for(auto& e: nums) if(e==1) nb_ones++;

        int n=nums.size();
        for(int i=0;i<n;++i) nums.push_back(nums[i]);

        n=2*n;

        vi pre_ones(n+1,0),pre_zeros(n+1,0);
        
        for(int i=0;i<n;++i){
            pre_ones[i+1]=nums[i]==1?pre_ones[i]+1:pre_ones[i];
        }
        
        int i=0,j=nb_ones-1,max_ones_in_win=INT_MIN;
        while(j<n){
            int cnt_ones_in_win=pre_ones[j+1]-pre_ones[i];
            max_ones_in_win=std::max(max_ones_in_win,cnt_ones_in_win);
            i++;
            j++;
        }
        
        return nb_ones-max_ones_in_win;
    }
};
// @lc code=end

