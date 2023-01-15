#include <bits/stdc++.h>
/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start
class Solution {
    private:
        std::vector<int> group;
    public:
        int find(int p){
            int root = p;
            while(root != group[root])
                root = group[root];
                
            while (p != root){
                int next = group[p];
                group[p] = root;
                p = next;
            }

            return root;
        }

        void unify(int p,int q){
            int group_p = find(p);
            int group_q = find(q);

            if (group_p == group_q) return;
            group[group_p] = group_q;
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

            // Step #1: each person in a group by itself
            for (int i = 0 ; i < n ; ++i) {
                group.push_back(i);
            }
            
            // Step #2: try to bipartite
            for (int v = 0 ; v < n ; ++v){    
                std::vector<int> nodes = graph[v];
                int fisrt_met = nodes[0]; for (auto u : nodes){
                    if (find(v) == find(u)) return false;
                    unify(u,fisrt_met);
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