/*
 * @lc app=leetcode id=1726 lang=cpp
 *
 * [1726] Tuple with Same Product
 */

// @lc code=start
/*
    Brure force + Binary search - AC
    (TLE if time constraint 1s)
    Time complexity: O(nlogn+n^3 logn)
    Space complexity: O(logn)
*/
typedef std::vector<int> vi;
class Solution {
    public:
        int tupleSameProduct(vi& nums) {
            int n=nums.size();

            std::sort(nums.begin(),nums.end());

            // Fix a, c and d, then look for b using binary search
            // Same concept of (1. Two Sum)
            int ans=0;
            for(int i=0;i<n-2;++i){
                for(int j=i+1;j<n-1;++j){
                    for(int k=j+1;k<n;++k){
                        int a=nums[i];
                        int c=nums[k];
                        int d=nums[j];

                        // If we can not make a product with actual values (a,c,d)
                        if(c*d%a) continue;

                        // Otherwise, search b in the remaining part of the array
                        if(std::binary_search(nums.begin()+k,nums.end(),c*d/a)) ans+=8;
                    }
                }
            }
            return ans;
        }
};
// @lc code=end

