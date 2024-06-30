/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    // Time complexity: O(n)
    // Extar time complexity: O(n)
    int specialArray(std::vector<int>& nums) {
        int n=nums.size();
    
        std::vector<int> freq(n+1,0);
        for(auto& ai: nums) freq[std::min(ai,n)]++;

        int cnt=0;
        for(int i=n;i>=0;--i){
            cnt+=freq[i];
            if(cnt==i) return i;
        }
       
        return -1;
    }
};
// @lc code=end

/*
    [0,4,3,0,4]\n
    =>3

    [2,3,5,10,1,7,1,0,11,30,0]\n
    ==>5 (5 values(5,10,7,11,30) >= 5)

    [2,5,5,10,1,7,1,0,11,30,0]\n
    ==>-1
*/