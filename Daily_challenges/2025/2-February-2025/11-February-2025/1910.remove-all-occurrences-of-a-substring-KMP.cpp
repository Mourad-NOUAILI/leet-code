/*
 * @lc app=leetcode id=1910 lang=cpp
 *
 * [1910] Remove All Occurrences of a Substring
 */

// @lc code=start
/*
    KMP
    Time complexity: O(m+(n/m)*m)=O(m+n)
    Space complexity: O(2m+n)
*/
class Solution {
    public:
        // KMP: return the longest prefix suffix array
        std::vector<int> kmp(std::string& needle){
            int m=needle.size();
            std::vector<int> lps(m,0);
            for(int current=1;current<m;++current ){
                int prefix_len=lps[current-1];
                while(prefix_len>0 && needle[prefix_len]!=needle[current]){
                    prefix_len=lps[prefix_len-1];
                }
                lps[current]=prefix_len+(needle[current]==needle[prefix_len]);
            }
            return lps;
        }

        std::string removeOccurrences(std::string s, std::string part) {
            int n=s.size();
            int m=part.size();

            std::vector<int> lps=kmp(part);

            std::string ans; // To store the answer

            // To store the matching prefix length during traversal
            std::vector<int> prefix_match_len;

            // For each character in s 
            for(int i=0;i<n;++i){
                // Add it to answer
                ans.push_back(s[i]);

                // Get the length of the last matching prefix
                int j=prefix_match_len.empty()?0:prefix_match_len.back();

                // While the length of last matching prefix is not zero,
                // and we have a mismatch between the current character in s
                // and the j-th character in part, the back the previous match,
                // which is lps[j-1].
                while(j>0 && s[i]!=part[j]) j=lps[j-1];

                // If the current character in s and the j-th character in part are equal
                // pass to next charatcer in part. 
                if(s[i]==part[j]) j++;

                // Add that length to the array
                prefix_match_len.push_back(j);

                // If we have a complete match
                if(j==m){
                    // Delete de last m characters from the answer
                    for(int j=0;j<m;++j){
                        ans.pop_back();
                        prefix_match_len.pop_back();
                    }
                }
            }

            return ans;
        }
};
// @lc code=end

