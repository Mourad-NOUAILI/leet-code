/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    DFS traversal
    Time complexity: O(n+m)
    Space complexity: O(3n)
    n: #nodes
    m: #edges

*/
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;

class Solution {
    public:
        vi eventualSafeNodes(vvi& graph){
            int n=graph.size();

            vi visited(n,0),has_back_edge(n,0);

            // Detect cycles
            // Return true, if a node u belongs to a cycle.
            // False, otherwise
            auto dfs=[&](int u,auto& self)->bool{
                visited[u]=1;
                has_back_edge[u]=1;
                for(auto& v: graph[u]){
                    // Cycle found or a back edge to v exists
                    if(!visited[v] && self(v,self) || has_back_edge[v]) return true;
                }

                // The ingoing edge to u is not a back edge
                has_back_edge[u] = 0;

                // u does not lead to a cycle
                return false;
            };

            for(int node=0;node<n;++node){
                if(visited[node]) continue;
                dfs(node,dfs);
            }

            vi ans;
            for(int node=0;node<n;++node){
                if(!has_back_edge[node]) ans.push_back(node);
            }
            
            return ans;
        }
};
// @lc code=end

int main(){
    vvi g={{1},{2,3},{0},{}};
    Solution sol=Solution();
    vi ans=sol.eventualSafeNodes(g);
    for(auto& e: ans) std::cout<<e<<' ';
    std::cout<<'\n';
    return 0;
}