/*
 * @lc app=leetcode id=2601 lang=cpp
 *
 * [2601] Prime Subtraction Operation
 */

// @lc code=start

/*
    Sieve of Eratosthenes
    Time complexity: O(n+mx log log mx)
    Space complexity: O(mx)
*/
class Solution {
    public:
    
        bool primeSubOperation(std::vector<int>& nums){
           
            int mx=*std::max_element(nums.begin(),nums.end());

            // Build the sieve array.
            std::vector<bool> sieve(mx+1,true); // Mark all as primes
            sieve[0]=sieve[1]=0; // 0 and 1 are not primes
            int sr=sqrt(mx+1);
            for(int i=2;i<=sr;++i){
                if(sieve[i]){ // If is prime
                    // Mark its all multiples as not prime
                    for(int j=i*i;j<=mx;j+=i){
                        sieve[j]=false;
                    }
                }
            }

            int n=nums.size();

            // Start by storing the current value as 1, and the initial index as 0.
            int cur=1;
            int i=0;
            while(i<n){
                // Compute the difference needed to make nums[i] equal to currValue.
                int diff=nums[i]-cur;

                // if diff<0, means that nums[i]<cur
                // Can't make strictly increasing array 
                if(diff<0) return false;

                // If the difference is prime or zero, then nums[i] can be made
                // equal to currValue.
                if(sieve[diff] || diff==0){
                    i++;
                    cur++;
                }
                // Otherwise, try for the next currValue.
                else cur++;
            }
            return true;
        }
};
// @lc code=end

