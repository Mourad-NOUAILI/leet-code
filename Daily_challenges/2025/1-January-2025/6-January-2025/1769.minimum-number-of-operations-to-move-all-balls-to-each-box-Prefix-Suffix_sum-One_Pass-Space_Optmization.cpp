/*
 * @lc app=leetcode id=1769 lang=cpp
 *
 * [1769] Minimum Number of Operations to Move All Balls to Each Box
 */

// @lc code=start


/*
    Prefix/Suffix sum: One passe and space optimization
    Time complexity: O(n)
    Space complexity: O(1)
*/

typedef std::vector<int> vi;

class Solution {
    public:
        vi minOperations(std::string boxes){
            int n=boxes.size();        

            vi ans(n,0);
            int balls_in_left=0,moves_from_left=0;
            int balls_in_right=0,moves_from_right=0;
            for(int i=0,j=n-1;i<n && j>=0;++i,--j){
                ans[i]+=moves_from_left;
                balls_in_left+=int(boxes[i]=='1');
                moves_from_left+=balls_in_left;
                

                ans[j]+=moves_from_right;
                balls_in_right+=int(boxes[j]=='1');
                moves_from_right+=balls_in_right;
            }
            return ans;
        }
};
// @lc code=end

