/*
 * @lc app=leetcode id=2364 lang=cpp
 *
 * [2364] Count Number of Bad Pairs
 */

// @lc code=start
/*
    Hash map+Math+counting
    Time complexity: O(n)
    Space complexity: O(n)
*/
typedef long long ll;
class Solution {
    public:
        ll countBadPairs(std::vector<int>& nums){
            ll n=nums.size();
            
            //  Create a hash map to store the frequency of good pairs
            // good pair is nums[j]-j==nums[i]-i => nums[j]-j==nums[i]-i
            std::unordered_map<int,ll> freq;

            ll ans=0;
            // For each nums[i]
            for(int i=0;i<n;++i){
                // Determine the number of good pairs that it can make it
                ll good_pairs=freq[nums[i]-i];

                // Each element at position i, can make a total of i pairs
                // so, to find the number of bad pairs we subtract the number of
                // goog pairs from the total number of pairs that nums[i] can make
                ans+=i-good_pairs;

                // nums[i]-i is a good pair by iteself
                // number of good pairs including nums[i] is total pairs-bad pairs
                // => i-(i-good pairs) + 1 = good pairs+1
                // i: total number of pairs made by nums[i]
                // i-good pairs; #bad pairs before nums[i]
                // +1: nums[i]-i is a good pair
                freq[nums[i]-i]=good_pairs+1;
            }
            
            return ans;
        }
};
// @lc code=end

