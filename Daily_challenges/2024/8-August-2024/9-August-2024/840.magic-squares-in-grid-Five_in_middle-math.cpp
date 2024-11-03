/*
 * @lc app=leetcode id=840 lang=cpp
 *
 * [840] Magic Squares In Grid
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Use 3x3 magic square properties+Math observation
    Time complexity: O(nm*(9+15+15))=O(39nm)=O(nm)
    Space complexity: O(9+15+15)=O(1)
*/
class Solution {
    public:
        bool is_magic_square(std::vector<std::vector<int>>& square){
            if(square[1][1] != 5) return false;

            std::string spiral1="438167294381672";
            std::string spiral2="927618349276183";

            std::string s=std::to_string(square[0][0])+std::to_string(square[0][1])+std::to_string(square[0][2])
                +std::to_string(square[1][2])+std::to_string(square[2][2])
                +std::to_string(square[2][1])+std::to_string(square[2][0])
                +std::to_string(square[1][0]);
           
            if(spiral1.find(s)==std::string::npos && spiral2.find(s)==std::string::npos) return false;
            
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

