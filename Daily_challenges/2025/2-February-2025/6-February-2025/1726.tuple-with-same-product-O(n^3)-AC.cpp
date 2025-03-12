/*
 * @lc app=leetcode id=1726 lang=cpp
 *
 * [1726] Tuple with Same Product
 */

// @lc code=start

/*
    Brure force + Hashing - AC
    (TLE if time constraint 1s)
    Time complexity: O(n^3)
    Space complexity: O(logn+n)
*/

typedef std::vector<int> vi;
class Solution{
    public:
        int tupleSameProduct(vi& nums) {
            int n=nums.size();

            std::sort(nums.begin(),nums.end());

            // Fix a, c and d, then look for b using hashing
            // Same concept of (1. Two Sum)

            // Store all element for later lookup
            std::unordered_map<int,int> freq;
            for(auto& e: nums) freq[e]++;
            
            int ans=0;
            for(int i=0;i<n-2;++i){
                for(int j=i+1;j<n-1;++j){
                    for(int k=j+1;k<n;++k){
                        int a=nums[i];
                        int c=nums[k];
                        int d=nums[j];

                        // If we can not make a product with actual values (a,c,d)
                        if(c*d%a) continue;

                        // Otherwise, lookup for b in the hash map
                        if(freq[c*d/a]) ans+=8;
                    }
                }
            }
            return ans;
        }
};
// @lc code=end

