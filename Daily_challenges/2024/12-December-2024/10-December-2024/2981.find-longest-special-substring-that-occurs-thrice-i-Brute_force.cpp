/*
 * @lc app=leetcode id=2981 lang=cpp
 *
 * [2981] Find Longest Special Substring That Occurs Thrice I
 */

// @lc code=start

/*
    Brute force: get all substrings with their frequecies in a hash map
    AC on part I, TLE on part II
    Time complexity: O(n^3)
    Space complexity: O(n^2)
   
*/
class Solution {
    public:
        int maximumLength(std::string s) {
            int n=s.size();

            // Store all possible substrings
            std::unordered_map<std::string,int> freq;

            // Get all substrings
            for(int i=0;i<n;++i){
                std::string sub;
                for(int j=i;j<n;++j){
                    if(sub.empty() || sub.back()==s[j]){
                        sub.push_back(s[j]);
                        freq[sub]++;
                    }
                    else break;
                }
            }

            int ans=-1;
            for(auto& [s,f]: freq){
                std::cout<<s<<'/'<<f<<'\n';
                // get longest substring which its frequency is greater or equal to 3
                if(f>=3) ans=std::max(ans,int(s.size()));
            }
            return ans;
        }
};

// @lc code=end

