/*
 * @lc app=leetcode id=2493 lang=cpp
 *
 * [2493] Divide Nodes Into the Maximum Number of Groups
 */

// @lc code=start
/*
    Build the graph: <O(m),O(mn)>
    Check if graph is bipartitable using DSU: <O(nα(n)),O(3n)>
    Get all graph components using DSU: <O(mα(n)+n+n),O(5n)>
    Cumulate the number of groups that we can make of each component: <O(n),O(1)>
    Overall time complexity: O((n+m)α(n))
    Overall sapce complexity: O(mn+8n)
    n: #nodes
    m: #edges
*/

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class DSU{
    public:
        vi parent;
        vi group;

        DSU(int _N){
            parent.resize(_N);
            group.resize(_N,1);
            for(int i=0;i<_N;++i){
                parent[i]=i;
            }
        }

        int find(int p){
            if(p==parent[p]) return p;
            return parent[p]=find(parent[p]);

            // Iterative
            /*int root=p;
            while(root!=parent[root]){
                root=parent[root];
            }
            while(parent[p]!=root){
                int next=parent[p];
                parent[p]=root;
                p=next;
            }
            return root;*/
        }

        void unify(int p,int q){
            int parent_p=find(p);
            int parent_q=find(q);
            if(parent_p==parent_q) return;

            if(group[parent_p]<group[parent_q]){
                group[parent_q]+=group[parent_p];
                group[parent_p]=1;
                parent[parent_p]=parent_q;
                
            }
            else{
                group[parent_p]+=group[parent_q];
                group[parent_q]=1;
                parent[parent_q]=parent_p;
            }
        }
};

class Solution {
    private:
        vvi graph,components;
        vi depth;

    public:
        void build_graph(int n, vvi& edges){
            graph.resize(n);
            for(auto& edge: edges){
                int u=--edge[0];
                int v=--edge[1];
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }

        // Check if graph is bipartitable using union find
        // https://www.youtube.com/watch?v=f7xY_7wTa3M&list=PL-FHy1OmEFZsAhLhVAUYzguW4zzNXHE15&index=3
        bool is_bipartitable(int n){
            DSU dsu=DSU(n);
            for(int u=0;u<n;++u){
                for(auto& v: graph[u]){
                    int v0=graph[u][0];
                    if(dsu.find(u)==dsu.find(v)) return false;
                    dsu.unify(v,v0);
                }
            }
            return true;
        }

        // Store all graph components using union find 
        void get_components(int n,vvi& edges){
            std::unordered_map<int,vi> comp;
            DSU dsu=DSU(n);
            for(auto& edge: edges){
                int u=edge[0];
                int v=edge[1];
                dsu.unify(u,v);
            }
            for(int node=0;node<n;++node){
                int parent=dsu.find(node);
                comp[parent].push_back(node);
            }

            for(auto&[_,c]: comp){
                components.push_back(c);
            }
        }

        // Count the maximum number of groups that we can made using BFS
        int count_groups(int n,int node){
            vi depth(n,0);

            std::queue<int> q;
            q.push(node);

            depth[node]=1;
            int goup_count=1;
            while(!q.empty()){
                int cur_node=q.front();
                q.pop();
                for(auto& ne: graph[cur_node]){
                    if(!depth[ne]){
                        depth[ne]=depth[cur_node]+1;
                        goup_count=std::max(goup_count,depth[ne]);
                        q.push(ne);
                    }
                    
                }
            }
            return goup_count;
        }

        int magnificentSets(int n, vvi& edges){
            // Construct the graph adjacency list
            build_graph(n,edges);

            // Check the graph is bipartitable
            if(!is_bipartitable(n)) return -1;
            
            // Determine all the components of the graph
            get_components(n,edges);
            
            // For each component:
            int ans=0;
            for(auto& cur_comp: components){
                // Starting from each node if the current component
                // Count the maximum number of groups that we can made
                int cnt=0;
                for(auto& node: cur_comp){
                    cnt=std::max(cnt,count_groups(n,node));
                }
                // Cumulate the number of groups
                ans+=cnt;
            }

            return ans;
        }
};
// @lc code=end

