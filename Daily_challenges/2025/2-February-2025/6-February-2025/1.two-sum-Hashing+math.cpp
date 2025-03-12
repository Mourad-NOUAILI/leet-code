/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

/*
    Hashing+Math
    Time complexity: O(n)
    Space complexity: O(n)
*/
typedef std::vector<int> vi;

class Solution {
    public:
        vi twoSum(vi& nums, int target) {
            int n=nums.size();

            std::unordered_map<int,int> seen;

            for(int i=0;i<n;++i){
                if(seen.find(nums[i])!=seen.end()) return {seen[nums[i]],i};
                seen[target-nums[i]]=i;
            }
            
            return {};
        }
};
// @lc code=end

