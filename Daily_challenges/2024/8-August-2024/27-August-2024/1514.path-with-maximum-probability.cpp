/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Anti Dijkstra
    Time complexity: O(m+nm)=O(nm)
    Space complexity: O(n+n+nm+2n)=O(n+nm)=O(nm)
    n: #nodes
    m: #edges
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

typedef std::pair<double,int> di;
typedef std::vector<di> vdi;
typedef std::vector<vdi> vvdi;

typedef std::vector<double> vd;

class Solution {
    vvdi graph;
    public:
        void build_graph(int n,vvi& edges, vd& succProb){
            int m=edges.size();
            graph.resize(n);
            for(int i=0;i<m;++i){
                auto edge=edges[i];
                int u= edge[0];
                int v= edge[1];
                double w=succProb[i];
                graph[u].push_back({w,v});
                graph[v].push_back({w,u});
            }
        }

        double anti_dijkstra(int n,int start, int target){
            vd ans(n,INT_MIN);
            ans[start]=1;
            vi visited(n,false);
            std::priority_queue<di,vdi,std::greater<di>> min_heap;
            min_heap.push({0,start});
            while(!min_heap.empty()){
                di cur=min_heap.top();
                min_heap.pop();
                int u=cur.second;
                if(visited[u]) continue;
                visited[u]=true;
                if(u==target) return ans[u];
                for(auto& edge: graph[u]){
                    int v=edge.second;
                    double w=edge.first;
                    if(ans[v]<=ans[u]*w){
                        ans[v]=ans[u]*w;
                        min_heap.push({1.0/ans[v],v});
                    }
                }
            }
            return ans[target]!=INT_MIN?ans[target]:0;
        }

        double maxProbability(int n, vvi& edges, vd& succProb, int start_node, int end_node){
            build_graph(n,edges,succProb);
            return anti_dijkstra(n,start_node,end_node);
        }
};
// @lc code=end

