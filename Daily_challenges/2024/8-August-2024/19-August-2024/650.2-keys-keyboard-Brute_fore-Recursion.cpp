/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

/*
    Brute force: Recursion
    Time complexity: O(2^n)
    Space complexity: O(n)
*/

class Solution {
public:
    int minSteps(int n) {   
        
        auto solve=[&](int i,int j,auto& self)->int{
            if(i==n) return 0;
            if(i>n) return INT_MAX/2;
            return std::min(2+self(2*i,i,self) , 1+self(i+j,j,self));
        };

        if(n==1) return 0;
        return 1+solve(1,1,solve);
    }
};
// @lc code=end

