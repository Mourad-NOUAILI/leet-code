#include<bits/stdc++.h>

/*
    DFS
    Time compelxity: O(n+m)
    Space compelxity: O(n+m)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int,int> ii; 

class Solution {
    public:
        vvi build_adj_list(vvi& edges,int n){
            vvi adj(n);
            for(auto& edge: edges){
                int u=edge[0];
                int v=edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            return adj;
        }

        ii dfs(vvi& adj,int u,int par){
            int max_depth1=0,max_depth2=0,diameter=0;
            for(auto& v: adj[u]){
                if(v==par) continue;

                auto[subtree_diameter,depth]=dfs(adj,v,u);

                // Update the diameter of the subtree rooted by the current node `u`
                diameter=std::max(diameter,subtree_diameter);
                
                // Update the two largest depths from the current node `u`
                if(depth>max_depth1){
                    max_depth2=max_depth1;
                    max_depth1=depth;
                }
                else if(depth>max_depth2){
                    max_depth2=depth;
                }
            }

            // Update the diameter of the subtree rooted by the current node `u`
            diameter=std::max(diameter,max_depth1+max_depth2);

            // Return the diameter of the subtree rooted by the current node `u` and update its maximum depth 
            return {diameter,1+std::max(max_depth1,max_depth2)};
        }


        int minimumDiameterAfterMerge(vvi& edges1, vvi& edges2) {
            int n=edges1.size()+1;
            int m=edges2.size()+1;

            vvi adj1=build_adj_list(edges1,n);
            vvi adj2=build_adj_list(edges2,m);

            // Compute the diameter of the first subtree
            int diameter1=dfs(adj1,0,-1).first;

            // Compute the diameter of the second subtree
            int diameter2=dfs(adj2,0,-1).first;

            // Compute de diameter of the merged tree (tree1+tree2)
            int whole_diameter=std::ceil(diameter1/2.0)+std::ceil(diameter2/2.0)+1;

            // Return the maximum diameter of the two given trees and the merged tree.
            return std::max({diameter1,diameter2,whole_diameter});
        }
};