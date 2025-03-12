/*
 * @lc app=leetcode id=1524 lang=cpp
 *
 * [1524] Number of Sub-arrays With Odd Sum
 */

// @lc code=start
/*
    Prefix sum+counting
    Time compelxity: O(n)
    Space compelxity: O(1)
*/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD=1e9+7; 
        int n=arr.size();
        int prefix_sum=0;
        int even_freq=1; // 0 of the prefix sum is even 
        int odd_freq=0;
        int ans=0;
        for(int i=0;i<n;++i){
            prefix_sum+=arr[i]; // Build prefix sum from 0 to i
            even_freq+=prefix_sum%2==0; // Count frequency of even sums from 0 to i
            odd_freq+=prefix_sum%2==1; // Count frequency of odd sums from 0 to i

            // If sum from 0 to i is odd, add to the answer the frequency of even sums
            // Otherwise, add to the answer the frequency of odd sums
            ans=(prefix_sum%2?(ans+even_freq%MOD):(ans+odd_freq%MOD))%MOD;
        }
        
        return ans;
    }
};
// @lc code=end

