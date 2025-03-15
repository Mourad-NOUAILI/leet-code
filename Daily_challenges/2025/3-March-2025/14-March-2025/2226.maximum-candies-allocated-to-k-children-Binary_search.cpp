/*
 * @lc app=leetcode id=2226 lang=cpp
 *
 * [2226] Maximum Candies Allocated to K Children
 */

// @lc code=start
/*
    Binary search one the answer
    Time complexity: O(n+n log hi)
    Space complexity: O(1)
*/
typedef long long ll;
class Solution {
    public:
        int maximumCandies(vector<int>& candies_piles, ll k) {
            
            // Get the highest value in the list of candies piles
            int hi=*std::max_element(candies_piles.begin(),candies_piles.end());
            
            // Function to check if we can allocate amount of value of candies,
            // `candies_number` to k children
            auto is_possible=[&](int candies_number)->bool{
                ll nb_candies=0;
                for(auto& candies: candies_piles){
                    nb_candies+=candies*1ll/candies_number;
                    if(nb_candies>=k) return true; 
                }
                return false;
            };
            
            // Using binary serach, look for the greatest number of candies that
            // could be possible to be allocate to the k children
            int lo=1;
            while(lo<=hi){
                int candies_number=(lo+hi)>>1;
                // If it is possible, search further 
                if(is_possible(candies_number)) lo=candies_number+1;

                // Otherwise, go backward
                else hi=candies_number-1;
            }
            // -1, because it starts by 1`
            return lo-1; 
        }
};
// @lc code=end

