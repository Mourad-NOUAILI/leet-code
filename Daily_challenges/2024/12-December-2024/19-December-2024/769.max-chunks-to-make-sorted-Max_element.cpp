/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
/*
    Consecutive numbers property(max element)
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        int maxChunksToSorted(vector<int>& arr){
            int n=arr.size();
            int mx=0,ans=0;
            for(int i=0;i<n;++i){
                mx=std::max(mx,arr[i]);
                ans+=int(i==mx);
            }
            return ans;
        }
};
// @lc code=end

