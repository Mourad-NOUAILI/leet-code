/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Active Interval counting
    Time complexity: O(nm)
    Space complexity: O(m)
    n: total number of events
    m: number of starting points and and points
*/
class MyCalendar {
        map<int,int> dp;
    public:
        MyCalendar() {
            
        }
        
        bool book(int start, int end) {
            dp[start]++;
            dp[end]--;
            int s = 0;
            for (auto v: dp){
                s += v.second;
                if (s >= 2) {
                    dp[start]--;
                    dp[end]++;
                    return false;
                }
            }
            return true;
        }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

