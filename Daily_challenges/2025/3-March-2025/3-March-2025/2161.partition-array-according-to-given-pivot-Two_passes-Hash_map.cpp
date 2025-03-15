/*
 * @lc app=leetcode id=2161 lang=cpp
 *
 * [2161] Partition Array According to Given Pivot
 */

// @lc code=start
/*
    Two passes: Mapping with array+fill answer
    Time complexity: O(2n)
    Space complexity: O(n)
*/
class Solution {
    public:
        std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
            // Pass #1: Mapping
            // mapping[0]: contains all elements less than pivot
            // mapping[1]: contains all elements equal pivot
            // mapping[2]; contains all elements greater than pivot
            std::vector<std::vector<int>> mapping(3);
            for(auto& e: nums){
                if(e<pivot) mapping[0].push_back(e);
                else if(e==pivot) mapping[1].push_back(e);
                else mapping[2].push_back(e);
            }

            // Pass #2: Fill the answer
            std::vector<int> ans;
            for(int i=0;i<=2;++i){
                for(auto& e: mapping[i]) ans.push_back(e);
            }

            return ans;
        }
};
// @lc code=end

