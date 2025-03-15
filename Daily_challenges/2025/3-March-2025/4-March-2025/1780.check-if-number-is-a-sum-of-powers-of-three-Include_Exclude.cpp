/*
 * @lc app=leetcode id=1780 lang=cpp
 *
 * [1780] Check if Number is a Sum of Powers of Three
 */

// @lc code=start
/*
    Brute force: Recursion: Include/Exclude technique
    Time complexity: O(log_3(n).2^log_3(n))
    Space compelxity: O(log_3(n))
*/
class Solution {
    public:
        // Exponential power
        // Time compelxity: O(logb)
        // Space compelxity: O(1)
        int power(int a,int b){
            int res=1;
            while (b>0) {
                if (b&1) res*=a;
                a*=a;
                b/=2;
            }
            return res;
        }

        bool checkPowersOfThree(int n){
            // Determine de maximum power of 3 of n
            int max_level=log(n)/log(3);

            // Recursive function
            // The Include/Exclude technique ensure the exploration all distincts  possible powers of three
            auto solve=[&](int level,int sum,auto& self)->bool{
                // If we reach the maximum level
                if(level<0){
                    if(sum==n) return true; // If the sum is equal to n,return false 
                    return false; // Otherwise, return false
                }

                // If we reach the sum, before reaching the level
                if(sum>n) return false; // If sum is greater than n
                if(sum==n) return true;// If the sum is equal to n

                // Include 3^level to the sum, than pass the next level || Exclude 3^level from the sum, than pass the next level
                return self(level-1,power(3,level)+sum,self) || self(level-1,sum,self);
            };

            return solve(max_level,0,solve);
        }
};
// @lc code=end

