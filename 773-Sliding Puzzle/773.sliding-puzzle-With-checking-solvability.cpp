// @before-stub-for-debug-begin
#include <bits/stdc++.h>



// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

// @lc code=start
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int,int> ii;

class Puzzle {
    private:
        vvi grid;
        int x_empty_tile;
        int y_empty_tile;
        int steps_from_start;
        int misplaced_tiles;
        int coast;

    public:
        Puzzle(vvi grid,
            int x_empty_tile,
            int y_empty_tile,
            int steps_from_start,
            int misplaced_tiles,
            int coast): grid(grid),
                        x_empty_tile(x_empty_tile),
                        y_empty_tile(y_empty_tile),
                        steps_from_start(steps_from_start),
                        misplaced_tiles(misplaced_tiles),
                        coast(coast) {}
            
            vvi get_grid(){return grid;}
            int get_x_empty_tile(){return x_empty_tile;}
            int get_y_empty_tile(){return y_empty_tile;}
            int get_steps_from_start(){return steps_from_start;}
            int get_misplaced_tiles() {return misplaced_tiles;}
};

typedef std::pair<int,Puzzle*> iP;

class Solution {
public:
    // Time complexity: O(nxm)
    // Space complexity: O(nxm)
    bool is_solvable(vi v){
        int nb_inversions = 0;
        for(int i = 0 ; i < 4 ; ++i){
            for(int j = i+1 ; j < 5 ; ++j){
                if (v[i] > v[j]) nb_inversions++;
            }
        }
        return nb_inversions % 2 == 0;
    }

    // Time complexity: O(nxm)
    // Space complexity: O(nxm)
    int heuristic(vvi b){
        vvi goal{
            {1,2,3},
            {4,5,0}
        };

        int h = 0;
        for (int i = 0 ; i < 2 ; ++i){
            for(int j = 0 ; j < 3 ; ++j){
                if (b[i][j] != goal[i][j]) h++;
            }
        }
        return h;
    }

    // Time complexity: O(Q*(logQ*logV*4*(n*m*logQ))) = O(4Qnm(logQ)²logV)
    // Space complexity: O(Q*nm+Q) + O(V*nm+V)
    // Q: size of the priority_queue, V: size of the visited map
    int a_star(Puzzle* puzzle){
        std::map<vvi,bool> visited;

        std::priority_queue<iP,std::vector<iP>,std::greater<iP>> q;
        q.push({0,puzzle});

        ii moves[4] = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            Puzzle* cur_puzzle = q.top().second;
            q.pop();

            vvi cur_grid = cur_puzzle->get_grid();

            if (visited[cur_grid]) continue;
            visited[cur_grid] = true;

            if (cur_puzzle->get_misplaced_tiles() == 0) return cur_puzzle->get_steps_from_start() ;

            for (int i = 0 ; i < 4 ; ++i){
                int row = cur_puzzle->get_x_empty_tile() + moves[i].first;
                int col = cur_puzzle->get_y_empty_tile() + moves[i].second;

                if (row < 0 || row >= 2 || col < 0 || col >= 3) continue;

                vvi next_grid = cur_grid;
                int tmp = next_grid[row][col];
                next_grid[row][col] = 0;
                next_grid[cur_puzzle->get_x_empty_tile()][cur_puzzle->get_y_empty_tile()] = tmp;

                if (!visited[next_grid]){
                    int f = cur_puzzle->get_steps_from_start() + 1;
                    int h = heuristic(next_grid);
                    int coast = f + h;

                    Puzzle* next_puzzle = new Puzzle(next_grid,row,col,f,h,coast);

                    q.push({coast,next_puzzle});
                }
            }

        }
        return -1; // Never reached 
    }

    // Time complexity: O(4Qnm(logQ)²logV) + O(nm) + O(nm) + O(nm) = O(Qnm(logQ)²logV)
    // Amortized: O(nm)
    // Space complexity: O(nm) + O(nm) + O(Q*nm+Q) + O(V*nm+V)
    // Amortized: O(nm)
    // Q: size of the priority_queue, V: size of the visited map
    int slidingPuzzle(vvi board) {
        vi v;
        int x_empty_tile , y_empty_tile;
        for (int i = 0 ; i < 2 ; ++i){
            for(int j = 0 ; j < 3 ; ++j){
                if (board[i][j] != 0) v.push_back(board[i][j]);
                else {
                    x_empty_tile = i;
                    y_empty_tile = j;
                }
            }
        }

        int h = heuristic(board);

        Puzzle* p0 = new Puzzle(board,x_empty_tile,y_empty_tile,0,h,0+h);
        return is_solvable(v)?a_star(p0):-1;
    }
};
// @lc code=end