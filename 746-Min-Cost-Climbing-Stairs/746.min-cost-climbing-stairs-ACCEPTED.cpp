/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 * 
 * *********Solution using memoization********
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> memo;
    int f(vector<int>& cost, int i, int n) {
        if (i == n-1) return 0;

        if (memo.find(i) != memo.end()) return memo[i];
        
        if (i == n - 2) return memo[i] = cost[i];
        return memo[i] = cost[i] + min(f(cost, i + 1, n), f(cost, i + 2, n));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        auto it1 = cost.begin();
        cost.insert(it1, 0);
        auto it2 = cost.end();
        cost.insert(it2, 0);
        int n = cost.size();
        return f(cost, 0, n);   
    }
};
// @lc code=end

