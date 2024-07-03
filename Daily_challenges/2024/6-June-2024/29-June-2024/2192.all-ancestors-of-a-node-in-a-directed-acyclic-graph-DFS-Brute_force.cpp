/*
 * @lc app=leetcode id=2192 lang=cpp
 *
 * [2192] All Ancestors of a Node in a Directed Acyclic Graph
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Brute force using DFS
    Overall time complexity: O(n^3+n^2*m)
    Overall extra space complexity: O(n+nm)
*/
class Solution {
    public:
        std::vector<int>* graph=nullptr;
        std::vector<std::vector<int>> ans;
    public:
        /*
            Time complexity: O(m+n)
            extra space complexity: O(nm)
        */
        void build_graph(int n,std::vector<std::vector<int>>& edges){
            graph=new std::vector<int>[n];
            for(auto& edge: edges){
                graph[edge[0]].push_back(edge[1]);
            }
        }
        /*
            Function to check if there is a path Between u and v
            Time complexity: O(n+m)
            extra space complexity: O(n)
        */
        bool dfs(int u,int v){
            if(u==v) return true;
            bool test=false;
            for(auto& node: graph[u]){
                test=test||dfs(node,v);
            }
            return test;
        }
       
        vector<vector<int>> getAncestors(int n, std::vector<std::vector<int>>& edges){
            build_graph(n,edges); //O(m+n)

            ans.resize(n); // O(n)
            
            // O(n^2*(n+m))
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    if(i!=j&&dfs(i,j)) ans[j].push_back(i);
                }
            }

            return ans;
        }
    };
// @lc code=end

