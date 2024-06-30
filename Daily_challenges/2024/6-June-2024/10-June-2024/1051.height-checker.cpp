/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
    public:
        /*
            Version #1(Not implemented): sort in O(nlogn)
        */

        /*
            Version #2: Using counting sort
            Time complexity: O(n+101)=O(n)
            Extra space complexity: O(n+101)
        */
        vector<int> counting_sort(vector<int>& A){
            std::vector<int> count(101,0);
            for(auto& ai: A) count[ai]++;
            
            count[0]--;
            for(int i=1;i<=100;++i) count[i]+=count[i-1];

            int n=A.size();
            std::vector<int> B(n);
            for(int i=n-1;i>=0;--i) B[count[A[i]]--]=A[i];

            return B;
        }

        int heightChecker(vector<int>& heights) {
            int n=heights.size();

            vector<int> expected=counting_sort(heights);

            int ans=0;
            for(int i=0;i<n;++i)ans+=heights[i]!=expected[i];
            
            return ans;
        }
};
// @lc code=end

