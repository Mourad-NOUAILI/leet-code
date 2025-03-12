/*
 * @lc app=leetcode id=1400 lang=cpp
 *
 * [1400] Construct K Palindrome Strings
 */

// @lc code=start
/*
    Math: counting number of odds frequencies
    using an array for frequencies
    Time Complexity:O(26+n+26)=O(n)
    Space compelxity: O(26)=O(1)

*/
class Solution{
    public:
        bool canConstruct(std::string s, int k){
            if(k>s.size()) return false;
            std::vector<int> freq(26,0);
            for(auto& letter: s) freq[letter-'a']++;
            int count_odd=0;
            for(auto& f: freq) count_odd+=(f!=0&&f%2);
            return count_odd<=k;
        }
};
// @lc code=end

