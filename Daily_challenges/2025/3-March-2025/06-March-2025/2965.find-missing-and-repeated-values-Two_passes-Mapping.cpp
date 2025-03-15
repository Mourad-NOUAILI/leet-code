/*
 * @lc app=leetcode id=2965 lang=cpp
 *
 * [2965] Find Missing and Repeated Values
 */

// @lc code=start

/*
    Two passes: Mapping with array
    Time compelxity: O(3n^2)
    Space complexity: O(n^2)
*/
class Solution {
    public:
        std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
            int n=grid.size();

            int m=n*n;
            
            // To mark all numbers in the grid as seen
            std::vector<bool> seen(m+1,false);
            
            // Pass #1: look for the number `a` that appears twice
            int a;
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    int e=grid[i][j];
                    if(seen[e]) a=e; // `a` is found
                    seen[e]=true;
                }
            }

            // Pass #2: look for the number `b` that does not exist
            for(int i=0;i<=m;++i){
                if(!seen[i]) b=i;
            }

            return {a,b};

        }
};
// @lc code=end

