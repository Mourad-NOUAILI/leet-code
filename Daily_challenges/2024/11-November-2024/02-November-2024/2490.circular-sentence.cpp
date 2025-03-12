/*
 * @lc app=leetcode id=2490 lang=cpp
 *
 * [2490] Circular Sentence
 */

// @lc code=start


/*
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        bool isCircularSentence(std::string sentence){
            int n=sentence.size();
            if(sentence[0]!=sentence[n-1]) return false;
            for(int i=0;i<n;++i){
                if(sentence[i]==' ' && sentence[i-1]!=sentence[i+1]) return false;
            }
            return true;
        }
};


/*
    C++ STL all_of
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        bool isCircularSentence(std::string s){
            return s[0]==s.back() && std::all_of(s.begin(), s.end(), [&, i=0](auto _) mutable{
                        return !i++|| s[i]!=' ' || s[i-1]==s[i+1];
            });
        }
};

// @lc code=end

