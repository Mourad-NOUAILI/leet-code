/*
 * @lc app=leetcode id=2342 lang=cpp
 *
 * [2342] Max Sum of a Pair With Equal Sum of Digits
 */

// @lc code=start

/*
    Hash map: Track the max number given a sum of digit
    Time complexity: O(nlogm)
    Space complexity: O(logm)
    m: max number in the given array
*/
typedef std::vector<int> vi;
typedef std::pair<int,int> ii;
class Solution {
    public:
        int sum_digits(int x){
            int s=0;
            while(x!=0){
                s+=x%10;
                x/=10;
            }
            return s;
        }

        int maximumSum(vi& nums){
            int n=nums.size();

            std::unordered_map<int,int> sum_numbers;

            int ans=-1;
            for(int i=0;i<n;++i){
                int s=sum_digits(nums[i]);
                // If the sum of digits is already computed
                // add the number store in tha map to the current one and maximize the answer
                if(sum_numbers.find(s)!=sum_numbers.end()) ans=std::max(ans,sum_numbers[s]+nums[i]);

                // Store only the max number given that sum
                sum_numbers[s]=std::max(sum_numbers[s],nums[i]);
            }

            return ans;  
        }
};
// @lc code=end

