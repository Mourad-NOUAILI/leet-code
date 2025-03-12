/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 */

// @lc code=start

/*
    Topological sort (compute prerequisites of each node)
    Time complexity: O(2n+n^2+n+n^3+qn)=O(3n+n^2+n^3+qn)
    Space complexity: O(n+2n^2)
*/

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution {
    private:
        vvi graph;
        vi indegree;
        std::vector<std::unordered_set<int>> node_prerequisites;
    public:
        // Build the directed graph
        // <O(2n+n^2),O(n^2)>
        void build_graph(vvi& prerequisites,int n){
            graph.resize(n);
            indegree.resize(n,0);
            int m=prerequisites.size();
            for(int i=0;i<m;++i){
                int u=prerequisites[i][0];
                int v=prerequisites[i][1];
                graph[u].push_back(v);
                indegree[v]++;
            }
        }

        // Topological sort to compute the prerequisites of each node
        // <O(n+n^3),O(n+n^2)>
        void topo_sort(vvi& prerequisites,int n){
            node_prerequisites.resize(n);
            std::queue<int> q;
            for(int node=0;node<n;++node){
                if(indegree[node]==0) q.push(node);
            }

            while(!q.empty()){
                int cur_node=q.front();
                q.pop();
    
                for(auto& ne: graph[cur_node]){
                    node_prerequisites[ne].insert(cur_node);
                    for(auto& node: node_prerequisites[cur_node]) node_prerequisites[ne].insert(node);
                    if(--indegree[ne]==0) q.push(ne); 
                }
            }
        }

        std::vector<bool> checkIfPrerequisite(int numCourses,vvi& prerequisites,vvi& queries){
            build_graph(prerequisites,numCourses);
            
            topo_sort(prerequisites,numCourses);
          
            // Process queries
            // <O(q.n),O(1)> 
            std::vector<bool> ans;
            for(auto& q: queries){
                int u=q[0],v=q[1];
                std::unordered_set<int> pre=node_prerequisites[v];
                ans.push_back(pre.find(u)!=pre.end());
            }

            return ans;
        }
};

/*
    7
    [[0,1],[1,4],[4,5],[0,3],[5,2],[3,6]]

    [[1,0],[0,1],[2,3],[4,5],[3,5],[1,5]]

    6
    [[0,1],[1,2],[2,3],[3,4],[3,5]]
    [[1,0],[0,1],[2,3],[4,5],[3,5],[1,5]]

    7
    [[2,3],[2,1],[2,0],[3,4],[3,6],[5,1],[5,0],[1,4],[1,0],[4,0],[0,6]]
    [[3,0],[6,4],[5,6],[2,6],[2,3],[5,6],[4,0],[2,6],[3,5],[5,3],[1,6],[1,0],[3,5],[6,5],[2,3],[3,0],[3,4],[3,4],[2,5],[0,3],[4,0],[6,4],[5,0],[6,5],[5,6],[6,5],[1,0],[3,4],[1,5],[1,4],[3,6],[0,1],[1,2],[5,1],[5,3],[5,3],[3,4],[5,4],[5,4],[5,3]]

*/
// @lc code=end
