/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity= O(n * log max) = O(n log n)
    Extra space complexity: O(1)
*/
class Solution{
public:
    bool are_bouquets_made(int day,std::vector<int>& bloomDay,int m,int k){
        int cnt_consecutive=0,cnt_bouquets=0;
        int n=bloomDay.size();
        for(int i=0;i<n;++i){
            if(bloomDay[i]<=day) cnt_consecutive++;
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

        int left=1;
        int right=*std::max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;

        while(left<=right){
            int mid=(left+right)>>1;
            if(are_bouquets_made(mid,bloomDay,m,k)){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};
// @lc code=end

