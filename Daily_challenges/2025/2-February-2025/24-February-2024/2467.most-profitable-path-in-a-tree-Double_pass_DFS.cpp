/*
 * @lc app=leetcode id=2467 lang=cpp
 *
 * [2467] Most Profitable Path in a Tree
 */

// @lc code=start
/*
    Double Pass DFS
    Time complexity: O(6n)
    Space compelxity: O(6n)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution{
    private:
        vvi graph;
        int n;
        vi parent,depth;
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
            // Function DFS having double role:
            // 1st call: Compute the depth and the parent of each node while Alice move
            // 2nd call: Compute the max income of Alice, While both of them move
            auto dfs=[&](int u,int par,int d,auto& self)->int{
                int alice_income=amount[u];
                int max_path=INT_MIN;
                depth[u]=d;
                parent[u]=par;
                for(auto& v: graph[u]){
                    if(v!=par) max_path=std::max(max_path,self(v,u,d+1,self));
                }

                return max_path==INT_MIN?alice_income:alice_income+max_path;
            };

            n=edges.size()+1;

            build_graph(edges);

            // Phase I: Depths from Alice's view
            // Starting from 0(Alice start node), get depths and parent of each node

            depth.resize(n,0); // Store each node's depth while Alive move
            parent.resize(n); // Store each node's parent while Alice moves

            // While Alice moves: Compute each node's depth and each node's parent
            dfs(0,-1,0,dfs);

            // Phase II: Depth of each node in Alice's path from Bob's view
            // Starting from bob's start node, determine the depth of each node
            int current=bob,bob_depth=0;
            // While parent of Alice's start node (0) not reached
            while(current!=-1){
                // If Alice's node's depth>Bob's node's depth, means bob moves in that node first
                if(depth[current]>bob_depth) amount[current]=0;
                // If Alice's node's depth==Bob's node's depth, 
                // means both Alice and bOB moves in that node IN SAME TIME
                else if(depth[current]==bob_depth) amount[current]/=2;

                // Otherwise, Alice moves first to that node, so she will take all

                
                current=parent[current]; // Got next node
                bob_depth++; // Bob movee to next node
            }

            // At this point, Bob update all nodes in Alice's path,
            // Simulate the moves of Alice and Bob and compute Alice's max income
            return dfs(0,-1,0,dfs);
        }
};
// @lc code=end

