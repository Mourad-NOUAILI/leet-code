/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start
#include<bits/stdc++.h>
typedef long long ll;
class Solution {
public:
    /*
        Time complexity: O(c)
        Extra space complexity: O(1)
    */
    bool judgeSquareSum(int c){
        for(ll a=0;(ll)(a*a)<=c;++a){
            for(ll b=0;(ll)(b*b)<=c;++b){
                if((ll)(a*a)+(ll)(b*b)==(ll) c) return true;
            }
        }
        return false;
    }
};
// @lc code=end

