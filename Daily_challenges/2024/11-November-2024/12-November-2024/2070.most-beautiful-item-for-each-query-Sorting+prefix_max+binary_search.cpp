/*
 * @lc app=leetcode id=2070 lang=cpp
 *
 * [2070] Most Beautiful Item for Each Query
 */

// @lc code=start

/*
    Sorting items+prefix max + binary search
    Time complexity: O(3n+ nlogn + mlogn) = O((n+m)logn)
    Space complexity: O(3n)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution {
    public:
        vi maximumBeauty(vvi& items, vi& queries){
            
            // Sort the items base on prices
            std::sort(items.begin(),items.end());

            // Create two independant arrays for prices and beauties
            // to facilate searching
            vi prices,beauties;
            for(auto& item: items){
                prices.push_back(item[0]);
                beauties.push_back(item[1]);
            };

            int n=beauties.size();

            // Create prefix max array for beauties
            // to get the max beauty of each query in constant time
            vi prefix_max(n);
            prefix_max[0]=beauties[0];
            for(int i=1;i<n;++i) prefix_max[i]=std::max(prefix_max[i-1],beauties[i]);

            vi ans;
            // For each price query 
            for(auto& q: queries){
                int max_beauty=0; // Its max beauty is by default 0
                
                // Perform an upper bound binary search on prices 
                int i=std::upper_bound(prices.begin(),prices.end(),q)-prices.begin();
                
                // Because, we're looking for the upper bound
                // the max beauty is at index (i-1) 
                if(i-1>=0) max_beauty=prefix_max[i-1];

                ans.push_back(max_beauty); // add the max beauty of the query q to the answer
            }
           
            return ans;
        }
};
// @lc code=end

