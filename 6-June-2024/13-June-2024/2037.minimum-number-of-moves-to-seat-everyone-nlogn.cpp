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
        Time complexity: O(2nlogn+n)
        Extra space complexity: O(logn)
    */
   
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int ans=0;
        int n=seats.size();
        for(int i=0;i<n;++i) ans+=abs(seats[i]-students[i]);
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