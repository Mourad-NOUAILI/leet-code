/*
 * @lc app=leetcode id=2965 lang=cpp
 *
 * [2965] Find Missing and Repeated Values
 */

// @lc code=start

/*
    One pass: Mapping with array+Math
    Time compelxity: O(2n^2)
    Space complexity: O(n^2)
*/
class Solution {
    public:
        std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
            int n=grid.size();

            int m=n*n;
            
            // Sum from 1 to m
            int sm=m*(m+1)/2;

            // To mark all numbers in the grid as seen
            std::vector<bool> seen(m+1,false);

            // Pass #1: look for the number `a` that appears twice
            // and compute the sum of all elements in the grid
            int sg=0,a;
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    int e=grid[i][j];
                    sg+=e;
                    if(seen[e]) a=e; // `a` is found
                    seen[e]=true;
                }
            }

            // b=a+sm-sg
            return {a,a+sm-sg};

        }
};
// @lc code=end

