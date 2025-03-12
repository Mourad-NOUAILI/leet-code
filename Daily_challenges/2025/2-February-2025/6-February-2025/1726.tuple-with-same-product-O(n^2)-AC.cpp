/*
 * @lc app=leetcode id=1726 lang=cpp
 *
 * [1726] Tuple with Same Product
 */

// @lc code=start

/*
    Hashing + Combinatorics - AC
    (AC if time constraint 1s)
    Time complexity: O(n^2+n^2)
    Space complexity: O(n^2)
*/

typedef std::vector<int> vi;
typedef long long ll;
class Solution{
    public:
        int tupleSameProduct(vi& nums) {
            int n=nums.size();

            // Count the number of pairs (a*b) given the same product
            std::unordered_map<ll,int> freq;
            for(int i=0;i<n-1;++i){
                for(int j=i+1;j<n;++j){
                        freq[nums[i]*nums[j]]++;
                }
            }

            // For each product
            int ans=0;
            for(auto& [prod,f]: freq){
                // Count the number of distinct pairs from these f pairs
                int count_distinct_pairs_with_same_product=f*(f-1)/2;

                // Cumulate the answer
                ans+=count_distinct_pairs_with_same_product*8;
            }

            return ans;
        }
};
// @lc code=end

