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

        // Create a window of size 3
        int s=0;
        for(int i=0;i<3&&i<n;++i) s+=arr[i]%2;

        if(s==3) return true;

        // Keep sliding the window to the left
        int i=0;
        while(i<=n-3&&s!=3){
            s-=arr[i]%2;
            s+=arr[i+3]%2;
            if(s==3) return true;
            i++;
        }
        return false;
    }
};
// @lc code=end

