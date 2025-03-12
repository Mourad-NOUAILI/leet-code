/*
 * @lc app=leetcode id=2342 lang=cpp
 *
 * [2342] Max Sum of a Pair With Equal Sum of Digits
 */

// @lc code=start

/*
    Array: Track the max number given a sum of digit
    Time complexity: O(nlogm)=O(9n)=O(n)
    Space complexity: O(82)=O(1)
    m=999999999
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

            vi sum_numbers(82,-1);

            int ans=-1;
            for(int i=0;i<n;++i){
                int s=sum_digits(nums[i]);
                // If the sum of digits is already computed
                // add the number store in tha map to the current one and maximize the answer
                if(sum_numbers[s]!=-1) ans=std::max(ans,sum_numbers[s]+nums[i]);

                // Store only the max number given that sum
                sum_numbers[s]=std::max(sum_numbers[s],nums[i]);
            }

            return ans;  
        }
};
// @lc code=end

