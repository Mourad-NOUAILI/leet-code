/*
 * @lc app=leetcode id=2601 lang=cpp
 *
 * [2601] Prime Subtraction Operation
 */

// @lc code=start

/*
    Brute force
    Time complexity: O(n limit * sqrt(limit))
    Space complexity: O(1)
*/
class Solution {
    public:
    
        bool primeSubOperation(std::vector<int>& nums){
            
            auto is_prime=[&](int p)-> bool{
                int sr=sqrt(p);
                for(int i=2;i<=sr;++i) {
                    if(p%i==0) return false;
                }
                return true;
            };

            int n=nums.size();
            for(int i=0;i<n;++i){
                // Largest prime should be less than nums[i]-nums[i-1]
                int limit=i==0?nums[0]:nums[i]-nums[i-1];

                // if limit<=0, means nums[i]-nums[i-1]<=0
                // ==> nums[i]<=nums[i-1] 
                // ==> we cannot make a strictly incresing array
                if(limit<=0) return false;

                // Find largest prime, such that 2<= Largest prime < limit
                // Largest prime=0, otherwise
                int j=limit-1;
                while(j>=2 && !is_prime(j)) j--;
                int largest_prime=j>=2?j:0;

                // Subtract the largest prime number that
                // we found from nums[i]
                nums[i]-=largest_prime;
            }
            return true;
        }
};
// @lc code=end

