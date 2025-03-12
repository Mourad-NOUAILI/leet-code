/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    BFS
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

        std::map<vvi,bool> visited;

        class Puzzle{
            public:
                vvi board;

                // Position of empty tile in the cureent state
                int x_empty_tile;
                int y_empty_tile;

                int steps; // Number of steps to reach the current state 
            public:
                Puzzle(vvi board,int x_empty_tile,int y_empty_tile,int steps): 
                    board(board),
                    x_empty_tile(x_empty_tile),
                    y_empty_tile(y_empty_tile),
                    steps(steps) {}
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


        
        int bfs(Puzzle* puzzle){
            std::queue<Puzzle*>q;
            q.push(puzzle);

            std::map<vvi, bool> visited;

            while(!q.empty()){
                Puzzle* current_puzzle=q.front();
                q.pop();

                vvi current_board = current_puzzle->board;

                if(current_board==target) return current_puzzle->steps;

                // State visited, no need to fo it again
                if (visited[current_board]) continue;
                visited[current_board] = true;

                // Move empty tile in four directions
                for (auto& dir: directions){
                    int x=current_puzzle->x_empty_tile + dir[0];
                    int y=current_puzzle->y_empty_tile + dir[1];

                    if ( x < 0 || x >= m || y < 0 || y >= n) continue;

                    vvi next_board = current_board;
                    int tmp = next_board[x][y];
                    next_board[x][y] = 0;
                    next_board[current_puzzle->x_empty_tile][current_puzzle->y_empty_tile] = tmp;

                    // If the next state is not visited,
                    if (!visited[next_board]){

                        // Create next puzzle
                        Puzzle* next_puzzle = new Puzzle(next_board, x, y,current_puzzle->steps+1);

                        // Add it to the queue
                        q.push(next_puzzle);
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

            // Create the puzzle
            Puzzle* puzzle=new Puzzle(board,zero_pos.first,zero_pos.second,0);

            return bfs(puzzle);
        }
};
// @lc code=end

int main(){
    vvi board={{4,1,2},{5,0,3}};
    Solution sol=Solution();
    std::cout<<sol.slidingPuzzle(board)<<'\n';
    return 0;
}