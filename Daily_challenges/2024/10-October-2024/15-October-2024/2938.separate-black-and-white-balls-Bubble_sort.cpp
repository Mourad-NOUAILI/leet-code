/*
 * @lc app=leetcode id=2938 lang=cpp
 *
 * [2938] Separate Black and White Balls
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Straight forward simulation: Bubble sort
    Time complexity: O(n^2)
    Space complexity: O(n)
*/
class Solution {
    public:
        long long minimumSteps(string& s) {
            int n=s.size();
            bool is_swapped=true;
            long long ans=0;
            while(n>1 && is_swapped){
                    is_swapped=false;
                    for(int i=0;i<n-1;++i){
                        if(s[i]=='1' && s[i+1]=='0'){
                            std::swap(s[i],s[i+1]);
                            ans++;
                            is_swapped=true;
                        }
                    }
                    n--;
            }
            return ans;
        }
};
// @lc code=end

