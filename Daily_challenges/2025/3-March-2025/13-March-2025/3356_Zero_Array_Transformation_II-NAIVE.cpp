/*
    Brute force: Naively process the queries
    Time complexity: O(n+2m.n)
    Space complexity: O(1) 
*/
class Solution {
public:
    int minZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries){
        int n=nums.size();
        int m=queries.size();

        // Check if an array is a zero array or not
        auto is_zero_array=[&]()->bool{
            for(auto& e: nums){
                if(e!=0) return false;
            }
            return true;
        };

        if(is_zero_array()) return 0;

        int k=0; // Minimum number of queries to process to transform all elements of the array  to zero
        // For each query
        for(auto& query: queries){
            int l=query[0];
            int r=query[1];
            int val=query[2];

            // Perform the current query on the given array
            for(int i=l;i<=r;++i) nums[i]=std::max(nums[i]-val,0);

            // Query is performed, add it to the answer
            k++;
            
            if(is_zero_array()) return k;
            
           
        }

        // If all queries are performed, but the array is not transformed to zeros
        return -1;
    }
};