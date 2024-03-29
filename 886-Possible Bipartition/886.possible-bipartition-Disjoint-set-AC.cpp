#include <bits/stdc++.h>
/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start
class Solution {
    private:
        std::vector<int> parent;
    public:
        int find(int p){
            int root = p;
            while(root != parent[root])
                root = parent[root];
                
            while (parent[p] != root){
                int next = parent[p];
                parent[p] = root;
                p = next;
            }

            return root;
        }

        void unify(int p,int q){
            int parent_p = find(p);
            int parent_q = find(q);

            if (parent_p != parent_q) parent[parent_q] = parent_p;
        }


        bool possibleBipartition(int n, std::vector<std::vector<int>>& dislikes) {
            // Make adjacency list
            std::vector<std::vector<int>> graph(n);
            int m = dislikes.size();
            for(int i = 0 ; i < m ; ++i){
                int u = dislikes[i][0];
                int v = dislikes[i][1];
                u--;
                v--;
                graph[u].push_back(v);
                graph[v].push_back(u);
            }


            // Disjoint sets
            for (int i = 0 ; i < n ; ++i) {
                parent.push_back(i);
            }
            for (int u = 0 ; u < n ; ++u){    
                std::vector<int> nodes = graph[u];
                for (auto v : nodes){
                    int v0 = nodes[0];
                    if (find(u) == find(v)) return false;
                    unify(v,v0);
                }
            }
            return true;
        }
};
// @lc code=end










// 3\n[[1,2],[1,3]]\n --> true (AC)

// 3\n[[1,2],[1,3],[2,3]]\n --> false (AC)

// 4\n[[1,2],[1,3],[1,4]]\n --> true (AC)

// 5\n[[1,2],[1,5],[2,3],[3,4],[4,5]]\n --> false (AC)

// 7\n[[1,3],[1,4],[2,6],[2,7],[5,6]]\n --> true (AC)

// 7\n[[1,3],[1,4],[2,6],[2,7],[5,6],[6,7]]\n --> true (AC)
