/*
 * @lc app=leetcode id=1854 lang=cpp
 *
 * [1854] Maximum Population Year
 */

// @lc code=start
class Solution {
public:
    // O(N log N)
    int maximumPopulation(vector<vector<int>>& logs) {

        map<int, int> dp;
        for (auto v : logs){
            dp[v[0]]++;
            dp[v[1]]--;
        }

        int cnt = 0;
        int max_year = 0;
        int cnt_max = 0;
        for (auto p : dp){
            cnt += p.second;
            if (cnt_max < cnt){
                cnt_max = cnt;
                max_year = p.first;
            }
        }

        return max_year;
    }
};
// @lc code=end

