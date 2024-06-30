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
        Time complexity: O(n+n+n++101)=O(3n+101)=O(n)
        Extra space complexity: O(101+101)=O(1)
    */

   
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        std::vector<int> count_seats(101,0);
        std::vector<int> count_students(101,0);
        for(auto& seat: seats) count_seats[seat]++;
        for(auto& student: students) count_students[student]++;

        int ans=0;
        int i=0,j=0;
        int n=seats.size();

        while(n){
            if(!count_seats[i]) i++;
            if(!count_students[j]) j++;
            if(count_seats[i]&&count_students[j]){
                ans+=abs(i-j);
                count_seats[i]--;
                count_students[j]--;
                n--;
            }
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