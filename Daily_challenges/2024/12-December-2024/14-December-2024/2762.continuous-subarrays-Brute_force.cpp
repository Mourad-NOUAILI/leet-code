/*
 * @lc app=leetcode id=2762 lang=cpp
 *
 * [2762] Continuous Subarrays
 */

// @lc code=start

/*
    Brute force (TLE)
    Time complexity: O(n^3)
    Space complexity: O(1)
*/

class Solution {
    public:
        long long continuousSubarrays(std::vector<int>& nums){
            int n=nums.size();
            long long ans=0;
            for(int l=0;l<n;++l){
                for(int r=l;r<n;++r){
                    int mx=*std::max_element(nums.begin()+l,nums.begin()+r+1);
                    int mi=*std::min_element(nums.begin()+l,nums.begin()+r+1);
                    if(mx-mi<=2) ans++;
                }
            }
            return ans;
        }
};

// @lc code=end

