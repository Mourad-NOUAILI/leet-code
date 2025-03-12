/*
 * @lc app=leetcode id=2375 lang=cpp
 *
 * [2375] Construct Smallest Number From DI String
 */

// @lc code=start
/*
    Recursion+backtracking: build the answer
    Time compelxity: O(n!)
    Space complexity: O(10+n)
*/
class Solution {
    public:
        std::string smallestNumber(std::string pattern) {
            int n=pattern.size();
            
            // Avoid repeated digits in the answer
            std::vector<int> is_used(10,0);

            std::string tmp_ans,ans;

            // Build the answer using backtracking
            auto solve=[&](int i,auto& self)->bool{
                // If the temporary answer is build
                if(tmp_ans.size()==n+1){
                    ans=tmp_ans; // take as a valid answer
                    return true;
                }

                // For every digit from 1 to 9
                for(int j=1;j<=9;++j){
                    if(is_used[j]) continue;

                    if(!tmp_ans.empty() && 
                            (pattern[i-1]=='I' && tmp_ans.back()>=j+'0' ||
                             pattern[i-1]=='D' && tmp_ans.back()<=j+'0')) continue;
                    
                    // if the digit is not used in the answer and the answer is mathing the pattern

                    is_used[j]=1; // Mark it as used

                    tmp_ans.push_back(j+'0'); // added to the answer
                    
                    // If the digit j is in place
                    if(self(i+1,self)) return true; // solve for the reamining digits

                    // Otherwise, backtrack and try for an other answer
                    is_used[j]=0;
                    tmp_ans.pop_back();
                }

                return false;
            };

            solve(0,solve);

            return ans;
        }
};
// @lc code=end

