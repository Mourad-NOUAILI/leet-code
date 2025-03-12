/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start

/*
    BFS-Topological sort (Kahn's algorithm)
    Time complexity: O(n+m)
    Space complexity: O(n+m)
    n: #nodes
    m: #edges

*/
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;

class Solution {
    public:
        vi eventualSafeNodes(vvi& graph){
            int n=graph.size();

            vvi g(n); // <O(n),O(n+m)>
            std::vector<int> indegree(n,0); // <O(n),O(n)>
            // <O(m),O(1)>
            for(int v=0;v<n;++v){
                for(auto& u: graph[v]){
                    g[u].push_back(v);
                    indegree[v]++;
                }
            }
            
            // <O(n),O(n)>
            std::queue<int> q;
            for(int node=0;node<n;++node){
                if(indegree[node]==0) q.push(node);
            }

            vi is_safe(n,0); // <O(n),O(n)>
            // <O(m),O(1)>
            while(!q.empty()){
                int node=q.front();
                q.pop();

                is_safe[node]=1;

                for(auto& u: g[node]){
                    indegree[u]--;
                    if(indegree[u]==0) q.push(u);
                }
            }

            // <O(n),O(n)>
            vi ans;
            for(int node=0;node<n;++node){
                if(is_safe[node]) ans.push_back(node);
            }

            return ans;  
        }
};
// @lc code=end

