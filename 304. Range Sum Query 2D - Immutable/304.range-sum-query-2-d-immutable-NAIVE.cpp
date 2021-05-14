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
        m = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s = 0;
        for (int i = row1 ; i <= row2 ; ++i)
            for (int j = col1 ; j <= col2 ; ++j)
                s += m[i][j];
        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

