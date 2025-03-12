/*
    Bitwise operations
    Time complexity: O(n)
    Space complexity: O(1)
*/

class Solution {
public:
    bool isArraySpecial(std::vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<n;++i){
            if(!((nums[i-1]&1)^(nums[i]&1))) return false;
        }
        return true;
    }
};