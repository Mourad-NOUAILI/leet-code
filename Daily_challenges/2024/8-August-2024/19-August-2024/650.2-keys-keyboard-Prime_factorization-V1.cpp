/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

/*
    Prime factorization
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
public:
    int minSteps(int n) {   
        int i=2;
        int ans=0;
        while(n!=1){
            while(n%i==0){
                n/=i;
                ans+=i;
            }
            i++;
        }

        return ans;
    }
};
// @lc code=end

