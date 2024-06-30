/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Naive approach: TLE
    Time complexity= O(n * max) = O(n²)
    Extra space complexity: O(1)
*/
class Solution{
public:
    bool are_bouquets_made(int mid,std::vector<int>& bloomDay,int m,int k){
        int cnt_consecutive=0,cnt_bouquets=0;
        int n=bloomDay.size();
        for(int i=0;i<n;++i){
            if(bloomDay[i]<=mid) cnt_consecutive++;
            else cnt_consecutive=0;
            if(cnt_consecutive==k){
                cnt_bouquets++;
                cnt_consecutive=0;
            }
        }
        return cnt_bouquets>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();

        if( (long long)m*k>n) return -1;

        int mx=*std::max_element(bloomDay.begin(),bloomDay.end());

        for(int day=1;day<=mx;++day){
            if(are_bouquets_made(day,bloomDay,m,k)) return day;
        }
        return -1;
    }
};
// @lc code=end

