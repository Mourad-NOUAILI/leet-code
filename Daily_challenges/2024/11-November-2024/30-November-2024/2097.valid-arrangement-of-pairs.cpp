/*
 * @lc app=leetcode id=2097 lang=cpp
 *
 * [2097] Valid Arrangement of Pairs
 */

// @lc code=start
/*
    Hierholzer's Algorithm to find an Eulerian path:
        1-build graph with in degree and out degree info,
        2-find a valid starting point for DFS,
        3-perform a POSTORDER DFS,
        4-reverse the result

        Time compelxity: O(n+V+n)=O(V+n)
        Space compelxity: O((V+n)+V)=O(V+n)

*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
    private:
        std::unordered_map<int,std::stack<int>> graph;
        std::unordered_map<int,int> in_degree,out_degree;
        vvi ans,final_ans;
public:
    // Time complexity: O(n)
    // Space compelxity: O(V+V+(V+E))=O(V+n), since E=n
    void build_graph_with_info(vvi& pairs){
        for(auto& p: pairs){
            int u=p[0],v=p[1];
            graph[u].push(v);
            in_degree[v]++;
            out_degree[u]++;
        }
    }

    // Time complexity: O(V)
    // Space compelxity: O(1)
    int find_start_node(){
        int start;
        for(auto& [node,_]: graph){
            if(out_degree[node]-in_degree[node]==1) return node;
            if(out_degree[node]>0) start=node;
        }
        return start;
    }
    
    // Time complexity: O(E)=O(n)
    // Space compelxity: O(V)
    void dfs(int u){
        while(!graph[u].empty()){
            int v=graph[u].top();
            graph[u].pop();
            dfs(v);
            ans.push_back({u,v});
        }
    }

    vvi validArrangement(vvi& pairs){
        // Build the directed graph (pair_i[0]--->pair_i[1])
        build_graph_with_info(pairs);

        // Find a valid start node to start for DFS
        int start_node=find_start_node();

        // Perform Post-order(must be Post-order) DFS
        dfs(start_node);

        std::reverse(ans.begin(),ans.end());

        return ans;
    }   
};
// @lc code=end

