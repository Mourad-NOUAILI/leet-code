/*
    BFS
    Time complexity: O(V+Q.(E+V))
    Space compelxity: O(V)
*/

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int,int> ii;
typedef std::vector<ii> vii;
class Solution{
    private:
        vvi graph;
    public:
        // Build the adjacency matrix of graph G(V,E)
        // Time compelxity: O(V)
        // Space compelxity: O(V)
        void build_graph(int n,vvi& edges){
            graph.resize(n);
            for(int i=0;i<n-1;++i){
                graph[i].push_back(i+1);
            }
        }
        
        // Time complexity: O(V+E)
        // Space compelxity: O(V)
        int bfs(int start, int target){
            vi visited(target+1,false);
            vi distances(target+1,INT_MAX);
            distances[0]=0;
            std::queue<int> q;
            q.push(0);
            int dist=0;
            while(!q.empty()){
                int cur_node=q.front();
                q.pop();

                if(cur_node==target) return distances[target];  

                if(visited[cur_node]) continue;
                visited[cur_node]=true;

                for(auto& neighbor: graph[cur_node]){
                    if(distances[neighbor]!=INT_MAX) continue;
                    distances[neighbor]=distances[cur_node]+1;
                    q.push(neighbor);
                }
            }
            return distances[target];
        }

        // Overall time complexity: O(V+m.(V+E))
        // Overall space compelxity: O(V)
        vi shortestDistanceAfterQueries(int n, vvi& queries) {
            build_graph(n,queries);

            vi ans;

            for(auto& query: queries){
                int u=query[0];
                int v=query[1];
                graph[u].push_back(v);

                int shortest_path_lenght=bfs(0,n-1);
                ans.push_back(shortest_path_lenght);

            }
            return ans;
        }
};