/*
 * @lc app=leetcode id=2192 lang=cpp
 *
 * [2192] All Ancestors of a Node in a Directed Acyclic Graph
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Optimization (DFS)
    Overall time complexity: O(2n²+nm)
    Overall extra space complexity: O(n+nm+n)
*/
class Solution {
    public:
        std::vector<int>* graph=nullptr;
        std::vector<bool> visited;
        std::vector<std::vector<int>> ans;
    public:
        /*
            Time complexity: O(m+n)
            extra space complexity: O(n)
        */
        void build_graph(int n,std::vector<std::vector<int>>& edges){
            graph=new std::vector<int>[n];
            for(auto& edge: edges){
                graph[edge[0]].push_back(edge[1]);
            }
        }
        /*
            Time complexity: O(n+m)
            extra space complexity: O(n)
        */
        void dfs(int ancestor,int node){
            visited[node]=true;
            for(auto& v: graph[node]){
                if(visited[v]) continue;
                ans[v].push_back(ancestor);
                dfs(ancestor,v);
            }
        }
       
        vector<vector<int>> getAncestors(int n, std::vector<std::vector<int>>& edges){
            build_graph(n,edges);

            ans.resize(n);
            
            //O(n*(n+n+m))
            for(int i=0;i<n;++i){
                visited.resize(n);
                std::fill(visited.begin(),visited.end(),false);
                dfs(i,i);
            }

            return ans;
        }
    };
// @lc code=end

