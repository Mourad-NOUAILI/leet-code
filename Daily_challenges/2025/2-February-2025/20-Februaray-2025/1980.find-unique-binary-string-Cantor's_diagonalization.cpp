/*
 * @lc app=leetcode id=1980 lang=cpp
 *
 * [1980] Find Unique Binary String
 */

/*
    Cantor's diagonalization 
    Time complexity: O(n)
    Space complexity: O(1)
*/
// @lc code=start
class Solution {
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        int n=nums.size();
        std::string ans;
        for(int i=0;i<n;++i){
            ans+=nums[i][i]=='1'?'0':'1';
        }
        return ans;
    }
};
// @lc code=end

