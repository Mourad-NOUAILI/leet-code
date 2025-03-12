/*
 * @lc app=leetcode id=1980 lang=cpp
 *
 * [1980] Find Unique Binary String
 */

// @lc code=start
/*
    Generate all binary strings 
    Time Complexity: O(n+n2^n)=O(n.2^n) 
    Space complexity: O(3n)
*/
class Solution {
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        int n=nums.size();

        // Mark all binary strings in nums
        std::unordered_map<std::string,bool> exists;
        for(auto& bin: nums) exists[bin]=true;
        
        // Function to generate al binary string from 0 to 2^n - 1
        auto generate=[&](int i,std::string& bin,std::string& ans,auto& self)->void{
            // If size of generated binary string is equal to n
            if(i==n){
                // Lookit up, if does not exists
                if(!exists[bin]){
                    ans=bin; // Take it as an answer
                    return;
                }
                return;
            }

            // First assign "0" at i-th position
            // and try for all other permutations
            // for remaining positions
            bin[i]='0';
            self(i+1,bin,ans,self);

            // If we found an answer, stop the process
            if(!ans.empty()) return;

            // And then assign "1" at ith position
            // and try for all other permutations
            // for remaining positions
            bin[i]='1';
            self(i+1,bin,ans,self);

            // If we found an answer, stop the process
            if(!ans.empty()) return;
        };

        std::string bin(n,0),ans;
        generate(0,bin,ans,generate);

        return ans;
    }
};
// @lc code=end

