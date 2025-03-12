/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Brute force: for each book query,
    check if the new event (start to end) overlap or not
    with all previous events.

    Time complexity: O(n^2)
    Space complexity: O(n)
    n: total number of events
*/
class MyCalendar {
    private:
        // Store all events
        std::vector<std::pair<int,int>> booked;
    public:
        MyCalendar() {
            
        }

        // Could be called n times
        bool book(int start, int end) {
            // For each previous event (s to e)...
            for(auto& [s,e]: booked){
                // if it overlap with the new event
                // (start to end), don't sechedule the new event
                if(s<end && e>start) return false;
            }
        
            // Otherwise, add the new event to the list
            booked.push_back({start,end});

            // Accept scheduling the new event.
            return true;
        }
    };

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

