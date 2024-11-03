/*
 * @lc app=leetcode id=2053 lang=cpp
 *
 * [2053] Kth Distinct String in an Array
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    brute force
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
class Solution {
public:
    std::string kthDistinct(std::vector<std::string>& arr, int k) {
       int n=arr.size();
       for(int i=0;i<n;++i){
        bool ok=true;
        int j=0;
        while(j<n&&ok){
            if(i!=j&&arr[i]==arr[j]) ok=false;
            j++;
        }
        if(ok) k--;
        if(k==0) return arr[i];
       }
       return "";
    }
};
// @lc code=end

