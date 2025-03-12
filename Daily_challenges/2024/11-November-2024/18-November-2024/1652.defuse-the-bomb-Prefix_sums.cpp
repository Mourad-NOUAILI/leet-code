/*
 * @lc app=leetcode id=1652 lang=cpp
 *
 * [1652] Defuse the Bomb
 */

// @lc code=start
/*
    Prefix sums
    Time complexity: O(2n+2n+2n+2n+n)=O(9n)=O(n)
    Space complexity: O(2n+2n)=O(4n)=O(n)
*/
typedef std::vector<int> vi;
class Solution {
    public:
        vi decrypt(vi& code, int k){
            int n=code.size();

            vi ans(n,0);

            if(k==0) return ans;
            
            // Maintain circular property
            int m=2*n;
            vi arr(m);
            for(int i=0;i<m;++i) arr[i]=code[i%n];
            
            // Preprocess prefix sums
            vi prefix_sum(m+1);
            prefix_sum[0]=0;
            for(int i=1;i<=m;++i) prefix_sum[i]=prefix_sum[i-1]+arr[i-1];

            // Get answers
            for(int i=0;i<n;++i){
                ans[i]=k>0?prefix_sum[i+k+1]-prefix_sum[i+1]:prefix_sum[n+i]-prefix_sum[n+i-abs(k)];
            }

            return ans;
        }
};
// @lc code=end

