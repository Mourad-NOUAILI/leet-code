/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    // Time complexity: O(n²)
    // Extar time complexity: O(1)
    int specialArray(std::vector<int>& nums) {
        int n=nums.size();
        for(int x=1;x<=n;++x){
            int cnt=0;
            for(auto& ai: nums){
                if(cnt>x) break;
                if(ai>=x) cnt++;
            }
            if(cnt==x) return cnt;
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