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
        Time complexity: O(n+101+n+101)=O(2n+202)=O(n)
        Extra space complexity: O(101+n+n)=O(2n)=O(n)
    */

    std::vector<int> counting_sort(std::vector<int>& A){
        std::vector<int> count(101,0);
        for(auto& v: A) count[v]++;
        int n=A.size();
        count[0]--;
        for(int i=1;i<101;++i) count[i]+=count[i-1];
        std::vector<int> res(n);
        for(int i=n-1;i>=0;--i) res[count[A[i]]--]=A[i];
        return res;
    }
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        std::vector<int> sorted_seats=counting_sort(seats);
        std::vector<int> sorted_students=counting_sort(students);
        int ans=0;
        int n=seats.size();
        for(int i=0;i<n;++i) ans+=abs(sorted_seats[i]-sorted_students[i]);
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