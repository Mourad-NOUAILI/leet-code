/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

// @lc code=start

/*
    Active Interval counting
    Time complexity: O(nm)
    Space complexity: O(m)
    n: total number of events
    m: number of starting points and and points
*/

class MyCalendarTwo {
    private:
        std::map<int,int> dp;
    public:
        MyCalendarTwo() {
            
        }
        
        bool book(int start, int end) {
            dp[start]++;
            dp[end]--;
            int s = 0;
            for (auto v: dp){
                s += v.second;
                if (s >= 3) {
                    dp[start]--;
                    dp[end]++;
                    return false;
                }
            }
            return true;
        }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

