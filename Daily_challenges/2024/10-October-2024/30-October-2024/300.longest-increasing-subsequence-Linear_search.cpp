/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Linear search
    Time complexity: O(n^2)
    Space complexity: O(n)
*/
class Solution {
    public:
        /*
            if x in A, return index of x
            otherwise, return index of element > x
            if all elemnts are less than x, return -1
        */
        int index_of(std::vector<int>& A,int x){
            int n=A.size();
            for(int i=0;i<n;++i){
                if(A[i]==x || A[i]>x) return i;
            }
            return -1;
        }

        int lengthOfLIS(vector<int>& nums){
            int n = nums.size();
            std::vector<int> tmp;
            tmp.push_back(nums[0]);
            for(int i=1;i<n;++i){
                if(nums[i]>tmp.back()) tmp.push_back(nums[i]);
                else{
                    int j=index_of(tmp,nums[i]);
                    tmp[j]=nums[i];
                }
            }
            return tmp.size();
        }
};
// @lc code=end

