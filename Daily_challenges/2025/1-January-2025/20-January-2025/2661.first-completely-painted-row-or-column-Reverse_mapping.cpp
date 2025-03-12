/*
 * @lc app=leetcode id=2661 lang=cpp
 *
 * [2661] First Completely Painted Row or Column
 */

// @lc code=start
/*
    Reverse mapping
    Time complexity: O(3mn)
    Space compelxity: O(mn)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
    public:
        int firstCompleteIndex(vi& arr, vvi& mat) {
            int m=mat.size();
            int n=mat[0].size();

            // Store the index of each number in the arr
            vi val_pos(m*n+1); 
            for(int i=0;i<m*n;++i){
                val_pos[arr[i]]=i;
            }

            int ans=INT_MAX;

            // Determines the smallest index row completely painted
            for(int row=0;row<m;++row){
                // Tracks the greatest index in this row
                int max_row_index=INT_MIN;
                for(int col=0;col<n;++col){
                    int e=mat[row][col];
                    max_row_index=max(max_row_index,val_pos[e]);
                }
                // Update result with the minimum index where this row is fully
                // painted
                ans=std::min(ans,max_row_index);
            }

            // Determines the smallest index column completely painted
            for(int col=0;col<n;++col){
                // Tracks the greatest index in this column
                int max_col_index=INT_MIN;
                for(int row=0;row<m;++row){
                    int e=mat[row][col];
                    max_col_index=max(max_col_index,val_pos[e]);
                }
                // Update the answer with the minimum index where this column is fully
                // painted
                ans=std::min(ans,max_col_index);
            }

        
            return ans;
        }
};
// @lc code=end

