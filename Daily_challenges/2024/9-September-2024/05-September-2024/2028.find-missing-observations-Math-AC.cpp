/*
 * @lc app=leetcode id=2028 lang=cpp
 *
 * [2028] Find Missing Observations
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Math
    Time complexity: O(m+n)
    Space complexity: O(1)
*/

typedef std::vector<int> vi;
class Solution {
    public:
        vi missingRolls(vi& rolls,int mean,int n){
            int m=rolls.size();
            int rolls_sum=std::accumulate(rolls.begin(),rolls.end(),0);
            int missing_sum=mean*(m+n)-rolls_sum;

            if(missing_sum>6*n || missing_sum<n) return {};

            int cell_val=missing_sum/n;
            int rem=missing_sum%n;

            /*
                ans={cell_val+1}*rem+{cell_val}*(n-rem);
                
                vi ans;
                for(int i=1;i<=n-rem;++i) ans.push_back(cell_val);
                for(int i=1;i<=rem;++i) ans.push_back(cell_val+1);
            */
            vi ans(n,cell_val);
            std::fill(ans.begin(),ans.begin()+rem,cell_val+1);

            return ans;
        }
};
// @lc code=end

