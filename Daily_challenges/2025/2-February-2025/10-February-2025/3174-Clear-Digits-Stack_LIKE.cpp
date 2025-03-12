/*
    Stack
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        std::string clearDigits(std::string s) {
            int n=s.size();

            // ans string will behave as a stack
            std::string ans;

            // For every character
            for(int i=0;i<n;++i){
                // If there is some characters before it (stack not empty) and
                // it is a digit
                // then remove the non-digit character (pop it from the stack) and pass the next character
                if(!ans.empty() && std::isdigit(s[i])) ans.pop_back();

                // If there is no characters before the current character
                // or it is not digit
                // then push it ot the stack and pass the next character
                else ans.push_back(s[i]); 
            }
            return ans;
        }
};