/*
 * @lc app=leetcode id=3042 lang=cpp
 *
 * [3042] Count Prefix and Suffix Pairs I
 */

// @lc code=start
/*
    STLs find and rfind
    Time compelxity: O(n^2.2m^2)
    Space compelxity: O(1)
    n: size of the words's list
    m: size of a word in the list of words

*/
class Solution {
    public:
        int countPrefixSuffixPairs(std::vector<std::string>& words) {
            int n=words.size();

            auto is_prefix_and_suffix=[&](std::string& needle,std::string& haystack)->bool{
                int n=haystack.size();
                int m=needle.size();
                if(n<m) return false;
                auto it1=haystack.find(needle);
                auto it2=haystack.rfind(needle);
                return it1==0 && it2==n-m;
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

