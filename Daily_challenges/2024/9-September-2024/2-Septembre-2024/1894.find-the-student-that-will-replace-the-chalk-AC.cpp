/*
 * @lc app=leetcode id=1894 lang=cpp
 *
 * [1894] Find the Student that Will Replace the Chalk
 */

// @lc code=start

#include<bits/stdc++.h>
/*
    Math
    Time complexity: O(kn) - AC
    Space complexity: O(1)
*/
typedef std::vector<int> vi;
class Solution {
    public:
        int chalkReplacer(vi& chalk, int k) {
            int n=chalk.size();

            long long s=std::accumulate(chalk.begin(),chalk.end(),0*1ll);
            long long rem=(k*1ll)%s;

            k=(int)rem;
            for(int i=0;i<n;++i){
                k-=chalk[i];
                if(k<0) return i;
            }

            return -1; // Never reached
        }
};
// @lc code=end

