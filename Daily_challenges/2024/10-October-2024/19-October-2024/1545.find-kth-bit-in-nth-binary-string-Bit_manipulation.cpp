/*
 * @lc app=leetcode id=1545 lang=cpp
 *
 * [1545] Find Kth Bit in Nth Binary String
 */

// @lc code=start

/*
    Bit manipulation
    Time complexity: O(1)
    Space complexity: O(1)
*/
class Solution {
    public:
        char findKthBit(int n, int k) {
                // Find the group where k belong
                int rightmost_set_bit_pos=k&-k;

                // If the group is set => k-th bit is inverted
                // Otherwise => k-th bit remains same as original
                bool is_inverted=((k/rightmost_set_bit_pos)>>1&1)==1;

                // Determine if the original bit (before any inversion) would be 1
                // This is true if k is even (i.e., its least significant bit is 0)
                bool is_original_bit_one=(k&1)==0;

                if (is_inverted){
                    // If we're in the inverted part, we need to flip the bit
                    return is_original_bit_one?'0':'1';
                } 
                
                // If we're not in the inverted part, return the original bit
                return is_original_bit_one?'1':'0';
                
        }
};

// @lc code=end

