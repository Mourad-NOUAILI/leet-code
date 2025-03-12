/*
 * @lc app=leetcode id=2183 lang=cpp
 *
 * [2183] Count Array Pairs Divisible by K
 */

// @lc code=start
/*
    Brute force
    Time complexity:O(n^2)
    Space complexity: O(1)
*/
typedef std::vector<int> vi;
typedef long long ll;
class Solution {
    public:
        ll countPairs(vi& nums, int k) {
            int n=nums.size();
            ll ans=0;
            for(int i=0;i<n-1;++i){
                for(int j=i+1;j<n;++j){
                    if(nums[i]*1ll*nums[j]*1ll%k==0) ans++;
                }
            }
            return ans;
        }
};
// @lc code=end

