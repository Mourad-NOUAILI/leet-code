/*
 * @lc app=leetcode id=2037 lang=cpp
 *
 * [2037] Minimum Number of Moves to Seat Everyone
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    /*
        Time complexity: O(n+n++101)=O(2n+101)=O(n)
        Extra space complexity: O(101)=O(1)
    */

   
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int mx=std::max(*std::max_element(seats.begin(),seats.end()),*std::max_element(students.begin(),students.end()));
        std::vector<int> available(mx+1,0);
        for(auto& pos: seats) available[pos]++;
        for(auto& pos: students) available[pos]--;
        int ans=0;
        int x=0;
        for(auto& v: available){
            x+=v;
            ans+=abs(x);
        }
        return ans;
    }
};
// @lc code=end

/*
    [5,3,10,20,2]\n[1,4,60,5,8]\n

    [5,3,10,20,2,30,8,1,99]\n[2,3,10,11,1,4,60,5,8]\n

    [4,1,5,9]\n[1,3,2,6]\n

    [2,2,6,6]\n[1,3,2,6]\n
*/