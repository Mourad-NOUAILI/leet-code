/*
 * @lc app=leetcode id=2290 lang=cpp
 *
 * [2290] Minimum Obstacle Removal to Reach Corner
 */

// @lc code=start
/*
    Dijkstra
    Time complexity: O(2m.n+m.n log(m.n)) = O(m.n log(m.n))
    Space complexity: O(3mn))=O(m.n)
*/

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int,int> ii;
typedef std::pair<int,ii> iii;
typedef std::vector<iii> viii;

class Solution{
    private:
        int m,n;
    public:
        int dijkstra(vvi& grid){
            vvi directions={{-1,0},{1,0},{0,1},{0,-1}};
            vvi visited(m,vi(n,false));
            vvi distances(m,vi(n,INT_MAX));
            distances[0][0]=0;
            std::priority_queue<iii,viii,std::greater<iii>> min_heap;
            min_heap.push({0,{0,0}});
            while(!min_heap.empty()){
                auto[d,cell]=min_heap.top();
                min_heap.pop();
                int i=cell.first;
                int j=cell.second;
                if(i==m-1 && j==n-1) return distances[m-1][n-1];
                if(visited[i][j]) continue;
                visited[i][j]=true;
                for(auto& dir: directions){
                    int x=i+dir[0];
                    int y=j+dir[1];
                    if(x<0 || x>m-1 || y<0 || y>n-1) continue;
                    int w=grid[x][y]==0?0:1;
                    if(distances[x][y]>distances[i][j]+w){
                        distances[x][y]=distances[i][j]+w;
                        min_heap.push({distances[x][y],{x,y}});
                    }
                }
            }
            return distances[m-1][n-1];
        }

        int minimumObstacles(vvi& grid){
            m=grid.size();
            n=grid[0].size();
            return dijkstra(grid);
        }
};
// @lc code=end

