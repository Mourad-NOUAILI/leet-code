/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
/*
    Prefix array + Suffix array
    Time compelxity: O(5n)
    Space complexity: O(2n)
*/
class Solution {
public:
    int maxScore(std::string s){
        int n=s.size();

        std::vector<int> prefix_0(n);
        prefix_0[0]=int(s[0]=='0');
        for(int i=1;i<n;++i) prefix_0[i]=prefix_0[i-1]+int(s[i]=='0');

        std::vector<int> suffix_1(n);
        suffix_1[n-1]=int(s[n-1]=='1');
        for(int i=n-2;i>=0;--i) suffix_1[i]=suffix_1[i+1]+int(s[i]=='1');

        int ans=0;
        for(int i=0;i<n-1;++i){
            ans=std::max(ans,prefix_0[i]+suffix_1[i+1]);
        }
        return ans;
    }
};
// @lc code=end

