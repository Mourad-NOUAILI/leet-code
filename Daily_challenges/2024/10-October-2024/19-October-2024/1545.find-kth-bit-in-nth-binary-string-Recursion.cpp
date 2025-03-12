/*
 * @lc app=leetcode id=1545 lang=cpp
 *
 * [1545] Find Kth Bit in Nth Binary String
 */

// @lc code=start

/*
    Recursion
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution{
    public:
        char findKthBit(int n, int k) {

            auto solve=[&](int n,int k,auto& self)->char{
                if(n==1) return '0';
                int nb_bits=(1<<n)-1;
                int mid=nb_bits/2+1;
                if(k==mid) return '1';
                if(k<mid) return self(n-1,k,self);
                return self(n-1,nb_bits-k+1,self)=='0'?'1':'0';
            };
            
            return solve(n,k,solve);
        }
};
// @lc code=end

