/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
    /*
        Brute force
        Time complexity: O(n*m+nlogn+n)
        Extra space complexity: O(1)
    */
    public:
        vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
           std::vector<int> ans;
        int n=arr1.size();
        int m=arr2.size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(arr2[i]==arr1[j]){
                    ans.push_back(arr1[j]);
                    arr1[j]=-1;
                }
            }
        }

        sort(arr1.begin(),arr1.end());

        for(auto& v: arr1){
            if(v!=-1) ans.push_back(v);
        }


        return ans;
        }
};
// @lc code=end

/*
 [2,3,1,3,2,4,6,19,9,2,7,7,19]\n[2,1,4,3,9,6]\n

*/
