/*
 * @lc app=leetcode id=1942 lang=cpp
 *
 * [1942] The Number of the Smallest Unoccupied Chair
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    Brute force
    Time complexity: O(nlogn+n^2)=O(n^2)
    Space complexity: O(n)
*/
class Solution {
    public:
        int smallestChair(std::vector<std::vector<int>>& times, int targetFriend){
            int n=times.size();

            int target_friend_arrival=times[targetFriend][0];

            std::sort(times.begin(),times.end());

            std::vector<int> occupied_chairs(n,-1);

            for(auto& time: times){
                int arrival=time[0];
                int leave=time[1];
                int i=0;
                bool is_occupied=false;
                while(i<n&&!is_occupied){
                    if(occupied_chairs[i]<=arrival){
                        if(arrival==target_friend_arrival) return i;
                        occupied_chairs[i] = leave;
                        is_occupied=true;
                    }
                    else is_occupied=false;
                    i++;
                }
            }
            return -1;
        }
};
// @lc code=end

