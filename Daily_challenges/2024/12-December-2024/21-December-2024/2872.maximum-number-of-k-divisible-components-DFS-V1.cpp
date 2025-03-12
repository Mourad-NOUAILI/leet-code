/*
 * @lc app=leetcode id=2872 lang=cpp
 *
 * [2872] Maximum Number of K-Divisible Components
 */

// @lc code=start

/*
    DFS
    Time complexity: O(V+V+(V+E))=O(V+E)
    Space complexity: O((V+E)+V)=O(V+E)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
    private:
        int V,E;
        vvi graph;
    public:
        void build_graph(vvi& edges){
            graph.resize(V);
            for(auto& edge: edges){
                int u=edge[0];
                int v=edge[1];
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }

        int maxKDivisibleComponents(int n, vvi& edges, vi& values, int k){
            V=n;
            E=edges.size();
            
            build_graph(edges);

            int ans=0;
            
            auto dfs=[&](int u,int par,long long s,auto& self)->long long{
                long long sum=values[u];
                for(auto& v: graph[u]){
                    // a node should not call its parent
                    if(v==par) continue;
                    // Cumulate sum at each node
                    sum+=self(v,u,s,self);
                }
                
                // If sum at node is divisible by k
                // means we found a component
                if((s-sum)%k==0) ans++;

                return sum;
            };
            
            // Compute total sum of all tree
            long long s=std::accumulate(values.begin(),values.end(),0*1ll);

            // Start by any node
            dfs(0,-1,s,dfs);
            
            return ans;
        }
};
// @lc code=end

