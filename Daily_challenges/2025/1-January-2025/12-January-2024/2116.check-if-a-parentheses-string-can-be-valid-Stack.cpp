/*
 * @lc app=leetcode id=2116 lang=cpp
 *
 * [2116] Check if a Parentheses String Can Be Valid
 */

// @lc code=start
/*
    Stack
    Time compelxity: O(2n)
    Space compelxity: O(n)
*/
class Solution {
public:
    bool canBeValid(std::string s, std::string locked){
        int n=s.size();
        if (n%2!=0) return false;
        std::stack<int> open,unlocked;
        for(int i=0;i<n;++i){
            if(locked[i]=='0') unlocked.push(i);
            else if(s[i]=='(') open.push(i);
            else if(s[i]==')'){
                if(!open.empty()) open.pop();
                else if (!unlocked.empty()) unlocked.pop();
                else return false;
            }
        }

        // Match remaining open brackets with unlocked characters
        while(!open.empty() && !unlocked.empty() && open.top()<unlocked.top()) {
            open.pop();
            unlocked.pop();
        }
        return open.empty();
    }
};
// @lc code=end

