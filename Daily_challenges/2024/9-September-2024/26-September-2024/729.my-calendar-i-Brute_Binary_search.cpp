/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Binary search: for each book query,
    check if the new event (start to end) overlap or not
    with all previous events.

    Time complexity: O(nlogn)
    Space complexity: O(n)
    n: total number of events
*/
class MyCalendar {
    private:
        std::map<int,int> booked;
    public:
        MyCalendar() {
            
        }
        
        bool book(int start, int end) {
           //Find next event
           auto next=booked.lower_bound(start);
           // If next event overlaps with the next one, don't sechedule it
           if(next!=booked.end() && next->first<end) return false;
           // If next event overlaps with the next one, don't sechedule it
           if(next!=booked.begin() && std::prev(next)->second>start) return false;

           // Otherwise, schedule the new event (from start to end)
           booked[start]=end;
           return true;
        }
    };


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

