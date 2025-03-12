/*
 * @lc app=leetcode id=2661 lang=cpp
 *
 * [2661] First Completely Painted Row or Column
 */

// @lc code=start
/*
    Mapping+Counting
    Time complexity: O(2mn)
    Space compelxity: O(mn+(m+n))
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
    public:
        int firstCompleteIndex(vi& arr, vvi& mat) {
            int m=mat.size();
            int n=mat[0].size();

            // Preprocessing by each cell value in the matrix to its position (row,col)
            vvi val_pos(m*n+1); // Store cell_value: (row,col)
            for(int row=0;row<m;++row){
                for(int col=0;col<n;++col){
                    int cell_value=mat[row][col];
                    val_pos[cell_value]={row,col};
                }
            }

            // Create frequency array:

            //  --rows--columns--
            // [0~(m-1)~m~(m+n-1)]
            vi freq(m+n,0);

            // For each row and column, determine the number of painting
            for(int i=0;i<m*n;++i){
                // Element to paint
                int e=arr[i];

                // Lookup its position in matrix
                int row=val_pos[e][0];
                int col=val_pos[e][1];

                // Increment the row and column that belong to the element ot paint
                freq[row]++;
                freq[m+col]++;

                // If the whole row is painted, or the whole column is painted return the inedex 
                if(freq[row]==n || freq[m+col]==m) return i;
            }

            // Never reached, because it is guarantee that we have answer
            return m+n-1;
        }
};
// @lc code=end

