/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
class Solution {
public:
    std::vector<std::vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        std::vector<std::vector<int>> ans;

        std::vector<std::pair<int,int>> moves {
            {0,1}, //Right
            {1,0}, //Down
            {0,-1}, //Left
            {-1,0} //Up
        };

        int r=rStart,c=cStart,steps=1;

        int dir=0;
        while(ans.size()<rows*cols){
            for(int k=1;k<=2;++k){
                for(int i=1;i<=steps;++i){
                    if(r>=0&&r<rows&&c>=0&&c<cols) ans.push_back({r,c});
                    r+=moves[dir].first;
                    c+=moves[dir].second;
                }
                dir=(dir+1)%4;
            }
            steps+=1;
        }
        return ans;
    }
};
// @lc code=end

