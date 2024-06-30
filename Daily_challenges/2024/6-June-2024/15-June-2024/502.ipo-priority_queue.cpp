/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
    /*
        Time complexity: O(n+nlogn+nlogn+k)=O(nlogn)
        Extra space complexity: O(2n+logn+2n)
    */
    public:
        int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
            int n=profits.size();

            std::vector<std::pair<int,int>> cp;
            for(int i=0;i<n;++i) cp.push_back({capital[i],profits[i]});

            sort(cp.begin(),cp.end());

            std::priority_queue<int> pq;

            int j=0;
            for(int i=1;i<=k;++i){
                while(j<n&&w>=cp[j].first) {
                    pq.push(cp[j].second);
                    j++;
                }

                if(pq.empty()) return w;

                w+=pq.top();
                pq.pop();
            }

            return w;

        }
};
// @lc code=end

/*
    4\n5\n[3,5,1,8,11,2]\n[2,1,0,2,2,0]\n
    ==>32
*/