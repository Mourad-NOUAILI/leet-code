/*
    Naive: Naively process the queries on the array
    Time complexity: O(n.m)
    Space complexity: O(1) 
*/
class Solution {
    public:
        bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            //int n=nums.size();
            //int m=queries.size();

            // For each query
            for(auto& query: queries){
                int l=query[0];
                int r=query[1];
                int val=query[2];

                // Run over the array in range [l,r]
                for(int i=l;i<=r;++i){
                    // if the current element is already equal to zero, pass to next
                    if(nums[i]==0) continue;

                    // Otherwise, decrement 1 from the current element
                    nums[i]-=1;
                }
            }

            // Afer processing all queries, check il all elements in the given aaray
            // are tansformed to zero or not
            for(auto& e: nums){
                // If at least one element is not eqaul to zero, return false
                if(e!=0) return false;
            }

            // If all elements are equal to zero
            return true;
        }
};

/*
    [3,4,0,2]
    [[0,3],[0,1],[1,3],[0,3],[0,0]]

*/