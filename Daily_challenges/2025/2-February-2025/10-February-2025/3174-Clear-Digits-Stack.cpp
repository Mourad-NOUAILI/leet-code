/*
    Stack
    Time complexity: O(3n)
    Space complexity: O(n)
*/
class Solution {
    public:
        std::string clearDigits(std::string s) {
            int n=s.size();

            std::stack<char> st;

            // For every character
            for(int i=0;i<n;++i){
                // If there is some characters before it (stack not empty) and
                // it is a digit
                // then remove the non-digit character (pop it from the stack) and pass the next character
                if(!st.empty() && std::isdigit(s[i])) st.pop();

                // If there is no characters before the current character
                // or it is not digit
                // then push it ot the stack and pass the next character
                else st.push(s[i]); 
            }

            // Get element from the stack
            // ans will be in reverse order
            std::string ans;
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }

            // Reverse the answser
            std::reverse(ans.begin(),ans.end());

            return ans;
        }
};