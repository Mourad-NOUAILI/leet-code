/*
 * @lc app=leetcode id=1415 lang=cpp
 *
 * [1415] The k-th Lexicographical String of All Happy Strings of Length n
 */

// @lc code=start
/*
    Recursive+backtracking: Generate all happy strings o the group where the k-th
    happy string belongs
    Time complexity: O(2^n)
    Space compelxity: O(n)
*/
class Solution {
    public:
        std::string getHappyString(int n, int k) {
            // Count total happy string in each group
            int group_count=1<<(n-1);

            // Count total number of happy strings
            int happy_count=3*group_count;

            // If k exceeds the total number of happy strings
            if(k>happy_count) return "";

            // Determine which group belongs the k-th happy string ('a','b' or 'c')
            int group=ceil(k*1.0/group_count*1.0);

            // Update k of the k-th happy string in the its group 
            k=k-(group-1)*group_count;
            
            int cnt=0; // index in sorted order list of happy strings

            std::string cur; // Generated happy string
            cur.push_back((group-1)+'a'); // We know, which group belong the k-th happy string

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
                    if(cur.back()==c) continue;

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

