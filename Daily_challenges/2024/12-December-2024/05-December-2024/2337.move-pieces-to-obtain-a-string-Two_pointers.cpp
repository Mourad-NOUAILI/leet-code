/*
 * @lc app=leetcode id=2337 lang=cpp
 *
 * [2337] Move Pieces to Obtain a String
 */

// @lc code=start
/*
    Two pointers
    Time compelxity: O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        bool canChange(std::string start, std::string target) {
            int n=start.size();
            int i=0; // Pointer on start
            int j=0; // Pointer on target
            while(i<n || j<n){
                // Skip underscores in start
                while(i<n && start[i]=='_') i++;

                // Skip underscores in target
                while(j<n && target[j]=='_') j++;

                // If both strings are exhausted
                if(i==n && j==n) return true;

                // If just one string is exhausted
                if(i==n || j==n) return false;

                // Check if the pieces match and follow movement rules
                if(start[i]!=target[j] || 
                    start[i]=='L' && i<j ||
                    start[i]=='R' && i>j) return false;
                i++;
                j++;
            }
            return true;
        }
};
// @lc code=end

