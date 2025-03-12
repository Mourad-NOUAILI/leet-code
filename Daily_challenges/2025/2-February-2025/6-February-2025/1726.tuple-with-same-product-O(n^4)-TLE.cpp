/*
 * @lc app=leetcode id=1726 lang=cpp
 *
 * [1726] Tuple with Same Product
 */

// @lc code=start
/*
    Brure force -TLE
    Time complexity: O(nlogn+n^4)
    Space complexity: O(logn)
*/
typedef std::vector<int> vi;
class Solution {
    public:
        int tupleSameProduct(vi& nums) {
            int n=nums.size();

            std::sort(nums.begin(),nums.end());

            // Try all possibilities
            int ans=0;
            for(int i=0;i<n-3;++i){
                for(int j=i+1;j<n-2;++j){
                    for(int k=j+1;k<n-1;++k){
                        for(int l=k+1;l<n;++l){
                            int a=nums[i];
                            int b=nums[l];
                            int c=nums[k];
                            int d=nums[j];
                            
                            if(a*b==c*d) ans+=8;
                        }
                    }
                }
            }
            return ans;
        }
};
// @lc code=end

