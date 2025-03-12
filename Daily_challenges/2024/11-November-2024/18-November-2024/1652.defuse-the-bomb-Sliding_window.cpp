/*
 * @lc app=leetcode id=1652 lang=cpp
 *
 * [1652] Defuse the Bomb
 */

// @lc code=start
/*
    Sliding window
    Time complexity: O(k+n)=O(2n), if k=n => O(n)
    Space complexity: O(1)
*/
typedef std::vector<int> vi;
class Solution {
    public:
        int mod(int a,int b){
            return ((a%b)+b)%b;
        }
        
        vi decrypt(vi& code, int k){
            int n=code.size();

            vi ans(n,0);

            if(k==0) return ans;

            // k>0 => dir=1 (Go right)
            // k<0 => dir=-1 (Go left)
            int dir=(k>0)?1:-1;

            // Create a window of size k
            // if k>0, create window from left to right
            // if k<0, create window from right to left
            int win=0;
            for(int j=1;j<=std::abs(k);++j){
                int idx=mod(dir*j,n);
                win+=code[idx];
            }

            // Window start and end indices
            int start=mod(dir,n);
            int end=mod(k,n);
            if(start>end) std::swap(start,end);

            int i=0;
            while(i<n){
                ans[i]=win;

                // Slide the window
                win-=code[start];
                win+=code[mod(end+1,n)];
                start=mod(start+1,n);
                end=mod(end+1,n);
                
                i++;
            }

            return ans;
        }
};
// @lc code=end

