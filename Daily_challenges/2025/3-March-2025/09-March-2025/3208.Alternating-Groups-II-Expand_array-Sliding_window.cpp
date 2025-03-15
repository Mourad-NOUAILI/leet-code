/*
    Expand array+Dynamic sliding window
    Time compelxity: O(2n)
    Space complexity:O(n)
*/

class Solution {
public:
    int numberOfAlternatingGroups(std::vector<int>& colors, int k){
        // Expand the given by the elements in range[0,k-2]
        // to simulate the circularity
        for(int i=0;i<k-1;++i) colors.push_back(colors[i]);
        
        int n=colors.size();

        int ans=0;

        int i=0; // start of the window
        int j=0; // end of the window
        
        while(j<n-1){
            // If the last tile in the actual window have the same
            // color with the next tile
            if(colors[j]==colors[j+1]){
                // Start new window from the next tile
                i=j+1;
                j=i;
                continue;
            }
            
            // Otherwise, expand the window
            j++;
            
            // If the length of the window reaches k
            if(j-i+1==k){
                ans++; // Count it in the answer
                i++; // Shrink the window from the left
            }
        }

        return ans;
    }
};