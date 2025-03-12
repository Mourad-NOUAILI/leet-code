/*
    Single pass: Sliding window, Four pointers
    Time complexity: O(n)
    Space complexity: O(1)
*/
typedef std::vector<int> vi;
class Solution {
    public:
        int longestMonotonicSubarray(vi& nums){
            int n=nums.size();

            int ans=1,len_li=1,len_ld=1;

            // For each element at index:
            int i=0; // start of LI
            int k=0; // start of LD
       
            while(i<n){
                // Determine the LI/LD subarray starting from i/k 
                int j=i+1,l=k+1; // Start  from next position
                // While the previous element is less than the next one,
                // increment the size of the LI subarray 
                while(j<n && nums[j-1]<nums[j]) j++;

                // While the previous element is greater than the next one,
                // increment the size of the LD subarray 
                while(l<n && nums[l-1]>nums[l]) l++;
                
                // Maximize the answer
                len_li=std::max(ans,j-i); // Size of LI
                len_ld=std::max(ans,l-k); // Size of LD
                ans=std::max({ans,len_li,len_ld});

                // The new subarray will start at the end of the previous one.
                i=j;
                k=l;
            }
            return ans;
        
        }
};