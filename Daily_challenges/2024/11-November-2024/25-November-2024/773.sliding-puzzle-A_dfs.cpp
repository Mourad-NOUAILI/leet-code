/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    DFS
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

        std::map<vvi,int> visited;

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


        
        void dfs(Puzzle* puzzle){
            if(visited.find(puzzle->board)!=visited.end() && visited[puzzle->board]<=puzzle->steps) return;
            visited[puzzle->board]=puzzle->steps;

            for (auto& dir: directions){
                int x=puzzle->x_empty_tile + dir[0];
                int y=puzzle->y_empty_tile + dir[1];

                if ( x < 0 || x >= m || y < 0 || y >= n) continue;

                vvi next_board = puzzle->board;
                int tmp = next_board[x][y];
                next_board[x][y] = 0;
                next_board[puzzle->x_empty_tile][puzzle->y_empty_tile] = tmp;

            
                Puzzle* next_puzzle = new Puzzle(next_board, x, y,puzzle->steps+1);
                
                dfs(next_puzzle);
            }
        }

        int slidingPuzzle(vvi& board){
            m=board.size();
            n=board[0].size();

            // Find position of empty tile
            std::pair<int,int> zero_pos=find_zero_pos(board);

            // Create the puzzle
            Puzzle* puzzle=new Puzzle(board,zero_pos.first,zero_pos.second,0);

            dfs(puzzle);

            return visited.find(target)!=visited.end()?visited[target]:-1;
        }
};
// @lc code=end

int main(){
    srand(time(0));
    int n=100000;
    vvi board(n,vi(n));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            board[i][j]=rand() % 1000000 + (-100000);
        }
    }
    
    long long s=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            s+=board[i][j];
        }
    }
    std::cout<<s<<'\n';
    /*Solution sol=Solution();
    std::cout<<sol.slidingPuzzle(board)<<'\n';*/
    return 0;
}