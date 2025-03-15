/*
 * @lc app=leetcode id=1780 lang=cpp
 *
 * [1780] Check if Number is a Sum of Powers of Three
 */

// @lc code=start
/*
    Ternary representation
    Time complexity: O(log_3(n)))
    Space compelxity: O(1)
*/
class Solution {
public:
    /*
        In base 3, each digit in a number represents the number of copies of that power of 3.
        That is, the first digit tells you how many ones you have;
        the second tells you how many 3s you have;
        the third tells you how many 3x3 you have; 
        the fourth tells you how many 3x3x3 you have;
        and so on.
    */
    bool checkPowersOfThree(int n){
        while(n>0){
            // If remainder=k, means that we have k powers of three
            // if remainder>=2, means that we have a repeated power of 3
            if(n%3==2) return false;

            n/=3;
        }
        return true;
    }
};
// @lc code=end

