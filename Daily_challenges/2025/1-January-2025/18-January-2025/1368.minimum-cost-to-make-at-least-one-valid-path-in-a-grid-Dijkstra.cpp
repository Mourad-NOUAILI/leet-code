/*
 * @lc app=leetcode id=1368 lang=cpp
 *
 * [1368] Minimum Cost to Make at Least One Valid Path in a Grid
 */

// @lc code=start

/*
    Dijkstra
    Time complexity: O(mnlog(mn))
    Space complexity: O(2mn)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

typedef std::pair<int,int> ii;
typedef std::pair<int,ii> iii;
typedef std::vector<iii> viii;

class Solution {
    private:
        // Directions for movement: right, left, down, up
        vvi directions= {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int minCost(vvi& grid){
        int m=grid.size(),n=grid[0].size();

        vvi min_costs(m,vi(n,INT_MAX));
        min_costs[0][0]=0;

        std::priority_queue<iii,viii,std::greater<iii>> min_heap;
        min_heap.push({0,{0,0}});

        while(!min_heap.empty()){
            // Pick the cell with minimum cost
            auto[cur_cost,cur_cell]=min_heap.top();
            min_heap.pop();

            int cur_row=cur_cell.first;
            int cur_col=cur_cell.second;

            if(cur_row==m-1 && cur_col==n-1) return min_costs[m-1][n-1];
         
            for(int i=0;i<4;++i){
                vi dir=directions[i];
                int new_row=cur_row+dir[0];
                int new_col=cur_col+dir[1];
               
                if(new_row<0 || new_col<0 || new_row>m-1 || new_col>n-1) continue;

                // Update the current cost of the current cell
                // If we need to change directions add1 to the current cost
                int new_cost=cur_cost+(grid[cur_row][cur_col]!=(i+1));

                // Path relaxation: Update the cost if we found a better path
                if(min_costs[new_row][new_col]>new_cost){
                   min_costs[new_row][new_col]=new_cost;
                   min_heap.push({new_cost,{new_row,new_col}}); 
                }
            }
        }
        return min_costs[m-1][n-1];
    }
};
// @lc code=end

