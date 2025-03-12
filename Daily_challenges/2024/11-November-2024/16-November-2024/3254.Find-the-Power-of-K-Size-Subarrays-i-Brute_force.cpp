/*
    Brute Force
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
typedef std::vector<int> vi;
class Solution {
    public:
        vi resultsArray(vi& nums, int k){
            int n=nums.size();
            
            // Check if all integer are consecutive in a given range
            // Time complexity: O(n)
            // Space complexity: O(1)
            auto is_consecutive=[&](int left,int right)->bool{
                for(int i=left;i<right;++i){
                    if(nums[i+1]-nums[i]!=1) return false;
                }
                return true;
            };

            vi ans; // Store final answer
            // For each starting index i, we extract the subarray of elements from nums[i] to nums[i+k−1].
            // We then need to verify two conditions: 
            // 1- the elements must be sorted in ascending order,
            // 2- and they must be consecutive integers.
            for(int i=0;i<=n-k;++i){
                int j=i+k-1;
                if(is_consecutive(i,j)) ans.push_back(nums[j]);
                else ans.push_back(-1);
            }
            return ans;         
        }
    };