/*
    Brute force
    Time complexity: O(2n^2)
    Space complexity: O(1)
*/

typedef std::vector<int> vi;
class Solution {
    public:
        int length_of_LIS_or_LDS(vi& nums,int flag){
            int n=nums.size();
    
            int ans=1;
            // For each element at index i
            for(int i=0;i<n;++i){
                // Determine the LI/LD subarray starting from i
                int len=1; // The element at position i has a length equal to 1
                int j=i+1; // Start  from next position
                
                // While the previous element is less/greater than the next one,
                // increment the size of the LI/LD subarray 
                while(j<n && flag*nums[j-1]<flag*nums[j]){
                    len++;
                    j++;
                }

                // Maximize the answer
                ans=std::max(ans,len);
            }
            return ans;
        }

        int longestMonotonicSubarray(vi& nums){
            // 1st call with a flag equal to 1 to compute LI
            int lis=length_of_LIS_or_LDS(nums,1);

            // 2nd call with a flag equal to -1 to compute LD
            int lds=length_of_LIS_or_LDS(nums,-1);

            return std::max(lis,lds);
        }
};