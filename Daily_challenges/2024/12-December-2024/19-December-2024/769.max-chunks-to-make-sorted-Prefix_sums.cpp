/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
/*
    Consecutive numbers property(Prefix sums)
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        int maxChunksToSorted(std::vector<int>& arr){
            int n=arr.size();
            int pref_sum=0,sorted_pref_sum=0,ans=0;
            for(int i=0;i<n;++i){
                pref_sum+=arr[i];
                sorted_pref_sum+=i;
                ans+=int(pref_sum==sorted_pref_sum);
            }
            return ans;
        }
};
// @lc code=end

