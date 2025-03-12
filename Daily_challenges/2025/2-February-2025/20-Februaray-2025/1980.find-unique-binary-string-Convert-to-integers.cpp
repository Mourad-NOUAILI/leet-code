/*
 * @lc app=leetcode id=1980 lang=cpp
 *
 * [1980] Find Unique Binary String
 */

// @lc code=start
/*
    Convert to integers equivalents
    Time Complexity: O(n^2+log_10(number)*2^n) 
    Space complexity: O(2^n)
*/
class Solution {
    public:
        std::string findDifferentBinaryString(std::vector<std::string>& nums) {
            int n=nums.size();

            // 2^n - 1: maximum number of n bits
            int m=1<<n;

            // Array of size to 2^n, to store numbers from 0 to 2^n - 1
            std::vector<int> exists(m,0);

            // For each binary string bin
            for(auto& bin: nums){
                // Converted to its equivalent decimal number
                int p=1<<(n-1);
                int number=0;
                for(auto& bit: bin){
                    number+=(bit=='1'?1:0)*p;
                    p/=2;
                }

                // Mark that number as exists
                exists[number]=1;
            }

            // For each number from 0 to 2^n - 1
            for(int number=0;number<m;++number){
                // If it does not exist
                if(!exists[number]){
                    // Converted to a binary string
                    std::string ans(n,'0');
                    int i=n-1;
                    while(number!=0){
                        ans[i--]=number%2+'0';
                        number/=2;
                    }

                    // Return it
                    return ans;
                }
            }

            return ""; // Never reachedn beacause it exists at least 1 answer
        }
};
// @lc code=end

