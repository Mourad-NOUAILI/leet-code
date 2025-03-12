/*
    prefix sum
    Time complexity: O(n+q)
    Space compelxity: O(n)
*/

class Solution {
public:
    std::vector<bool> isArraySpecial(std::vector<int>& nums,std::vector<vector<int>>& queries){
        int n=nums.size();

        // Preprocess a prefix sum
        // add 1, if we have a valid pair (having different parity)
        // 0, otherwise
        std::vector<int> prefix_sum(n);
        prefix_sum[0]=0;
        for(int i=1;i<n;++i) prefix_sum[i]=prefix_sum[i-1]+((nums[i-1]%2==0)^(nums[i]%2==0));
        
        std::vector<bool> ans;
        for(auto& query: queries){
            int l=query[0];
            int r=query[1];
            
            // if all pairs are valide in range [l,r]:
            //******The sum from l to r, should be equal to the number of 1's in range [l,r].
            ans.push_back(prefix_sum[r]-prefix_sum[l]==r-l);
        }
        return ans;
    }
};