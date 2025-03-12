/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

// @lc code=start

/*
    A*
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution{
    private:
        int m; // Row
        int n; // Cols

        vvi directions={ 
            {-1,0}, // Up
            {1,0}, // Down
            {0,-1}, // Left
            {0,1} // Right;
        };

        vvi target={{1,2,3},{4,5,0}};

        class Puzzle{
            public:
                vvi board;

                // Position of empty tile in the cureent state
                int x_empty_tile;
                int y_empty_tile;

                int steps; // Number of steps to reach the current state 
                int h; // Heuristic value: Number of misplaced tiles
                int coast; // The coast to get target state from an actual stata.
            public:
                Puzzle(vvi board,int x_empty_tile,int y_empty_tile,int steps,int h, int coast): 
                    board(board),
                    x_empty_tile(x_empty_tile),
                    y_empty_tile(y_empty_tile),
                    steps(steps),
                    h(h),
                    coast(coast) {}
        };

    public:
        // Find the position of the empty tile (0)
        std::pair<int,int> find_zero_pos(vvi& board){
            for(int i=0;i<m;++i){
                for(int j=0;j<n;++j){
                    if(board[i][j]==0) return {i,j}; 
                }
            }
            return {-1,-1}; // Never reached
        }

        // Heuristic function
        // #misplaced tiles in actual state by comparing with the target state.
        int heuristic(vvi& board){
            int h=0;
            int tile=1;
            for (int i=0;i<m;++i){
                for (int j=0;j<n;++j){
                    if ( (i!=m-1 || j!=n-1) &&board[i][j]!=tile) h++;
                    tile++;
                }
            }
            return h+int(board[m-1][n-1]!=0);
        }

        // A* algorithm
        int a_star(Puzzle* puzzle){
            // Use min heap to get the minimum coast
            std::priority_queue<std::pair<int,Puzzle*>,std::vector<std::pair<int,Puzzle*>>, std::greater<std::pair<int,Puzzle*>>> min_heap;
            
            // Push initial state to the min heap
            min_heap.push({puzzle->coast, puzzle});

            std::map<vvi,bool> visited;

            while (!min_heap.empty()){
                // Get the puzzle with the minimum coast
                Puzzle* current_puzzle=min_heap.top().second;
                min_heap.pop();

                vvi current_board=current_puzzle->board;

                // If number of misplaced tiles is equal to 0, means we reached the target
                // then return the number of steps 
                if (current_puzzle->h==0) return current_puzzle->steps;

                // if the board's state is visited, no need to continue with it
                if (visited[current_board]) continue;

                // If not visited, mark it as visited
                visited[current_board]=true;

                // Move empty tile in four directions
                for (auto& dir: directions){
                    int x=current_puzzle->x_empty_tile + dir[0];
                    int y=current_puzzle->y_empty_tile + dir[1];

                    if ( x<0 || x>=m || y<0 || y>=n) continue;

                    // Get next state
                    vvi next_board=current_board;
                    int tmp=next_board[x][y];
                    next_board[x][y]=0;
                    next_board[current_puzzle->x_empty_tile][current_puzzle->y_empty_tile]=tmp;

                    // If the next state is not visited, 
                    if (!visited[next_board]){
                        int f=current_puzzle->steps+1; // Add one step to the current state 
                        int h=heuristic(next_board); // Determine the heuristic value of the next state
                        int coast=f+h; // Compute the coast to go from current state to next state

                        // Create next puzzle
                        Puzzle* next_puzzle=new Puzzle(next_board,x,y,f,h,coast);

                        // Add it to min heap
                        min_heap.push({coast,next_puzzle});
                    }

                }
            }

            return -1; // If target not reached at all
        }

        int slidingPuzzle(vvi& board){
            m=board.size();
            n=board[0].size();

            // Find position of empty tile
            std::pair<int,int> zero_pos=find_zero_pos(board);
            
            // Compute heuristic value
            int h0=heuristic(board);

            // Create the puzzle
            Puzzle* puzzle=new Puzzle(board,zero_pos.first,zero_pos.second,0,h0,0+h0);

            return a_star(puzzle);
        }
};
// @lc code=end

