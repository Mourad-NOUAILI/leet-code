/*
 * @lc app=leetcode id=2290 lang=cpp
 *
 * [2290] Minimum Obstacle Removal to Reach Corner
 */

// @lc code=start
/*
    A*
    Time complexity: O(m.n+m.n log(m.n))
    Space complexity: O(2mn)
*/

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int,int> ii;
typedef std::pair<int,ii> iii;
typedef std::vector<iii> viii;
class Solution{
    private:
        int m,n;
        // Create class cell
        class Cell{
            public:
                int row,col;
                int cost; // Cost the reach the cell at (row,col)
            public:
                Cell(int row,int col,int cost):
                    row(row),
                    col(col),
                    cost(cost) {}
        };
    public:
        // Using A* to prioritize the cell with minimum cost.
        // The cost of a cell is the number of removed walls to reach that cell.
        int a_star(vvi& grid,Cell* cell){
            vvi directions={{-1,0},{1,0},{0,1},{0,-1}};
            vvi visited(m,vi(n,false));
         
            std::priority_queue<std::pair<int,Cell*>,
                                    std::vector<std::pair<int,Cell*>>,
                                    std::greater<std::pair<int,Cell*>>> min_heap;
            min_heap.push({0,cell});

            while(!min_heap.empty()){
                // Pick the cell with minimum cost
                Cell* cell=min_heap.top().second;
                min_heap.pop();

                // If we reach the destination, return its cost
                // which is the number of removed walls to reach it
                if(cell->row==m-1 && cell->col==n-1) return cell->cost;

                if(visited[cell->row][cell->col]) continue;
                visited[cell->row][cell->col]=true;

                for(auto& dir: directions){
                    int x=cell->row+dir[0];
                    int y=cell->col+dir[1];
                    if(x<0 || x>m-1 || y<0 || y>n-1) continue;
                    if(!visited[x][y]){
                        // New cost = f+h
                        // f: cost of current cell
                        // h: 0, if no wall to remove
                        //1, if there is a wall to remove 
                        int f=cell->cost;
                        int h=grid[x][y];
                        int cost=f+h;

                        // Add the new cell to the min heap
                        Cell* next_cell=new Cell(x,y,cost);
                        min_heap.push({h,next_cell});
                    }
                }
            }
            return -1;
        }

        int minimumObstacles(vvi& grid){
            m=grid.size();
            n=grid[0].size();
            Cell* cell=new Cell(0,0,0);
            return a_star(grid,cell);
        }
};
// @lc code=end

