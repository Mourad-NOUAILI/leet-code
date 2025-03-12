/*
 * @lc app=leetcode id=1545 lang=cpp
 *
 * [1545] Find Kth Bit in Nth Binary String
 */

// @lc code=start

/*
    Divide and conquer
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        char findKthBit(int n, int k){
            int nb_bits=(1<<n)-1;
            int nb_inversions=0;
            while(k>1){
                int mid=nb_bits/2;
                if(k==mid+1) return nb_inversions%2==0?'1':'0';
                if(k>mid){
                    k=nb_bits-k+1;
                    nb_inversions++;
                }
                nb_bits/=2;
            }
            return nb_inversions%2==0?'0':'1';
        }
};
// @lc code=end

