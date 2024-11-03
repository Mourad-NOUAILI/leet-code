/*
 * @lc app=leetcode id=840 lang=cpp
 *
 * [840] Magic Squares In Grid
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Use 3x3 magic square properties
    Time complexity: O(nm*(9+9))=O(18nm)=O(nm)
    Space complexity: O(9+3+3)=O(1)
*/
class Solution {
    public:
        bool is_magic_square(std::vector<std::vector<int>>& square){
            // If 5 is not in middle, it can not be a magic square 
            if(square[1][1] != 5) return false;

            // Computes sums, and check if digits from 1 to 9
            // are all present once.
            int row_sum[3]={0},col_sum[3]={0};
            int mask=511;
            for(int i=0;i<3;++i){
                for(int j=0;j<3;++j){
                    int x=square[i][j];
                    if(x<=0 || x>9) return false;
                    row_sum[i]+=x;
                    col_sum[j]+=x;
                    mask=(mask & (~(1<<(x-1))));
                }
            }
            // mask !=0, means it exists a digit that exists than one, or
            // it exists a digit that does not a exist. 
            if(mask!=0) return false;
            
            // sums of all rows, and all columns must be 15
            if (!all_of(row_sum, row_sum+3,[](int sum){return sum==15;})) return false;
            if (!all_of(col_sum, col_sum+3,[](int sum){return sum==15;})) return false;
            
            // It all checks above ar good
            return true;
        }

        int numMagicSquaresInside(std::vector<std::vector<int>>& grid) {
            int n=grid.size();
            int m=grid[0].size();

            int ans=0;
            for(int i=0;i<=n-3;++i){
                for(int j=0;j<=m-3;++j){
                    if(j+2>m-1) break;
                    if(i+2>n-1) return ans;
                    std::vector<std::vector<int>> square(3,std::vector<int>(3));
                    for(int k=0;k<3;++k){
                        for(int l=0;l<3;++l){
                            square[k][l]=grid[i+k][j+l];
                        }
                    }
                    if (is_magic_square(square)) ans++;
                }
            }
            return ans;
        }
};
// @lc code=end

