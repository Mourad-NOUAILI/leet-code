/*
 * @lc app=leetcode id=2467 lang=cpp
 *
 * [2467] Most Profitable Path in a Tree
 */

// @lc code=start
/*
    One Pass DFS
    Time complexity: O(3n)
    Space compelxity: O(4n)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution{
    private:
        vvi graph;
        int n;
        vi depth; // Bob's depth
    public:
        void build_graph(vvi& edges){
            graph.resize(n);
            for(auto& edge: edges){
                int u=edge[0];
                int v=edge[1];
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }

        int mostProfitablePath(vvi& edges, int bob, vi& amount){
        
            auto dfs=[&](int u,int par,int alice_depth,int& alice_score,auto& self)->void{
                // Initialize Alice's income to 0
                int alice_take=0;

                // Initialize Bob's depth
                if(u==bob) depth[u]=0;
                else depth[u]=INT_MAX/2;

                // Maximum of each path to a leaf node
                int max_path=INT_MIN;

                for(auto& v: graph[u]){
                    if(v!=par){
                        self(v,u,alice_depth+1,max_path,self);
                        
                        // Update Bob's depth while we identifying his path
                        depth[u]=std::min(depth[u],depth[v]+1);
                    }
                }
                // If Bob's depth > Alice's, means Alice visit that node first
                // So, Alice will take all
                if(depth[u]>alice_depth) alice_take=amount[u];
                // If both depths are equal, they wil share the value at that node
                else if(depth[u]==alice_depth) alice_take=amount[u]/2;

                alice_score=std::max(alice_score,max_path==INT_MIN?alice_take:alice_take+max_path);
            };

            n=edges.size()+1;

            build_graph(edges);

            depth.resize(n,0);

            int alice_score=INT_MIN;
            dfs(0,-1,0,alice_score,dfs);

            return alice_score;
        }
};

// @lc code=end

