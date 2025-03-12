/*
 * @lc app=leetcode id=1894 lang=cpp
 *
 * [1894] Find the Student that Will Replace the Chalk
 */

// @lc code=start

#include<bits/stdc++.h>
/*
    Simulation
    Time complexity: O(kn) - TLE
    Space complexity: O(1)
*/
typedef std::vector<int> vi;
class Solution {
    public:
        int chalkReplacer(vi& chalk, int k) {
            int n=chalk.size();

            int ans=0;
            while(k>=0){
                for(int i=0;k>=0 && i<n;++i){
                    ans=i;
                    k-=chalk[i];
                }
            }

            return ans;
        }
};
// @lc code=end

