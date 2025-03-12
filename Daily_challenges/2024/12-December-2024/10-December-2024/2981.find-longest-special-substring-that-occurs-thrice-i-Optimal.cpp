/*
 * @lc app=leetcode id=2981 lang=cpp
 *
 * [2981] Find Longest Special Substring That Occurs Thrice I
 */

// @lc code=start

/*
    Optimal: Single pass: get all substrings with their frequecies in an 2D array
    AC on part I, AC on part II
    Time complexity: O(26n+n+26n)=O(n)
    Space complexity: O(26n)=O(n)
*/
class Solution {
    public:
        int maximumLength(std::string s) {
            int n=s.size();

            // Store all possible substrings
            std::vector<std::vector<int>> freq(26,std::vector<int>(n+1,0));

            // Store all possible substrings, with their frequecies
            int len=1;
            for(int i=0;i<n;++i){
                if(i>0 && s[i]==s[i-1]) len++;
                else len=1;
                freq[s[i]-'a'][len]++;
            }   

           int ans=-1;
            for(int c=0;c<26;++c){
                for(int len=n;len>0;--len){

                    if(len<n) freq[c][len]+=freq[c][len+1];
                    if(freq[c][len]>=3) {
                        ans=std::max(ans,len);
                        break;
                    };
                }
            }
            return ans;
        }
};

// @lc code=end

