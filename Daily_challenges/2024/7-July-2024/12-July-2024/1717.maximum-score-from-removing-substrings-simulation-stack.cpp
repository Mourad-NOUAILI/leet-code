/*
 * @lc app=leetcode id=1717 lang=cpp
 *
 * [1717] Maximum Score From Removing Substrings
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(n)
    Extra space complexity: O(n)
*/
class Solution {
public:
    int simulate(std::string& s, std::string sub,int points){
        int score=0;
        std::stack<int> st;
        for(auto& c: s){
            if(st.empty()) st.push(c);
            else{
                if(c==sub[1] && st.top()==sub[0]){
                    st.pop();
                    score+=points;
                }
                else st.push(c);
            }
        }

        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());

        return score;
    }

    int maximumGain(std::string s, int x, int y) {
        std::string sub1="ab",sub2="ba";
        if(y>x) std::swap(sub1,sub2),std::swap(x,y); 
        return simulate(s,sub1,x)+simulate(s,sub2,y);
    }
};
// @lc code=end

