/*
 * @lc app=leetcode id=2597 lang=cpp
 *
 * [2597] The Number of Beautiful Subsets
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
    public:
        int ans=0;
    public:
        /*
        * Using backtracking, brute force all subsets, for each one check if there exists two elements, such as
        * their abs difference is equal to k.
        * Time complexity: O(2^n + n²): Get all subsets: 2^n , check subset: n²
        * Extra space complexity: DFS:O(n) + subset: O(n)   
        */
        void solve(int index,std::vector<int>& nums, int k, std::vector<int>& subset){
             auto check=[&](std::vector<int>& subset,int k)->bool{
                    int m=subset.size();
                    if(m==0) return false;
                    for(int i=0;i<m;++i){
                        for(int j=0;j<m;++j){
                            if(abs(subset[i]-subset[j])==k*1u) return false;
                        }
                    }
                    return true;
                };

            
            if(check(subset,k)) ans++;

            for(int i=index;i<nums.size();++i){
                subset.push_back(nums[index]);
                solve(i+1,nums,k,subset);
                subset.pop_back();
            }
           
        }

        int beautifulSubsets(std::vector<int>& nums, int k) {
            std::vector<int> subset;
            solve(0,nums,k,subset);
            return ans;
    
        }
};
// @lc code=end

/*
    [5,6,8,2,4,6,4]\n2\n
    ==>31

    [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]\n2\n
    ==>2035
*/