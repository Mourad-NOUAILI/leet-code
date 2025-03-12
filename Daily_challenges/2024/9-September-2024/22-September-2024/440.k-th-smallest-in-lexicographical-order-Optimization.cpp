/*
 * @lc app=leetcode id=440 lang=cpp
 *
 * [440] K-th Smallest in Lexicographical Order
 */

// @lc code=start

#include<bits/stdc++.h>


/*
    Optimization: lust look in the subtree that
    contains the k-th number
    Time complexity: O((10 log_10 n)^2) - AC
    Space complexity: O(1)
*/
class Solution {
    public:
        int count_nodes(long long cur,int n){
            int cnt=0;
            long long next=cur+1;
            while(cur<=n){
                cnt+=std::min(n*1ll-cur+1*1ll,next-cur);
                cur*=10;
                next*=10;
            }
            return cnt;
        }

        int findKthNumber(int n, int k) {
            long long cur=1;
            k--; // We have already 1.
            while(k){
                int cnt=count_nodes(cur,n);
                if(cnt<=k){
                    cur++;
                    k-=cnt;
                }
                else {
                    cur*=10;
                    k--;
                }
            }
            return cur;
        }
};
// @lc code=end

