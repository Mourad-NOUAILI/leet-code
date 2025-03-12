/*
 * @lc app=leetcode id=2658 lang=cpp
 *
 * [2658] Maximum Number of Fish in a Grid
 */

// @lc code=start
/*
    DSU
    Time complexity: O(mnα(mn))
    Space complexity: O(mn)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int,int> ii;
class DSU{
    public:
        vi parent;
        vi group;
        vi fishes;
        int _N,n,m;
        vvi grid;
    public:
        DSU(int _N,int m,int n,vvi& grid){
            this->_N=_N;
            this->m=m;
            this->n=n;
            this->grid=grid;

            parent.resize(_N);
            group.resize(_N,1);
            fishes.resize(_N,0);

            for(int i=0;i<_N;++i) {
                parent[i]=i;
                fishes[i]=grid[i/n][i%n];
            }
        }

        int find(int p){
            if(p==parent[p]) return p;
            return parent[p]=find(parent[p]);
        }

        void unify(int p,int q){
            int parent_p=find(p);
            int parent_q=find(q);
            if(parent_p==parent_q) return;
        
            if(group[parent_p]<group[parent_q]){
                group[parent_q]+=group[parent_p];
                fishes[parent_q]+=fishes[parent_p];
                group[parent_p]=1;
                parent[parent_p]=parent_q;
                
            }
            else{
                group[parent_p]+=group[parent_q];
                fishes[parent_p]+=fishes[parent_q];
                group[parent_q]=1;
                parent[parent_q]=parent_p;
            }
        }
};

class Solution {
    public:
        int cell_id(int row,int col,int n){
            return row*n+col;
        }

         bool is_in_the_grid(int row, int col, int m, int n){
            return (row >=0 && row < m && col >= 0 && col < n);
        }

        
        int findMaxFish(vvi& grid){
            int m=grid.size();
            int n=grid[0].size();

            DSU dsu=DSU(m*n,m,n,grid);
            
            for(int i=0;i<m;++i){
                for(int j=0;j<n;++j){
                    if(grid[i][j]==0) continue;
                    int cur=cell_id(i,j,n);
                    int right=cell_id(i,j+1,n);
                    int left=cell_id(i,j-1,n);
                    int up=cell_id(i-1,j,n);
                    int down=cell_id(i+1,j,n);
                    
                    if (is_in_the_grid(i,j+1,m,n) && grid[i][j+1]) dsu.unify(cur,right);
                    if (is_in_the_grid(i,j-1,m,n) && grid[i][j-1]) dsu.unify(cur,left);
                    if (is_in_the_grid(i-1,j,m,n) && grid[i-1][j]) dsu.unify(cur,up);
                    if (is_in_the_grid(i+1,j,m,n) && grid[i+1][j]) dsu.unify(cur,down);
                }
            }
            //for(auto& e: dsu.fishes) std::cout<<e<<' ';
            int ans=*std::max_element(dsu.fishes.begin(),dsu.fishes.end());
            
            return ans;
        }
};

// @lc code=end

