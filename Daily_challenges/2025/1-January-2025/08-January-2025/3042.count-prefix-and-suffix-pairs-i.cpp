/*
 * @lc app=leetcode id=3042 lang=cpp
 *
 * [3042] Count Prefix and Suffix Pairs I
 */

// @lc code=start
/*
    Three pointers
    Time compelxity: O(n^2.m)
    Space compelxity: O(1)
*/
class Solution {
    public:
        int countPrefixSuffixPairs(std::vector<std::string>& words) {
            int n=words.size();

            auto is_prefix_and_suffix=[&](std::string& needle,std::string& haystack)->bool{
                int n=haystack.size();
                int m=needle.size();
                if(n<m) return false;
                int i=0,j=n-m,k=0;
                while(k<m && haystack[i]==needle[k] && haystack[j]==needle[k]){
                    i++;
                    j++;
                    k++;
                }
                return k==m;
            };

            int ans=0;
            for(int i=0;i<n-1;++i){
                for(int j=i+1;j<n;++j){
                    if(is_prefix_and_suffix(words[i],words[j])) ans++;
                }
            }

            return ans;
        }
};
// @lc code=end

