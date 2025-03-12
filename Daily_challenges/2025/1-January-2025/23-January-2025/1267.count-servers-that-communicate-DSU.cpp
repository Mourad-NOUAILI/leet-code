/*
 * @lc app=leetcode id=1267 lang=cpp
 *
 * [1267] Count Servers that Communicate
 */

// @lc code=start

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int,int> ii;

class DSU{
    public:
        vi parent;
        vi group;
    public:
        DSU(int n){
            group.resize(n,1);
            parent.resize(n);
            std::iota(parent.begin(),parent.end(),0);
        }
        int find(int p){
            if(p==parent[p]) return p;
            return parent[p]=find(parent[p]);
        }
        int unify(int p,int q){
            int parent_p=find(p);
            int parent_q=find(q);
            if(parent_p==parent_q) return false;
            if(group[parent_p]<group[parent_q]){
                group[parent_q]+=group[parent_p];
                group[parent_p]=1;
                parent[parent_p]=parent_q;
            }
            else{
                group[parent_p]+=group[parent_q];
                group[parent_q]=1;
                parent[parent_q]=parent_p;
            }
            return true;
        }
};

class Solution {
    public:
        int countServers(vvi& grid){
            int m=grid.size();
            int n=grid[0].size();

            DSU dsu=DSU(m+n);
            
            // Iterate over the grid and group all servers in same row and column
            int cnt_unify=0,cnt_already_unified=0;
            for(int row=0;row<m;++row){
                for(int col=0;col<n;++col){
                    if(grid[row][col]==1){
                        if(dsu.unify(row,col+m)) cnt_unify++;
                        else cnt_already_unified++;
                    }
                }
            }
            
            // Count isolate servers
            int isolate_servers=0;
            for(auto&g: dsu.group) isolate_servers+=(g==2);

            return cnt_unify+cnt_already_unified-isolate_servers;
          
        }
};
// @lc code=end

