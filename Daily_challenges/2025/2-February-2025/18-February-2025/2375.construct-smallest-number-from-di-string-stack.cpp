/*
 * @lc app=leetcode id=2375 lang=cpp
 *
 * [2375] Construct Smallest Number From DI String
 */

// @lc code=start
/*
    Stack: build the answer
    Time compelxity: O(n)
    Space complexity: O(n)
*/
class Solution {
    public:
        std::string smallestNumber(std::string pattern) {
            pattern.push_back('I');

            int n=pattern.size();

            std::stack<int> st;
            
            std::string ans;
            for(int i=0;i<n;++i){
                st.push(i+1);
                if(pattern[i]=='I'){
                    while(!st.empty()){
                        ans.push_back(st.top()+'0');
                        st.pop();
                    }
                }
            }
            
            return ans;
        }
};
// @lc code=end

