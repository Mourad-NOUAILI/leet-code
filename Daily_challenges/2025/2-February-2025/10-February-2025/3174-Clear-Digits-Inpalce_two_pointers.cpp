/*
    In place: two pointers
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        std::string clearDigits(std::string& s) {
            int n=s.size();

            int w=0; // Pointer to write characters
            // For every character
            // r: pointer to read characters
            for(int r=0;r<n;++r){
                // If current character is a digit, reduce the wrire pointer by 1
                // because the character to the left should be removed 
                if(std::isdigit(s[r])) w=std::max(w-1,0);

                // Otherwise, write the character pointer by the read
                // pointer in its correct place
                else s[w++]=s[r]; 
            }

            // Return all overwritten characters 
            return s.substr(0,w);
        }
};