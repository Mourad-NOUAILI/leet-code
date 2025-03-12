/*
 * @lc app=leetcode id=2364 lang=cpp
 *
 * [2364] Count Number of Bad Pairs
 */

// @lc code=start
/*
    Hash map+Math+counting
    Time complexity: O(2n)
    Space complexity: O(n)
*/
typedef long long ll;
class Solution {
    public:
        ll countBadPairs(std::vector<int>& nums){
            ll n=nums.size();
            
            //  Create a hash map to store the frequency of good pairs
            // good pair is nums[j]-j==nums[i]-i => nums[j]-j==nums[i]-i
            // Initiate the hash map with -1, because the differene of nums[j]-j=nums[i]-i
            // such that i==j is not counted. 
            struct defaut_value{int val=-1;};
            std::unordered_map<int,defaut_value> freq;
            for(int i=0;i<n;++i) freq[nums[i]-i].val++;

            // Determine the number of goog pairs
            ll good_pairs=0;
            // For each nums[j]
            for(int j=0;j<n;++j){
                // If the frequency of nums[j]-j>0, add it to the answer and reduce it by 1
                // because that difference nums[j]-j will not be counted any more, if we encounter
                // the same difference one more time
                good_pairs+=freq[nums[j]-j].val>0?freq[nums[j]-j].val--:0;
            }

            // Count the total number of pairs
            ll total_pairs=n*(n-1)/2;
            
            // Number of bad pairs = total number of pairs-number of good pairs
            return total_pairs-good_pairs;
        }
};
// @lc code=end

