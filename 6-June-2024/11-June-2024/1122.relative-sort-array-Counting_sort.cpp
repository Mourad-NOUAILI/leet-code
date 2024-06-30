/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
    /*
        Counting sort
        Time complexity: O(n+m+m+n+1001)=O(2n+2m)=O(n+m)
        Extra space complexity: O(1001)+O(1001)+O(n)
    */
    public:
        vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
            std::vector<int> count(1001,0),count_remaining(1001,0);
            for(auto& v: arr1) {
                count[v]++;
                count_remaining[v]++;
            }

            for(auto&v: arr2) count_remaining[v]=0;

            int n=arr1.size();
            int m=arr2.size();

            count[arr2[0]]--;
            for(int i=1;i<m;++i) count[arr2[i]]+=count[arr2[i-1]];

            int x=count[arr2[m-1]];
            for(int i=0;i<1001;++i){
                if(count_remaining[i]!=0){
                    count[i]+=x;
                    x=count[i];
                }
            }

            std::vector<int> ans(n);
            for(int i=n-1;i>=0;--i) ans[count[arr1[i]]--]=arr1[i];


            return ans;
        }
};
// @lc code=end

/*
 [2,3,1,3,2,4,6,19,9,2,7,7,19]\n[2,1,4,3,9,6]\n

*/
