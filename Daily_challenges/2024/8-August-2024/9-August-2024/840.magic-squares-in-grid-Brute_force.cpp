/*
 * @lc app=leetcode id=840 lang=cpp
 *
 * [840] Magic Squares In Grid
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Brute force
    Time complexity: O(nm*(9+9+9+3+9+9))=O(48nm)=O(nm)
    Space complexity: O(9+9)=O(1)
*/
class Solution {
    public:
        bool is_magic_square(std::vector<std::vector<int>>& square){
            // Check if digits from 1 to 9 are distinct
            bool exists[10]={false};
            for(int i=0;i<3;++i){
                for(int j=0;j<3;++j){
                    int x=square[i][j];
                    if(x>9 || exists[x]) return false;
                    exists[x]=true;
                }
            }
            
            // Check if all digits from 1 to 9 exist
            for(int i=1;i<=9;++i) if(!exists[i]) return false;
            
            // Check sums

            // Compute first sum
            int row_sum=0;
            for(int i=0;i<3;++i) row_sum+=square[0][i];
            
            // Sum of each row
            for(int i=0;i<3;++i){
                int s=0;
                for(int j=0;j<3;++j){
                    s+=square[i][j];
                }
                if(s!=row_sum) return false;
            }

             // Sum of each column
            for(int i=0;i<3;++i){
                int s=0;
                for(int j=0;j<3;++j){
                    s+=square[j][i];
                }
                if(s!=row_sum) return false;
            }
            
            // Sum of the diagonal
            int sd1=square[0][0]+square[1][1]+square[2][2];

            // Sum of the anti-diagonal
            int sd2=square[0][2]+square[1][1]+square[2][0];
    
            if(sd1!=row_sum || sd2!=row_sum) return false;

            // If all checks are good 
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

