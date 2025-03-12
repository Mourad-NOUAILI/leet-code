/*
 * @lc app=leetcode id=1368 lang=cpp
 *
 * [1368] Minimum Cost to Make at Least One Valid Path in a Grid
 */

// @lc code=start
/*
    0/1 BFS
    Time complexity: O(mn)
    Space complexity: O(2mn)
*/

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int,int> ii;
class Solution {
    private:
        // Directions for movement: right, left, down, up
        vvi directions= {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int minCost(vvi& grid){
        int m=grid.size(),n=grid[0].size();

        vvi min_costs(m,vi(n,INT_MAX));
        min_costs[0][0]=0;
    
       
        std::deque<ii> deq; // {row,col}
        deq.push_back({0,0});

        while (!deq.empty()){
            auto [cur_row,cur_col]=deq.front();
            deq.pop_front();
            
            if(cur_row==m-1 && cur_col==n-1) return min_costs[m-1][n-1];
            
            for (int i=0;i<4;++i){
                vi dir=directions[i];
                int new_row=cur_row+dir[0];
                int new_col=cur_col+dir[1];
               
                if(new_row<0 || new_col<0 || new_row>m-1 || new_col>n-1) continue;
                
                // Compute the cost of the current cell
                // 1: if we need to change direction
                // 0: otherwise
                int cost=grid[cur_row][cur_col]!=(i+1);
		
		// If the cost at the new cell is greater than the cost of the current
		// cell + the cost of the current cell, then update the cost of the new cell
                if(min_costs[new_row][new_col]>min_costs[cur_row][cur_col]+cost){
                    min_costs[new_row][new_col]=min_costs[cur_row][cur_col]+cost;
                    
                    // If the we need to change direction from the current cell to
                    // reach the new cell, push the new cell to the back to deal with it later
                    if(cost==1) deq.push_back({new_row,new_col});
                    // Otherwisen push it to the front to deal with it as soon as possible
                    else deq.push_front({new_row,new_col}); 
                }
            }
        }
     
        return min_costs[m-1][n-1];
    }
};
// @lc code=end

