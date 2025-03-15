/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 */

// @lc code=start
/*
    Prefix sums+two pointers (at least(1) ‘a’, at least(1) ‘b’, at least(1) ‘c’)
    Time complexity: O(n)
    Space complexity: O(3)=O(1)
*/
class Solution {
public:
    int numberOfSubstrings(std::string s) {
        int n=s.size();
        int count[3]={0};

        int l=0,ans=0;
        for(int r=0;r<n;++r){
            count[s[r]-'a']++;
            while(count[0]>=1 && count[1]>=1 && count[2]>=1){
                ans+=n-r;
                count[s[l]-'a']--;
                l++;
            }
        }

        return ans;
    }
};
// @lc code=end

