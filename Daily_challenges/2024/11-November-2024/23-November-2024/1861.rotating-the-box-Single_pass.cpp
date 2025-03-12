/*
 * @lc app=leetcode id=1861 lang=cpp
 *
 * [1861] Rotating the Box
 */

// @lc code=start
/*
    One pointer: Mark the lowest empty cell
    Single pass:gravity effect+Rotation
    Time complexity: O(m.n)
    Space complexity: O(n.m)
*/
typedef std::vector<char> vc;
typedef std::vector<vc> vvc;
class Solution {
    public:
        vvc rotateTheBox(vvc& box){
            int m=box.size();
            int n=box[0].size();

            // Gravity and rotation
            vvc rot(n,vc(m,'.'));
            for(int i=0;i<m;++i){
                int lowest_empty_cell_idx=n-1;
                for(int j=n-1;j>=0;--j){
                    if(box[i][j]=='#'){
                        rot[lowest_empty_cell_idx][m-i-1]='#';
                        lowest_empty_cell_idx--;
                    }
                    if(box[i][j]=='*'){
                        rot[j][m-i-1]='*';
                        lowest_empty_cell_idx=j-1;
                    }
                }
            }

            return rot;
        }
};
// @lc code=end

