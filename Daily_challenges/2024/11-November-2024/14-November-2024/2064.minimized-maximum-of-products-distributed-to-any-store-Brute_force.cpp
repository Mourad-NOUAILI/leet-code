/*
 * @lc app=leetcode id=2064 lang=cpp
 *
 * [2064] Minimized Maximum of Products Distributed to Any Store
 */

// @lc code=start

/*
    Linear search
    Time complexity: O(m * hi)
    Space complexity: O(1)
    hi: maximum quantitites
    m: number of products
*/
class Solution {
    public:
        int minimizedMaximum(int n, std::vector<int>& quantities){
            // Get max quantity
            int hi=*std::max_element(quantities.begin(),quantities.end());

            // Linear search for the minimum quantity
            // that we can distribute to stores.
            for(int limit=1;limit<=hi;++limit){
                // Determine the maximum number of stores that we can
                // distribute to them `limit` amounts of product
                long long nb_stores=0;  
                for(auto& qte: quantities){
                    nb_stores+=(qte/limit+int(qte%limit!=0));
                }
                // if is possible to distribute `limit` product to
                // the stores, return that limit which represent 
                // the best we can do
                if(nb_stores<=n) return limit; 
            }

            return 0; // Never reached
        }
};
// @lc code=end

