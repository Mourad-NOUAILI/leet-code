/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
    /*
        Time complexity: O(n+nlogn+kn)
        Extra space complexity: O(2n+logn+n)
    */
    public:
        int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
            int n=profits.size();

            std::vector<std::pair<int,int>> cp;
            for(int i=0;i<n;++i) cp.push_back({capital[i],profits[i]});

            sort(cp.begin(),cp.end());

            std::vector<bool> visited(n,false);

            int all_visited=0;
            for(int i=1;i<=k;++i){
                int mx=-1;
                int id=-1;
                for(int j=0;j<n;++j){
                    if(!visited[j]&&w>=cp[j].first&&cp[j].second>mx){
                        mx=cp[j].second;
                        id=j;
                    }
                }

                if(all_visited>=n||mx==-1) return w;

                all_visited++;
                visited[id]=true;
                w+=mx;
            }

            return w;

        }
};
// @lc code=end

/*
    4\n5\n[3,5,1,8,11,2]\n[2,1,0,2,2,0]\n
    ==>32

     20\n5\n[3,5,1,8,11,2]\n[2,1,0,2,2,0]\n


1\n0\n[1,2,3]\n[1,1,2]\n

*/