/*
    Difference array
    Time complexity: O(n+m+n)=O(n+m)
    Space complexity: O(n) 
*/
class Solution {
    public:
        bool isZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
            int n=nums.size();
            //int m=queries.size();
            
            // Create the difference of size (n+1)
            std::vector<int> diff(n+1,0);

            // For each query
            for(auto& query: queries){
                int l=query[0];
                int r=query[1];
                int val=query[2];

                // Update the difference array
                diff[l]++;
                diff[r+1]--;
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
        }
};


/*
    [3,4,0,2]
    [[0,3],[0,1],[1,3],[0,3],[0,0]]

*/