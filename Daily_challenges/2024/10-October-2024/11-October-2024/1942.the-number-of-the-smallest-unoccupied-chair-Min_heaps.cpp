/*
 * @lc app=leetcode id=1942 lang=cpp
 *
 * [1942] The Number of the Smallest Unoccupied Chair
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    Min heaps
    Time complexity: O(nlogn)
    Space complexity: O(2n)=O(n)
*/
typedef std::pair<int,int> ii;
typedef std::vector<ii> vii;
class Solution {
    public:
        int smallestChair(std::vector<std::vector<int>>& times, int targetFriend){
            int n=times.size();

            int target_friend_arrival=times[targetFriend][0];

            std::priority_queue<ii,vii,std::greater<ii>> occupied_chairs;
            std::priority_queue<int,std::vector<int>,std::greater<int>> availabe_chairs;

            for(int i=0;i<n;++i) availabe_chairs.push(i);

            std::sort(times.begin(),times.end());

            for(int i=0;i<n;++i){
                int arrival=times[i][0];
                int leave=times[i][1];

                while(!occupied_chairs.empty() && occupied_chairs.top().first<=arrival){
                    availabe_chairs.push(occupied_chairs.top().second);
                    occupied_chairs.pop();
                }

                if(!availabe_chairs.empty()){
                    int chair=availabe_chairs.top();
                    availabe_chairs.pop();
                    if(arrival==target_friend_arrival) return chair;
                    occupied_chairs.push({leave,chair});
                }

            }

            return -1; // Never reached 
        }
};
// @lc code=end

