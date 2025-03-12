/*
 * @lc app=leetcode id=2981 lang=cpp
 *
 * [2981] Find Longest Special Substring That Occurs Thrice I
 */

// @lc code=start

/*
    Brute force: Space optimization
    AC on part I, TLE on part II
    Time complexity:O(n^2 log n)
    Space complexity: O(n)
*/
class Solution {
    public:
        int maximumLength(std::string s) {
            int n=s.size();

            // Store all possible substrings
            std::map<std::pair<char,int>,int> freq;

            // Get all substrings
            for(int i=0;i<n;++i){
                char c=s[i];
                int len=0;
                for(int j=i;j<n;++j){
                    if(s[j]==c){
                       len++;
                       freq[{c,len}]++;
                    }
                    else break;
                }
            }

            int ans=-1;
            for(auto& [p,f]: freq){
                // get longest substring which its frequency is greater or equal to 3
                if(f>=3) ans=std::max(ans,p.second);
            }
            return ans;
        }
};

// @lc code=end

