/*
 * @lc app=leetcode id=1780 lang=cpp
 *
 * [1780] Check if Number is a Sum of Powers of Three
 */

// @lc code=start
/*
    Math
    Time complexity: O(log_3(n).log(log_3(n))
    Space compelxity: O(1)
*/
class Solution {
public:
    int power(int a,int b) {
        int res=1;
        while (b>0) {
            if (b&1) res*=a;
            a*=a;
            b/=2;
        }
        return res;
    }

    bool checkPowersOfThree(int n){
        // Determine de maximum power of 3 of n
        int x=log(n)/log(3);
        int p=0;
        while(n>0){
            // 3^x
            p=power(3,x);
            // If n still greater than 3^x, reduce 3^n from n 
            if(n>=p) n-=p;
            // If n still greater than 3^x, means than x will be used twice in current sum
            // so return false
            if(n>=p) return false;

            // Pass to the next power
            x--;
        }

        // means n==0 (return)
        return true;
    }
};
// @lc code=end

