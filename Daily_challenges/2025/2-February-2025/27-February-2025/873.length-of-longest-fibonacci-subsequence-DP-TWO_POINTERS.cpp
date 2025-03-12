/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */

// @lc code=start
/*
    DP+Two pointers
    Time complexity: O(n^2)
    Space complexity:O(n^2)
*/
class Solution {
public:
    int lenLongestFibSubseq(std::vector<int>& arr) {
        int n=arr.size();
        if(n<3) return 0;
        std::vector<std::vector<int>> dp(n,std::vector<int>(n,2));
        int ans=0;

        // For each sum at arr[i]
        for(int i=2;i<n;++i){
            // Use two pointers technique to find the elemnets arr[r]+arr[l]=arr[i]
            // in range[0,i-1]
            int l=0,r=i-1;
            while(l<r){
                int s=arr[l]+arr[r];
                if(s==arr[i]){
                    // Add one the the precomputed result 
                    dp[i][r]=dp[r][l]+1;
                    ans=std::max(ans,dp[i][r]);
                    l++;
                    r--;
                }
                else if(s>arr[i]) r--;
                else l++;
            }

        }
        return ans>2?ans:0;
    }
};
// @lc code=end

