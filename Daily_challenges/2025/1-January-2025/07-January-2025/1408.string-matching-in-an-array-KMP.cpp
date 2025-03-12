/*
 * @lc app=leetcode id=1408 lang=cpp
 *
 * [1408] String Matching in an Array
 */

// @lc code=start
/*
    KMP
    Time complexity: O(n^2*m)
    Space complexity: O(m)
    n: size of the words's list
    m: size of a word in the list of words 
*/
class Solution {
    public:
        // Function to check if a needle match is a haystack using KMP algorithm
        // Time complexity: O(m+n)
        // Space complexity: O(m)
        bool is_match(std::string& haystack,std::string& needle){
            if(needle=="") return false;

            // Longest prefix suffix
            int n=haystack.size();
            int m=needle.size();
            std::vector<int> lps(m,0);
            int prev_lps_index=0,i=1;
            while(i<m){
                if(needle[prev_lps_index]==needle[i]){
                    lps[i]=prev_lps_index+1;
                    prev_lps_index++;
                    i++;
                }
                else if(prev_lps_index==0){
                    lps[i]=0;
                    i++;
                }
                else prev_lps_index=lps[prev_lps_index-1];
            }


            i=0; // Pointer for haystack
            int j=0; // Pointer for needle
            while(i<n){
                if(haystack[i]==needle[j]){
                    i++;
                    j++;
                }
                else if(j==0) i++;
                else j=lps[j-1];
                
                if(j==m) return true;
            }
            return false;
        }

        std::vector<std::string> stringMatching(std::vector<std::string>& words){
            int n=words.size();
            std::vector<std::string> ans;
            // For each words[i] as a needle:
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    // take words[j] as a haystack
                    // if same string ignore it
                    if(i==j) continue;

                    // If the the needle words[i] math in the haystack words[j]
                    // add the needle words[i] to the answer
                    if(is_match(words[j],words[i])){
                        ans.push_back(words[i]);
                        break; // ans must contains unique words
                    }
                }
            }

            return ans;
        }
};
// @lc code=end

