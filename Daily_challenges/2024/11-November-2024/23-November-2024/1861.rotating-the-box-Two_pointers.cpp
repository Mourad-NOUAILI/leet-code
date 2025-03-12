/*
 * @lc app=leetcode id=1861 lang=cpp
 *
 * [1861] Rotating the Box
 */

// @lc code=start
/*
    Brute Force: Two pointers to identify the sequence that will fall
    Double passes:gravity effect+Rotation
    Time complexity: O(m.n^2)
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
            for(auto& cur_row: box){
                // Two pointers to identify the sequence of rocks that will fall
                int start=-1,end=-1;
                for(int i=0;i<n;++i){
                    // Stone: Mark the start of the sequence
                    if(cur_row[i]=='#' && start==-1) start=i;

                    // Empty cell: Mark the end of the sequence
                    if(cur_row[i]=='.' && end==-1) end=i;

                    // Obstacle: 
                    if(cur_row[i]=='*') start=-1,end=-1;

                    // Not valid sequence: ..### 
                    if(start!=-1 && end!=-1 && start>end) end=-1;

                    // Valid sequence
                    if(start!=-1 && end!=-1 && end>start){
                        // Empty cell will be on the top
                        cur_row[start]='.';

                        // All stone will go right (fall)
                        for(int j=start+1;j<=end;++j) cur_row[j]='#';

                        // Mark the start of the ne sequence
                        start++;

                        // Don't know its end
                        end=-1;
                    }
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

