/*
 * @lc app=leetcode id=2466 lang=cpp
 *
 * [2466] Count Ways To Build Good Strings
 */

// @lc code=start
/*
    Include/Exclude technique+Memoization
    Time compelxity: O(high)
    Space complexity: O(2high)
*/
class Solution {
    public:
        int countGoodStrings(int low, int high, int zero, int one) {
            std::vector<int> memo(high+1,-1);

            auto solve=[&](int len,auto& self)->long long{
                if(len>high) return 0;
                if(len==high) return 1;
                
                if(memo[len]!=-1) return memo[len];

                int ans=0;

                ans+=self(zero+len,self);
                ans+=self(one+len,self);

                if(len>=low) ans++;

                return memo[len]=ans%1000000007;
            };

            return solve(0,solve);
        }
};
// @lc code=end

