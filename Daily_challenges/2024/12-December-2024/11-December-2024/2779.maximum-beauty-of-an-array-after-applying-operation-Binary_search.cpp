/*
 * @lc app=leetcode id=2779 lang=cpp
 *
 * [2779] Maximum Beauty of an Array After Applying Operation
 */

// @lc code=start
/*
    Binary search
    Time complexity: O(nlogn)
    Space complexity: O(logn)
*/
class Solution {
public:
    int maximumBeauty(std::vector<int>& nums, int k) {
        int n=nums.size();
        std::sort(nums.begin(),nums.end());

        auto my_upper_bound=[&](int x)->int{
            int lo=0,hi=n-1,index=0;
            while(lo<=hi){
                int mid=(lo+hi)>>1;
                if(nums[mid]<=x){
                    index=mid;
                    lo=mid+1;
                }
                else hi=mid-1;
            }
            return index;
        };
        
        
        int ans=0;
        for(int i=0;i<n;++i){
            int j=my_upper_bound(nums[i]+2*k);
            ans=std::max(ans,j-i+1);
        }
        
        return ans;
    }
};
// @lc code=end

