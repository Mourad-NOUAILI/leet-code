/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Union Find
    Time complexity:
        nested for loops: O(mn)
        DSU: O(α(mn))
        Overall: O(α(mn)mn),  
        where α is the inverse Ackermann function
    Space complexity:
        Recurion stack calls: O(mn)
*/

typedef vector<int> vi;
typedef vector<vi> vvi;

class DSU{
    public:
        vi parent;
    public:
        DSU(int _N){
            parent.resize(_N);
            for(int i=0;i<_N;++i) parent[i]=i;
        }

        int find(int p){
            if(p==parent[p]) return p;
            return parent[p]=find(parent[p]); // Path compression
        }

        int unify(int p,int q){
            int parent_p=find(p);
            int parent_q=find(q);
            if(parent_p==parent_q) return 0;
            parent[parent_q]=parent_p;
            return 1;
        }
};

class Solution {
    public:
        int m; // Number of rows
        int n; // Number of columns
     
    public:
        int cell_id(int i,int j){return i*n+j;}

        int countSubIslands(vvi& grid1, vvi& grid2) {
            m=grid1.size();
            n=grid1[0].size();

            int _N=m*n;

            DSU dsu=DSU(_N+1);

            int ans=0;
            for(int i=0;i<m;++i){
                for(int j=0;j<n;++j){

                    if(grid2[i][j]==0) continue;

                    int cur=cell_id(i,j);
                    int down=cell_id(i+1,j);
                    int right=cell_id(i,j+1);
                    
                    ans++;

                    if(grid1[i][j]==0) ans-=dsu.unify(cur,_N);
                    if(i+1<m && grid2[i+1][j]==1) ans-=dsu.unify(cur,down);
                    if(j+1<n && grid2[i][j+1]==1) ans-=dsu.unify(cur,right);
                }
            }

            return ans;
        }
};
// @lc code=end

