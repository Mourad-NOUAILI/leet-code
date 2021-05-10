#include <bits/stdc++.h>

using namespace std;

int leastBricks(vector<vector<long>> wall) {
        long wall_height = wall.size();

        map<long, int> map;
        int max_num_holes = 0;
        for (auto row: wall) {
            long x = 0;
            for (int j = 0; j < row.size()-1; ++j) {
                x += row[j];
                map.insert({x, map[x]++});
                max_num_holes = max(max_num_holes, map[x]);
            }
        }
        
       
        return wall.size() - max_num_holes;
}


int main() {
	
	vector<vector<long>> wall =	{ 
									{1,2,2,1},
									{3,1,2},
									{1,3,2},
									{2,4},
									{3,1,2},
									{1,3,1,1}
								};
    
    /*vector<vector<long>> wall =	{ 
									{7,1,1,1},{1,4,2,3},{7,3}
								};*/
    
   /* vector<vector<long>> wall =	{ 
									{2,1}, {1,2}
								};*/
        
        
cout << leastBricks(wall) << "\n";
return 0;
}
