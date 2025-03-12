/*
    Binary search
    Time complexity: O(n+qlogn)
    Space compelxity: O(n)
*/

class Solution {
    public:
        std::vector<bool> isArraySpecial(std::vector<int>& nums,std::vector<vector<int>>& queries){
            int n=nums.size();
            std::vector<int> bad_indices;

            // Determine indices that violate the different parity rule
            // if nums[i-1] and nums[i] have same parity, we store i as a bad index 
            for(int i=1;i<n;++i){
                if(!((nums[i-1]%2==0)^(nums[i]%2==0))) bad_indices.push_back(i);
            }

            // Binary search to check if a bad index exists in
            // the range [l,r]
            auto is_bad_index_exist=[&](int l, int r)->bool{
                int lo=0,hi=bad_indices.size()-1;
                while(lo<=hi){
                    int mid=(lo+hi)>>1;
                    if(bad_indices[mid]>l && bad_indices[mid]<=r) return true;
                    else if(bad_indices[mid]>r) hi=mid-1;
                    else if(bad_indices[mid]<=l) lo=mid+1;
                }
                return false;
            };

            std::vector<bool> ans;
            // For each query
            for(auto& query: queries){
                int l=query[0];
                int r=query[1];
                // If a bad index exist in range [l,r], append `false` to the answer,
                // Otherwise, append `true`
                ans.push_back(!is_bad_index_exist(l,r));
            }
            return ans;
        }
};