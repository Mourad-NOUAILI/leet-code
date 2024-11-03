/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Naive
    Time complexity: O(n^2) - TLE
    Space complexity: O(1)
*/
class Solution {
public:
    bool are_prime_factors_2_3_5(int m){
        int d=2;
        while(m!=1){
            if(m%d==0){
                if(d!=2&&d!=3&&d!=5) return false;
                m/=d;
            }
            else d++;
        }
        return true;
    }
    int nthUglyNumber(int n){
        int cnt=0,m=0;
        while(cnt<n){
            m++;
            if(are_prime_factors_2_3_5(m)) cnt++;
        }
        return m;
    }
};
// @lc code=end

