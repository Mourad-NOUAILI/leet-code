/*
 * @lc app=leetcode id=2597 lang=cpp
 *
 * [2597] The Number of Beautiful Subsets
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
    public:
        /*
         * Using backtracking, brute force all subsets, without storing them.
         * ....
         * Time complexity: O(2^n log n)
         * Extra space complexity: O(n) + O(n)
         */
        int beautifulSubsets(std::vector<int>& nums, int k) {
            std::map<int,int> count;
            int n=nums.size();

            auto solve=[&](int index,auto& self)->int{
                if(index>=n) return 1;
                
                int excluded=self(index+1,self); // Recursive call without including the current number.
                int included=0;
                // Check if we can continue with the current number nums[index]
                int v1=nums[index]+k;
                int v2=nums[index]-k;
                if( (count.find(v1)==count.end() || count[v1]==0) && (count.find(v2)==count.end() || count[v2]==0) ){  
                    // If yes
                    count[nums[index]]++; // include it
                    included=self(index+1,self); // Recursive call to continue with the included number.
                    count[nums[index]]--; // Exluded
                }
                return included+excluded;
            };

            return solve(0,solve)-1; // -1 for the empty set
        }
};
// @lc code=end

/*
    [5,6,8,2,4,6,4]\n2\n
    ==>31

    [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]\n2\n
    ==>2035
*/