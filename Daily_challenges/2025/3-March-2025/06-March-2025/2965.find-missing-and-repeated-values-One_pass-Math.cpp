/*
 * @lc app=leetcode id=2965 lang=cpp
 *
 * [2965] Find Missing and Repeated Values
 */

// @lc code=start

/*
    One pass: Math
    Time compelxity: O(n^2)
    Space complexity: O(1)
*/
typedef long long ll;
class Solution {
    public:
        std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
            int n=grid.size();

            ll m=n*n;

            // Sum from 1 t m
            ll sm=m*(m+1)/2;

            // Sum from 1^2 tp m^2
            ll sm2=(m*(m+1)*(2*m+1))/6;

            // Compute the sum sg of all elements and the sum all elements squares sg2
            ll sg=0,sg2=0;
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    int e=grid[i][j];
                    sg+=e;
                    sg2+=e*e;
                }
            }
            
            // Solve the equations system:
            // sg-sm=a-b
            // sg2-sm2-a^2-b^2

            int s=sg-sm;
            int b=(sg2-sm2-s*s)/(2*s);
            int a=s+b;

            return {a,b};

        }
};
// @lc code=end

