/*
    Dijkstra
    Time complexity: O(V+Q.(E log V))
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

        // Time complexity: O(E log V)
        // Space compelxity: O(V)
        int dijkstra(int start, int target){
            vi visited(target+1,false);
            vi distances(target+1,INT_MAX);
            distances[start]=0;
            std::priority_queue<ii,vii,std::greater<ii>> min_heap;
            min_heap.push({0,start});
            while(!min_heap.empty()){
                auto [dist,cur_node]=min_heap.top();
                min_heap.pop();
                if(visited[cur_node]) continue;
                visited[cur_node]=true;
                if(cur_node==target) return distances[target];
                for(auto& neighbor: graph[cur_node]){
                    if(distances[neighbor]>distances[cur_node]+1){
                        distances[neighbor]=distances[cur_node]+1;
                        min_heap.push({distances[neighbor],neighbor});
                    }
                }
            }
            return distances[target];
        }

        // Overall time complexity: O(V+Q.(E log V))
        // Overall space compelxity: O(V)
        vi shortestDistanceAfterQueries(int n, vvi& queries) {
            build_graph(n,queries);

            vi ans;

            for(auto& query: queries){
                int u=query[0];
                int v=query[1];
                graph[u].push_back(v);

                int shortest_path_lenght=dijkstra(0,n-1);
                ans.push_back(shortest_path_lenght);

            }
            return ans;
        }
};