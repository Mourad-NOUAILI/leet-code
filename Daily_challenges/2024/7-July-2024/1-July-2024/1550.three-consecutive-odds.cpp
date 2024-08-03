/*
 * @lc app=leetcode id=1550 lang=cpp
 *
 * [1550] Three Consecutive Odds
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    bool threeConsecutiveOdds(std::vector<int>& arr){
        int n=arr.size();
        int i=0;
        while(i<=n-3){
            // Window of size 3
            if(arr[i]%2!=0&&arr[i+1]%2!=0&&arr[i+2]%2!=0) return true;
            i++;
        }
        return false;
    }
};
// @lc code=end

