/*
 * @lc app=leetcode id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    /*
        Time complexity: O(n)
        Extra space complexity: O(1)
    */
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
        int n=customers.size();
        
        // Add all customers when the owner is not grumpy.
        long long not_grumpy_sum=0;
        for(int i=0;i<n;++i){
            if(grumpy[i]==0) {
                not_grumpy_sum+=customers[i];
                customers[i]=0; // Not added in the future
            }
        }

        // Apply the sliding window technique on the reamaining customers
        long long cur_sum=0;
        long long max_sum=0;
        int k=minutes;
        for(int i=0;i<n;++i){
            cur_sum+=customers[i];
            if(i>=k-1){
                max_sum=std::max(max_sum,cur_sum);
                cur_sum-=customers[i-k+1];
            }
        }

       
        return not_grumpy_sum+max_sum;
    }
};
// @lc code=end

/*
    [4,10,10]\n[1,1,0]\n2\n
*/