/*
 * @lc app=leetcode id=2392 lang=cpp
 *
 * [2392] Build a Matrix With Conditions
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Time complexity: O(n+m+klogk)
    Extra space complexity: O(n+m+k)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
    public:
        vi* above_graph=nullptr;
        vi* left_graph=nullptr;
    public:
        void build_graph(int k,vvi& edges,vi*& graph){
            graph=new vi[k];
            for(auto& edge: edges){
                int u=edge[0],v=edge[1];
                graph[u].push_back(v);
            }
        }

        vi top_sort(int k,vi*& graph){
            vi indegree(k,0);
            for(int node=1;node<k;++node){
                for(auto& u: graph[node]){
                    indegree[u]++;
                }
            }

            std::queue<int> q;
            
            for(int node=1;node<k;++node){
                if(indegree[node]==0) q.push(node);
            }

            vi ans;
            while(!q.empty()){
                int node=q.front();
                q.pop();

                ans.push_back(node);

                for(auto& u: graph[node]){
                    indegree[u]--;
                    if(indegree[u]==0) q.push(u);
                }
            }

            for(int node=1;node<k;++node){
                if(indegree[node]!=0) return {};
            }

            return ans;
            
        }

        vvi buildMatrix(int k, vvi& rowConditions, vvi& colConditions){
            k++;
            
            build_graph(k,rowConditions,above_graph);
            build_graph(k,colConditions,left_graph);

            vi top_sort_above=top_sort(k,above_graph);
            vi top_sort_left=top_sort(k,left_graph);

            if(top_sort_above.empty() || top_sort_left.empty() ) return {};

            k--;

            std::unordered_map<int,int> row_pos;
            for(int i=0;i<k;++i) row_pos[top_sort_above[i]]=i;
        

            vvi ans(k,vi(k,0));
            for(int i=0;i<k;++i) ans[row_pos[top_sort_left[i]]][i]=top_sort_left[i];

            return ans;
        }   
};
// @lc code=end

