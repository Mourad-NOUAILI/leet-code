/*
 * @lc app=leetcode id=2523 lang=cpp
 *
 * [2523] Closest Prime Numbers in Range
 */

// @lc code=start
/*
    Sieve of Eratosthenes: Track pair of the two adjacents prime numbers
    Time complexity: O(right log log sqrt(right)+(right-left))
    Space compelxity: O(right)
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
            
            // Get the two first smallest prime number
            // TC: O(right-left)
            // SC: O(1)
           
            int diff=INT_MAX; // To minimize the difference
            int prev_prime=-1,next_prime=-1; // Track the two adjacents primes numbers
            int prime1=-1,prime2=-1; // Track the two primes numbers with minimum difference
            for(int cur_num=left;cur_num<=right;++cur_num){
                // If current number is not prime, pass the next number
                if(!is_prime[cur_num]) continue;

                // If current number is prime

                // If we still don't have the previous prime number and the 
                // the current number will be the previous prime number
                if(prev_prime==-1) prev_prime=cur_num;

                // If we still don't have the next prime number tha immediately follows the previous prime number
                // the current number will be the next prime number
                else if(next_prime==-1) next_prime=cur_num; 
                
                // Once we have both the two adjacents prime numbers
                if(next_prime!=-1 && prev_prime!=-1){

                    int d=next_prime-prev_prime;

                    // If difference between the two adjacent prime numbers is less or equal than 2
                    // This is the minimum diffrernce that we can have
                    if(d<=2) return {prev_prime,next_prime};

                    // If their difference is less than minimal difference found so far
                    if(d<diff){
                        diff=d; // Minimize the diffrence

                        // Update the answer
                        prime1=prev_prime;
                        prime2=next_prime;
                    }

                    // Pass to the two next adjacent prime numbers
                    prev_prime=next_prime;
                    next_prime=-1;
                }
            }

            return {prime1,prime2};
        }
};
// @lc code=end

