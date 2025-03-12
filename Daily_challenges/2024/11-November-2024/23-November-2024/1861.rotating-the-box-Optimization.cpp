/*
 * @lc app=leetcode id=1861 lang=cpp
 *
 * [1861] Rotating the Box
 */

// @lc code=start
/*
    One pointer: Mark the lowest empty cell
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

            // Gravity
            for(int i=0;i<m;++i){
                // Lowest empty cell: by default last cell
                int lowest_empty_cell_idx=n-1;

                // Process each cell in row `j` from left to right (bottom to top)
                for(int j=n-1;j>=0;--j){
                    // Stone: let it fall to the lowest empty cell
                    if(box[i][j]=='#'){
                        box[i][j]='.';
                        box[i][lowest_empty_cell_idx]='#';
                        lowest_empty_cell_idx--;
                    }
                    // Obstacle: reset `lowest_empty_cell_idx` to the cell 
                    // directly on its left (above it)
                    if(box[i][j]=='*') lowest_empty_cell_idx=j-1;
                }
            }

            // Rotation
            vvc rot(n,vc(m));

            for(int i=0;i<n;++i){
                for(int j=m-1;j>=0;--j){
                    rot[i][m-j-1]=box[j][i];
                }
            }

            return rot;
        }
};
// @lc code=end

