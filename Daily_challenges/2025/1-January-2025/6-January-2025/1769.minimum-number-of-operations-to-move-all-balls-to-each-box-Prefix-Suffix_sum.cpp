/*
 * @lc app=leetcode id=1769 lang=cpp
 *
 * [1769] Minimum Number of Operations to Move All Balls to Each Box
 */

// @lc code=start


/*
    Prefix/Suffix sum
    Time complexity: O(7n)
    Space complexity: O(4n)
*/

typedef std::vector<int> vi;

class Solution {
    public:
        vi minOperations(std::string boxes){
            int n=boxes.size();
            
            // For each box:
            
            // Preprocess #moves from left
            vi balls_in_left(n,0);
            balls_in_left[0]=int(boxes[0]=='1');
            vi moves_from_left(n,0);
            for(int i=1;i<n;++i){
                balls_in_left[i]=balls_in_left[i-1]+int(boxes[i]=='1');
                moves_from_left[i]=moves_from_left[i-1]+balls_in_left[i-1];
            }

            // Preprocess #moves from the right
            vi balls_in_right(n,0);
            balls_in_right[n-1]=int(boxes[n-1]=='1');
            vi moves_from_right(n,0);
            for(int i=n-2;i>=0;--i){
                balls_in_right[i]=balls_in_right[i+1]+int(boxes[i]=='1');
                moves_from_right[i]=moves_from_right[i+1]+balls_in_right[i+1];
            }

            vi ans;
            for(int i=0;i<n;++i){
                ans.push_back(moves_from_left[i]+moves_from_right[i]);
            }
            return ans;
        }
};
// @lc code=end

