/*
 * @lc app=leetcode id=858 lang=cpp
 *
 * [858] Mirror Reflection
 */

// @lc code=start
class Solution {
    public:
        int gcd(int a, int b){
            return a % b == 0 ? b : gcd(b,a % b);
        }

        int lcm (int a, int b){
            return (a*b)/gcd(a,b);
        }

        int mirrorReflection(int p, int q) {
            int z = lcm(p,q);
            
            if (z / q % 2 == 0) return 2;

            return z / p % 2;
        }
};
// @lc code=end

