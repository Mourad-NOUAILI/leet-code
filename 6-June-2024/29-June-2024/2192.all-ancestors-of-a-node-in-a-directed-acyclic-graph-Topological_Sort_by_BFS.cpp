/*
 * @lc app=leetcode id=2192 lang=cpp
 *
 * [2192] All Ancestors of a Node in a Directed Acyclic Graph
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Kahn's algorithm(Topological sort by BFS)
    Overall time complexity: O(E*n)
    Overall extra space complexity: O(E+n)
*/
class Solution {
    public:
        std::vector<int>* graph=nullptr;
        std::vector<std::vector<int>> ans;
    public:
        void build_graph(int n,std::vector<std::vector<int>>& edges){
            graph=new std::vector<int>[n];
            for(auto& edge: edges){
                graph[edge[0]].push_back(edge[1]);
            }
        }

        std::vector<int> merge(std::vector<int>& A,std::vector<int>& B){
            std::vector<int> merged;    
            int n=A.size(),m=B.size(),i=0,j=0;
            while(i<n&&j<m){
                if(A[i]<B[j]){
                    merged.push_back(A[i]);
                    i++;
                }
                else if(A[i]>B[j]){
                    merged.push_back(B[j]);
                    j++;
                }
                else {
                    merged.push_back(A[i]);
                    i++;
                    j++;
                }
            }
            while(i<n) {
                merged.push_back(A[i]);
                i++;
            }
            while(j<m) {
                merged.push_back(B[j]);
                j++;
            }

            return merged;
        }

        std::vector<std::vector<int>> getAncestors(int n, std::vector<std::vector<int>>& edges){
            build_graph(n,edges);

           std::vector<int> indegree(n,0);
           for(int node=0;node<n;++node){
                for(auto& u: graph[node]){
                    indegree[u]++;
                }
           }

           std::queue<int> q;
           for(int node=0;node<n;++node){
                if(indegree[node]==0) q.push(node);
           }

           std::unordered_map<int,std::vector<int>> ancestors;
           while(!q.empty()){
                int node=q.front();
                q.pop();

                for(auto& u: graph[node]){
                    indegree[u]--;
                   
                    // ancestors[u]=ancestors[u]+ancestors[node]+{node};
                    std::vector<int> tmp={node};
                    ancestors[u]=merge(ancestors[u],ancestors[node]);
                    ancestors[u]=merge(ancestors[u],tmp);

                    if(indegree[u]==0) q.push(u);
                }
           }

           for(int node=0;node<n;++node) ans.push_back(ancestors[node]);

           return ans;  
        }
    };
// @lc code=end