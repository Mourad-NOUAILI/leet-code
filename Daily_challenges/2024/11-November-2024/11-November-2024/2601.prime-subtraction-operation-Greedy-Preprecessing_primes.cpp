/*
 * @lc app=leetcode id=2601 lang=cpp
 *
 * [2601] Prime Subtraction Operation
 */

// @lc code=start

/*
    Brute force+Preprecessing primes numbers
    Time complexity: O(mx * sqrt(limit)+n)
    Space complexity: O(mx)
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

            int mx=*std::max_element(nums.begin(),nums.end());

            std::vector<int> all_primes(mx+1);
            for(int i=2;i<=mx;++i) all_primes[i]=is_prime(i)?i:all_primes[i-1];

            int n=nums.size();
            for(int i=0;i<n;++i){
                int limit=i==0?nums[0]:nums[i]-nums[i-1];

                if(limit<=0) return false;

                int largest_prime=all_primes[limit-1];
               
                nums[i]-=largest_prime;
            }
            return true;
        }
};
// @lc code=end

