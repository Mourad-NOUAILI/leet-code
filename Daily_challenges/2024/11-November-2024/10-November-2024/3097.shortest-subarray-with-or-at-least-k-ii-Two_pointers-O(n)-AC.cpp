/*
 * @lc app=leetcode id=3097 lang=cpp
 *
 * [3097] Shortest Subarray With OR at Least K II
 */

// @lc code=start

/*
    Sliding window - AC
    Time complexity: O(n*32)=O(n)
    Space complexity: O(32)=O(1)
*/
typedef std::vector<int> vi;

class Solution {
    public:
        int minimumSubarrayLength(vi& nums, int k) {
            int n=nums.size();

            // Store the contibution of each bit of each value
            // in the prefix OR result
            vi prefix_bit(32,0);

            // If the  bit at position i of the value `val` is set
            // If `val` contibutes in the prefix OR result: we increment the conribution of that bit by 1
            // If `val` does not contibute in the prefix OR result: we subtract 1 from conribution of that bit
            auto contribute=[&](int val,bool is_contibuted)->void{
                for(int i=0;i<32;++i){
                    if(val&(1<<i)) prefix_bit[i]+= (is_contibuted?1:-1);
                }
            };

            // Convert a 32-bits array to an integer.
            auto bin2int=[&]()->int{
                int res=0;
                for(int i=0;i<32;++i) res+= (prefix_bit[i]!=0?(1<<i):0);
                return res;
            };
          
            int ans=INT_MAX;
            int i=0,j=0; // Window of size 1
            while(j<n){
                contribute(nums[j],true); // Add the contibution of nums[j] into the ORing operation
                // Keep shrinking the window, while i<=j && OR result >= k
                while(i<=j && bin2int()>=k){
                    ans=std::min(ans,j-i+1); // Minimize the answer
                    contribute(nums[i],false); // Remove the contibution of nums[i] into the ORing operation
                    i++; // Shrink the window
                }
                j++; // Extend the window
            }

            return ans!=INT_MAX?ans:-1;
        }
};
// @lc code=end

