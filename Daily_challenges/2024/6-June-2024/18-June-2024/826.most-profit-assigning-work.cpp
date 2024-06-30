/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    /*
        TODO:UNSERSTAND ALL APPRAOCHES (SEE YOUTUBE)
        Greedy
        Time complexity: O(n)+O(nlogn)+O(mlogm)+O(m+n)
        Extra space complexity: O(m)+O(logm)+O(logn)
    */
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        int m=worker.size();

        std::vector<std::pair<int,int>> w;

        for(int i=0;i<n;++i) w.push_back({difficulty[i],profit[i]});

        std::sort(w.begin(),w.end());
        std::sort(worker.begin(),worker.end());
        
        int ans=0,max_profit=0,j=0;
        for(int i=0;i<m;++i){
            while(j<m&&w[j].first<=worker[i]){
                max_profit=std::max(max_profit,w[j].second);
                j++;
            }
            ans+=max_profit;
        }
        return ans;  
    }
};
// @lc code=end

/**/
