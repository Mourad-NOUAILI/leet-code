/*
 * @lc app=leetcode id=2183 lang=cpp
 *
 * [2183] Count Array Pairs Divisible by K
 */

// @lc code=start
/*
    Hashing+GCD
    Time complexity:O(nsqrt(k))
    Space complexity: O(sqrt(k))
*/
typedef std::vector<int> vi;
typedef long long ll;
typedef std::vector<ll> vll;
class Solution {
    public:
        ll countPairs(vi& nums, int k) {
            std::unordered_map<ll,ll> gcd_freq;
            ll ans=0;
            for(auto& a: nums){
                ll gcd_ak=std::gcd(a,k);
                for(auto& [g,f]: gcd_freq) ans+=(gcd_ak*g%k==0)?f:0;
                gcd_freq[gcd_ak]++;
            }
            return ans;
        }
};
// @lc code=end

