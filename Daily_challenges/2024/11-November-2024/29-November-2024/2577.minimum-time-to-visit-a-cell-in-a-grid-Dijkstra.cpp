/*
 * @lc app=leetcode id=2577 lang=cpp
 *
 * [2577] Minimum Time to Visit a Cell In a Grid
 */

// @lc code=start

/*
    Modified Dijkstra
    Time complexity: O(m.n.log(m.n))
    Space complexity: O(m.n)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int,int> ii;
typedef std::pair<int,ii> iii;
typedef std::vector<iii> viii;

class Solution {
    private:
        int m,n;
    public:
        int dijkstra(vvi& grid){
            vvi directions={{-1,0},{1,0},{0,-1},{0,1}};

            vvi visited(m,vi(n,false));

            std::priority_queue<iii,viii,std::greater<iii>> min_heap;
            min_heap.push({0,{0,0}});

            while(!min_heap.empty()){
                auto [cur_time,cur_cell]=min_heap.top();
                min_heap.pop();

                int i=cur_cell.first;
                int j=cur_cell.second;

                if(i==m-1 && j==n-1) return cur_time;

                if(visited[i][j]) continue;
                visited[i][j]=true;

                for(auto& dir: directions){
                    int x=i+dir[0];
                    int y=j+dir[1];
                    if(x<0 || x>m-1 || y<0 || y>n-1) continue;
                    
                    int needed_time; // Needed time to enter cell(x,y)
                    // If we are able to enter next cell(x,y)
                    if(cur_time>=grid[x][y]) needed_time=cur_time+1;
                    
                    // Otherwise, (cur_time<grid[x][y], we need to wait until, we be
                    // able to reach cell(x,y)
                    // Move back and forth between cell(i,j) and cell(x,y)
                    else{
                        // Time we need to "waste" to move to next cell (x,y) 
                        int wasted_time=(grid[x][y]-cur_time)%2==0?1:0;
                       
                        needed_time=grid[x][y]+wasted_time;
                    }
                    min_heap.push({needed_time,{x,y}});
                }
            }
            return -1; // Never reached 
        }

        int minimumTime(vvi& grid){
            // If from (0,0) we can't move to any cell
            // because current time=1, and values of grid[0][1]>1
            // and grid[1][0]>1
            if(grid[0][1]>1 && grid[1][0]>1) return -1;

            // Otherwise, we have an answer
            m=grid.size();
            n=grid[0].size();

            return dijkstra(grid);
        }
};
// @lc code=end

