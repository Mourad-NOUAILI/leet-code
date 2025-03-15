/*
    Binary search on difference arrays
    Time complexity: O(m+log m . (m+n))
    Space complexity: O(n) 
*/
class Solution {
public:
    int minZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries){
        int n=nums.size();
        int m=queries.size();

        // Check if it is possible to obtain a zero array after processing k queries
        auto is_possible=[&](int k)->bool{
            // Create difference array
            std::vector<int> diff(n+1,0);

            for(int i=0;i<k;++i){
                int l=queries[i][0];
                int r=queries[i][1];
                int val=queries[i][2];

                // Update difference array
                diff[l]+=val;
                diff[r+1]-=val;
            }

            // Afer processing all queries, check il all elements in the given array
            // are tansformed to zero or not
            int pre=0;
            for(int i=0;i<n;++i){
                // pre=sum of all values in range[0,i] to decrement from nums[i]
                pre+=diff[i];

                // If at least one element is not equal to zero, return false
                if(nums[i]-pre>0) return false;
            }

            // If all elements are equal to zero
            return true;
        };
        
        // If is not possible to transform the array to a zero array after performing all the queries
        if(!is_possible(m)) return -1;

        // If it is possible to transform the array to a zero array after performing all the queries
        // determine the minimum number of queries to achieve that:

        // Do a binary search on the queries
        // return the first met where is possible to transform the array to a zero array
        int lo=0,hi=m-1;
        while(lo<=hi){
            int k=(lo+hi)>>1;
            if(is_possible(k)) hi=k-1;
            else lo=k+1;
        }
        return lo;
    }
};