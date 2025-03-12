/*
 * @lc app=leetcode id=2683 lang=cpp
 *
 * [2683] Neighboring Bitwise XOR
 */

// @lc code=start
/*
    Xor properties
    Time complexity: O(n)
    Space complexity: O(1)
*/

class Solution {
    public:
        bool doesValidArrayExist(std::vector<int>& derived){
            int total_xor=0;
            for(auto& e: derived) total_xor^=e;
            return total_xor==0;
        }
};

class Solution {
public:
    bool doesValidArrayExist(std::vector<int>& derived){
        int s=std::accumulate(derived.begin(),derived.end(),0);
        return s%2==0;
    }
};
// @lc code=end

