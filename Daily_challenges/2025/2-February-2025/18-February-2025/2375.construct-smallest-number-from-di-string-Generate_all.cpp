/*
 * @lc app=leetcode id=2375 lang=cpp
 *
 * [2375] Construct Smallest Number From DI String
 */

// @lc code=start
/*
    Brute force: Generate all possibilities and check
    Time compelxity: O(9!.n/(8-n)!)
    Space complexity: O(9+2n)
*/
class Solution {
    public:
        std::string smallestNumber(std::string pattern) {
            int n=pattern.size();
            
            // Digits to use for the answer
            std::string charset="123456789";

            // Avoid repeated digits in the answer
            std::vector<int> is_used(10,0);

            std::string ans="9999999999",tmp_ans;

            // Recursive function+backtracking to generate all possibilities
            // for each possible answer, check if is matching the given pattern 
            auto generate_all=[&](int k,auto& self){
                
                // Function to check if a string mathes a pattern
                auto is_matching=[&](std::string& s,std::string& p)->bool{
                    for(int i=0;i<n;++i){
                        if(p[i]=='I' && s[i]>s[i+1] || p[i]=='D' && s[i]<s[i+1]) return false;
                    }
                    return true;
                };

                // If the answer string is created
                if(k==0){
                    // check if it matches the pattern,
                    // if yes, minimize it
                    if(is_matching(tmp_ans,pattern)) ans=std::min(ans,tmp_ans);
                    return;
                }
                // Try all digits from 1 to 9
                for(int i=0;i<9;++i){
                    // if the digit is not used in the answer
                    if(!is_used[charset[i]-'0']){
                        is_used[charset[i]-'0']=1; // Mark it as used
                        tmp_ans.push_back(charset[i]); // added to the answer

                        self(k-1,self); // solve for the reamining digits

                        // Backtrack and try other answer
                        is_used[charset[i]-'0']=0;
                        tmp_ans.pop_back();
                    }
                }
            };


            // Generate all the strings of size (n+1) using the charest="123456789"
            generate_all(n+1,generate_all);

            return ans;
        }
};
// @lc code=end

