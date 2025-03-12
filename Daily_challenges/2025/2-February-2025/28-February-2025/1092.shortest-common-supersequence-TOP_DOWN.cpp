/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence 
 */

// @lc code=start
/*
    Phase#1: Recursion Top-Down: build DP table to find the longest common subsequence(LCS)
    Phase#2: Use DP table to build the answer.

    Time complexity: O(nm+(n+m))
    Space complexity: O(nm)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
    public:
        
        std::string shortestCommonSupersequence(std::string str1, std::string str2){
            int n=str1.size();
            int m=str2.size();

            // Phase #1: Determie Longest common subsequence

            // Memoize answers
            vvi memo(n+1,vi(m+1,0));

            // Recursive function to compute longest common subsequence
            auto lcs=[&](int i,int j,auto& self)->int{
                if(i==n || j==m) return 0;
                if (memo[i][j] != 0) return memo[i][j];
                if(str1[i]==str2[j]) return memo[i][j]=1+self(i+1,j+1,self);
                return memo[i][j]=std::max(self(i+1,j,self),self(i,j+1,self));
            };

            // Phase #2: Get the shortest common supersequence
            // Using the DP memo array of phase #1 to build the answer
            auto get_lcs=[&]()->std::string{
                std::string ans="";
                int i=0,j=0;
                // While both string not terminated
                while(i<n&&j<m){
                    // If letters are not equal
                    if(str1[i]!=str2[j]){
                        // If the result in memo[i][j] came from the down cell
                        if(memo[i+1][j]>memo[i][j+1]){
                            ans+=str1[i];
                            i++;
                        }
                        // If the result in memo[i][j] came from the right cell
                        else{
                            ans+=str2[j];
                            j++;
                        }
                    }
                    // If letters are equal
                    else{
                        ans+=str1[i];
                        i++;
                        j++;
                    }
                }

                // Add remaining letters to answer
                while(i<n) ans+=str1[i++];
                while(j<m) ans+=str2[j++];
                
                return ans;
            };

            lcs(0,0,lcs);


            return get_lcs();
        }
};
// @lc code=end

