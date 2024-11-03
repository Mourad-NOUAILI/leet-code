/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

/*
    Prime factorization
    Time complexity: O(sqrt(n))
    Space complexity: O(1)
*/
class Solution {
public:
    int minSteps(int n) {
       int ans=0;
       int i=2;
       for(int i=2;i*i<=n;++i){
            while(n%i==0){
                n/=i;
                ans+=i;
            }
       }
       
       if(n>1) ans+=n;
       
       return ans;
    }
};
// @lc code=end

