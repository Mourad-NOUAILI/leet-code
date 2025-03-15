/*
 * @lc app=leetcode id=2523 lang=cpp
 *
 * [2523] Closest Prime Numbers in Range
 */

// @lc code=start
/*
    Sieve of Eratosthenes: store all primes numbers
    Time complexity: O(right log log sqrt(right)+(right-left)+m)
    Space compelxity: O(right+m)
*/
class Solution {
    public:
        std::vector<int> closestPrimes(int left, int right) {
            // Build Sieve of Eratosthenes's array
            // TC: O(right log log sqrt(right))
            // SC: O(right)
            std::vector<int> is_prime(right+1,true);
            is_prime[0]=is_prime[1]=false;
            for(int i=2;i*i<=right;++i){
                if(is_prime[i]){
                    for(int j=i*i;j<=right;j+=i) is_prime[j]=false;
                }
            }

            // Store all primes numbers in range[left,right]
            // TC: O(right-left)
            // SC: O(m)
            std::vector<int> primes;
            for(int i=left;i<=right;++i){
                if(is_prime[i]) primes.push_back(i);
            }
            
            // Get the two closest prime numbers in range [left,right]
            // TC: O(m)
            // SC: O(1)

            // Get the primes size
            int m=primes.size();

            // if size<2, means there is no pair
            if(m<2) return {-1,-1};

            int diff=INT_MAX; // Track the minimum difference
            int prime1,prime2; // Track pair of the two closest primes numbers
            // Iterate all over primes numbers found in range[left,right]
            for(int i=0;i<m-1;++i){
                // If their difference is less than the minimum difference found so far
                if(primes[i+1]-primes[i]<diff){
                    diff=primes[i+1]-primes[i]; // Minimize the difference

                    // Update the answer
                    prime1=primes[i];
                    prime2=primes[i+1];
                }
            }

            return{prime1,prime2};
        }
};
// @lc code=end

