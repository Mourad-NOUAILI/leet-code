/*
    Circular array+Dynamic sliding window
    Time compelxity: O(2n)
    Space complexity:O(1)
*/

class Solution {
public:
    int numberOfAlternatingGroups(std::vector<int>& colors, int k){
        
        int n=colors.size();

        int ans=0;

        int i = 0; // start of the window
        int j = 0; // end of the window
        
        // Expand the size to simulate circular array
        while(j<n+k-2){
            if(colors[j%n]==colors[(j+1)%n]){
                i=j+1;
                j=i;
                continue;
            }

            j++;

            if(j-i+1==k){
                ans++;
                i++;
            }
            
        }

        return ans;
    }
};