/*
    Linear search
    Time complexity: O(q.n)
    Space compelxity: O(n)
*/

class Solution {
public:
    std::vector<bool> isArraySpecial(std::vector<int>& nums,std::vector<vector<int>>& queries){
        // Linear search to check if a bad index exists in
        // the range [l,r]
        auto is_bad_index_exist=[&](int l, int r)->bool{
            for(int i=l+1;i<=r;++i){
               if(!((nums[i-1]%2==0)^(nums[i]%2==0))) return true;
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