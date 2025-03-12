/*
    Single pass, One pointer
    Time complexity: O(n)
    Space complexity: O(1)
*/
typedef std::vector<int> vi;
class Solution {
    public:
        int longestMonotonicSubarray(vi& nums){
            int n=nums.size();
            int ans=1,len_li=1,len_ld=1;

            // Iterate through array comparing adjacent elements
            for(int i=0;i<n-1;++i){
                // If next element is larger,
                if(nums[i]<nums[i+1]){
                    len_li++; // Extend increasing sequence
                    len_ld=1; // Reset decreasing sequence
                }
                // If next element is smaller,
                else if(nums[i]>nums[i+1]){
                    len_ld++; // Extend decreasing sequence
                    len_li=1; // Reset increasing sequence
                }
                // If their equal
                else{
                    // Reset increasing and decreasing sequence
                    len_li=len_ld=1;
                }
                
                ans=std::max({ans,len_li,len_ld});
            }
            return ans;
        }
};