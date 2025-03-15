/*
    Line sweep + Difference array: apply only the necessary queries at the right moment.
    Time complexity: O(n+m+n)=O(n+m)
    Space complexity: O(n) 
*/
class Solution {
    public:
        bool isZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
            int n=nums.size();
            int m=queries.size();

            // Create the difference of size (n+1)
            std::vector<int> diff(n+1,0);
            
            int pre=0; // Prefix sum of difference array
            int query=0; // Number of the current query

            // For each element in the given array
            for(int i=0;i<n;++i){
                // While the current element in not zero
                while(nums[i]-(pre+diff[i])>0){
                    query++; // Perform the current query
                    
                    // If we have performed all queries
                    if(query>m) return false;

                    // Get range
                    int l=queries[query-1][0];
                    int r=queries[query-1][1];

                    // If the index of the current element is the range
                    if(i<=r){
                        // Update the start of the range
                        diff[std::max(i,l)]++; 
                        
                        diff[r+1]--;
                    }
                }

                // Update the prefox sum at current index
                pre+=diff[i];
            }

            // The original array transformed to a zero array
            return true;
        }
};


/*
    [8,4]
    [[0,1],[1,1],[1,1],[1,1],[0,0],[1,1],[0,1],[1,1],[1,1]]

*/