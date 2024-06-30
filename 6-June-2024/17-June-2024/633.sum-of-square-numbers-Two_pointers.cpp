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
        Time complexity: O(sqrt(c))
        Extra space complexity: O(1)
    */
    bool judgeSquareSum(int c){
       ll a=0;
       ll b=ceil(sqrt(c));
       while(a<=b){
        if((ll)(a*a)+(ll)(b*b)>(ll)c) b--;
        else if((ll)(a*a)+(ll)(b*b)<(ll)c) a++;
        else return true;
       }
       return false;
    }
};
// @lc code=end

