/*
 * @lc app=leetcode id=1769 lang=cpp
 *
 * [1769] Minimum Number of Operations to Move All Balls to Each Box
 */

// @lc code=start
/*
    Brute force
    Time compelxity: O(n^2)
    Space complexity: O(1)
*/
typedef std::vector<int> vi;

class Solution {
    public:
        vi minOperations(std::string boxes){
            int n=boxes.size();
            vi ans;
            // For each box
            for(int i=0;i<n;++i){
                // Compute the number of steps to get the 1 at position j
                int cnt=0;
                for(int j=0;j<n;++j){
                    if(boxes[j]=='1') cnt+=abs(i-j);
                }
                // Add the result to the answer
                ans.push_back(cnt);
            }
            return ans;
        }
};
// @lc code=end

