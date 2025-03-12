/*
 * @lc app=leetcode id=2116 lang=cpp
 *
 * [2116] Check if a Parentheses String Can Be Valid
 */

// @lc code=start
/*
    Space optimization
    Time compelxity: O(2n)
    Space compelxity: O(1)
*/
class Solution {
public:
    bool canBeValid(std::string s, std::string locked){
        int n=s.size();
        if (n%2!=0) return false;
        int open=0,unlocked=0;
        for(int i=0;i<n;++i){
            if(locked[i]=='0') unlocked++;
            else if(s[i]=='(') open++;
            else if(s[i]==')'){
                if(open>0) open--;
                else if (unlocked>0) unlocked--;
                else return false;
            }
        }

        // Match remaining open brackets with unlocked characters
        int level=0;
        for(int i=n-1;i>=0;--i){
            if(locked[i]=='0'){
                level--;
                unlocked--;
            }
            else if(s[i]=='('){
                level++;
                open--;
            }
            else if(s[i]==')') level--;
            if(level>0) return false;
            
            if(unlocked==0&&open==0) break;
        }
        return open<=0;
    }
};
// @lc code=end

