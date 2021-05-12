/*
 * @lc app=leetcode id=1854 lang=cpp
 *
 * [1854] Maximum Population Year
 */

// @lc code=start
class Solution {
public:
    // O(N²)
    int maximumPopulation(vector<vector<int>>& logs) {
        
        map <int, int> count;

        for (int year = 1950; year <= 2050 ; ++year)
            count[year] = 0;

        for (auto v: logs) {
            for (int year = v[0] ; year < v[1] ; ++year) {
                // years are inserted in ascending order in the map.
                count[year]++;
            }
        }

        int max_year = 0;
        int cnt_max = 0;
        for (auto cnt: count) {
            if (cnt_max < cnt.second) {
                    cnt_max = cnt.second;
                    max_year = cnt.first;
                }
        }
        
        return max_year;
    }
};
// @lc code=end

