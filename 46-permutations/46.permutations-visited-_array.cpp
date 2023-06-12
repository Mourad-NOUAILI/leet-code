/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
    private:
        vector<int> s;
        vector<vector<int>> ans;
        bool* visited;

    public:
        void bf(vector<int> nums, int n, int m){
            if (n == 0) {
                ans.push_back(s);
                return;
            }
            
            for(int i = 0 ; i < m ; ++i){
                if(!visited[i]){
                    visited[i] = true;
                    s.push_back(nums[i]);
                    bf(nums,n-1,m);
                    s.pop_back();
                    visited[i] = false;
                }
            }
        }
        vector<vector<int>> permute(vector<int>& nums) {
            int n = nums.size();
            visited = new bool[n];
            fill(visited,visited+n,false);
            bf(nums,n,n);
            return ans;
        }
};
// @lc code=end

