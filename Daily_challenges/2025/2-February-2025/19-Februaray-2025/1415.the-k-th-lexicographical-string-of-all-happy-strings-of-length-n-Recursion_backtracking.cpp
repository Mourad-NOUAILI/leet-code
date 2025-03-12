/*
 * @lc app=leetcode id=1415 lang=cpp
 *
 * [1415] The k-th Lexicographical String of All Happy Strings of Length n
 */

// @lc code=start
/*
    Recursive+backtracking: Generate all happy strings
    Time complexity: 
    Space complexity: 
*/
class Solution {
    public:
        std::string getHappyString(int n, int k) {
            int cnt=0; // index in sorted order list of happy strings
            std::string cur; // Generated happy string
            std::string ans; // Final answer
            
            // Function to generate happy strings in lexicographically order 
            auto solve=[&](auto& self)->void{
                // If we generate a happy string of size n
                if(cur.size()==n){
                    cnt++; // Increment the counter (its index in sorted order list of happy strings)
                    if(cnt==k) ans=cur; // If we read the k-th happy string, we get our answer
                    return;
                }
                
                // For each happy string, we use the letters 'a','b' and 'c'
                for(char c='a';c<='c';++c){
                    // If the generated string is not happy(cur[i-1]==c), go next letter
                    if(!cur.empty() && cur.back()==c) continue;

                    // Otherwise
                    cur.push_back(c); // Push the current letter to the current happy string
                    self(self); // Continue generating
                    if(!ans.empty()) return; // If we get our result, stop the process
                    cur.pop_back(); // Backtrack by removing the last character
                }
            };

            solve(solve);
            
            return ans;
    
        }
};
// @lc code=end

