/*
 * @lc app=leetcode id=1552 lang=cpp
 *
 * [1552] Magnetic Force Between Two Balls
 */

// @lc code=start

/*
    Binary search: AC
    Time complexity: O(n * log(max_position-min_position))
    Extra space complexity: O(1)
*/

#include<bits/stdc++.h>

class Solution {
public:
    int can_we_place_balls(int dis,std::vector<int>& position,int m){
        int n=position.size();
        int nb_placed_balls=1;
        int prev_pos=0;
        for(int i=0;i<n;++i){
            if(abs(position[i]-position[prev_pos])>=dis){
                prev_pos=i;
                nb_placed_balls++;
                if(nb_placed_balls>=m) return true;
            } 
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m){
        int n=position.size();

        auto min_max=std::minmax_element(position.begin(),position.end());
        int min_distance=*min_max.first;
        int max_distance=*min_max.second;

        int distance=max_distance-min_distance;

        std::sort(position.begin(),position.end());

        int ans=0;
        int left=1,right=distance;
        while(left<=right){
            int mid=(left+right)>>1;
            if(can_we_place_balls(mid,position,m)){
                left=mid+1;
                ans=std::max(ans,mid);
            }
            else right=mid-1;
        }
        return ans;
    }
};
// @lc code=end

/*
    [5,4,3,2,1,1000000000]\n2\n
    ==>999999999

    [6,20,3,8,5]\n2\n
    ==>17

     [6,20,3,8,5]\n3\n
    ==>5

    [1,2,3,4,5,6,7,8,9,10]\n4\n
    ==>3
*/