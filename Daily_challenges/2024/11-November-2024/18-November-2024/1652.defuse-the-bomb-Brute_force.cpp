/*
 * @lc app=leetcode id=1652 lang=cpp
 *
 * [1652] Defuse the Bomb
 */

// @lc code=start
/*
    Brute force
    Time complexity: O(nk)=O(n^2),if k=n
    Space complexity: O(1)
*/
typedef std::vector<int> vi;
class Solution{
    public:
        vi decrypt(vi& code, int k){
            int n=code.size();

            vi ans(n,0);

            if(k==0) return ans;

            // k>0 => dir=1 (Go right)
            // k<0 => dir=-1 (Go left)
            int dir=(k>0)?1:-1;

            // For each index i (0<=i<=n-1)
            for(int i=0;i<n;++i){
                // compute the sum for the next/previous k elements
                int s=0;
                for(int j=1;j<=std::abs(k);++j){
                    // Because the array is circular
                    // we need to get the correct index of the
                    // element to add to the sum
                    // if k>0 (dir=1), shift the index i to the right by j positions 
                    // if k<0 (dir=-1), shift the index i to the left by j positions  
                    int idx=((((dir*j)+i)%n)+n)%n;
                    s+=code[idx];
                }
                ans[i]=s;
            }
            
            return ans;
        }
};
// @lc code=end

