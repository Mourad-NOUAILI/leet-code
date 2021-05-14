/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {
    public:
        vector<vector<int>> m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row_size = matrix.size();
        int col_size = matrix[0].size();

        m.resize(row_size + 1);
        for (int i = 0 ; i < row_size+1; ++i)
            m[i].resize(col_size + 1);
     
        for (int i = 0 ; i < row_size+1 ; ++i){
            for (int j = 0 ; j < col_size+1; ++j) {
                if (i == 0 || j == 0) m[i][j] = 0;
                else if (i == 0) m[i][j] = matrix[i][j-1] + m[i][j];
                else if (j == 0) m[i][j] = matrix[i-1][j] + m[i][j];
                else m[i][j] = matrix[i-1][j-1] + m[i-1][j] + m[i][j-1] - m[i-1][j-1];
           }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return m[row2 + 1][col2 + 1] - m[row1][col2 + 1] - (m[row2 + 1][col1] - m[row1][col1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

