/*
 * @lc app=leetcode id=2192 lang=cpp
 *
 * [2192] All Ancestors of a Node in a Directed Acyclic Graph
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Backtracking+DFS: TLE
    Overall time complexity: O(m*n*logn*2^n)
    Overall extra space complexity: O(n+n+nm+n+n^2)
*/
class Solution {
    public:
        std::vector<int>* graph=nullptr;
        std::vector<std::vector<int>> ans;
        std::vector<bool> visited;
        std::vector<std::vector<bool>> seen;
    public:
        /*
            Time complexity: O(m)
            extra space complexity: O(n)
        */
        void build_graph(int n,std::vector<std::vector<int>>& edges){
            graph=new std::vector<int>[n];
            for(auto& edge: edges){
                graph[edge[0]].push_back(edge[1]);
            }
        }
        /*
            Time complexity: O(n+nlogn+2^n)
            extra space complexity: O(n)
        */
        void dfs(int u,std::vector<int>& tmp){
            if(visited[u]) return;
            visited[u]=true;
            tmp.push_back(u);
            for(auto& v: graph[u]){
                dfs(v,tmp);
            }
            for(auto& e: tmp) {
                if(!seen[u][e]&&u!=e) ans[u].push_back(e);
                seen[u][e]=true;
            }
            std::sort(ans[u].begin(),ans[u].end());

            tmp.pop_back();
            visited[u]=false;
        }
       
        vector<vector<int>> getAncestors(int n, std::vector<std::vector<int>>& edges){
            build_graph(n,edges);
            ans.resize(n);
            seen.resize(n,std::vector<bool>(n,false));
            for(int i=0;i<n;++i){
                visited.resize(n,false);
                std::vector<int> tmp;
                dfs(i,tmp);
            }
            
            return ans;
        }
    };
// @lc code=end

