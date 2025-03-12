/*
 * @lc app=leetcode id=1760 lang=cpp
 *
 * [1760] Minimum Limit of Balls in a Bag
 */

// @lc code=start
/*
    Binary search
    Time compelxity: O(n+n log mx_balls)=O(n log mx_balls)
    Space complexity: O(1)
*/
class Solution {
    public:
        int minimumSize(std::vector<int>& nums, int maxOperations){
            
            /*
                Compute the total number of operations.
                For each bag, that contains a certain number of balls,
                count the number of operations to divide a `balls_in_bag`.
                If the total number of operations `count_operations` exceed the given
                maximum number of operation `maxOperations`, it is not possible to divide some bags
                into new bags of `balls_in_bag`
            */
            auto is_possible=[&](int balls_in_bag)->bool{
                int count_operations=0;
                for(auto& balls: nums){
                    count_operations+=balls/balls_in_bag+int(balls%balls_in_bag!=0)-1;
                    if(count_operations>maxOperations) return false;
                }
                return true;
            };

            // The maximum number that a new bag could contains is 
            // the maximum number of given balls. 
            int mx_balls=*std::max_element(nums.begin(),nums.end());

            // Perform a Binary search to get the first number of balls
            // that we can put in the new bags with in the maximum number
            // of operations.
            // It is abvious, that we should start trying by the smallest
            // number until we reach the biggest.
            int lo=1,hi=mx_balls;
            int ans=mx_balls;
            while(lo<=hi){
                int balls_in_bag=(lo+hi)>>1;
                if(is_possible(balls_in_bag)) {
                    ans=balls_in_bag;
                    hi=balls_in_bag-1;
                }
                else lo=balls_in_bag+1;
            }
            return ans;
        }
};
// @lc code=end

