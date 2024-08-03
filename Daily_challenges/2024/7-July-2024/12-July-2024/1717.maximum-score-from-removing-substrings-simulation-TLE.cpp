/*
 * @lc app=leetcode id=1717 lang=cpp
 *
 * [1717] Maximum Score From Removing Substrings
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(n^2)
    Extra space complexity: O(1)
*/
class Solution {
public:
    int simulate(std::string& s, std::string sub,int points){
        std::size_t p=s.find(sub);
        int m=sub.size();
        int score=0;
        while(p!=std::string::npos){
            score+=points;
            s.erase(p,m);
            p=s.find(sub);
        }
        return score;
    }

    int maximumGain(std::string s, int x, int y) {
        std::string sub1="ab",sub2="ba";
        if(y>x) std::swap(sub1,sub2),std::swap(x,y); 
        return simulate(s,sub1,x)+simulate(s,sub2,y);
    }
};
// @lc code=end

