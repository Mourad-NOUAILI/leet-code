/*
 * @lc app=leetcode id=2425 lang=cpp
 *
 * [2425] Bitwise XOR of All Pairings
 */

// @lc code=start
/*
    XOR properties
    Time compexity: O(n+m)=O(n)
    Space complexity: O()
*/
class Solution {
    public:
        int xorAllNums(std::vector<int>& nums1, std::vector<int>& nums2){
            auto solve=[&](std::vector<int>&A)->int{
                int ans=0;
                for(auto& e: A) ans^=e;
                return ans;
            };

            int n=nums1.size();
            int m=nums2.size();
            
            if(n%2==0 && m%2==0) return 0;
            if(n%2==1 && m%2==1) return solve(nums1)^solve(nums2);
            if(n%2==0) return solve(nums1);
            return solve(nums2);
        }
    };
// @lc code=end

