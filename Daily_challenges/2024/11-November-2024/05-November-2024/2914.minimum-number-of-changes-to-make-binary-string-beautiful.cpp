/*
 * @lc app=leetcode id=2914 lang=cpp
 *
 * [2914] Minimum Number of Changes to Make Binary String Beautiful
 */

// @lc code=start
/*
    One pointer
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution {
    public:
        int minChanges(std::string s){
            int n=s.size();
            int ans=0;
            for(int i=0;i<n-1;i+=2){
                if(s[i]!=s[i+1]) ans++;
               
            }
            return ans;
        }
};
// @lc code=end

