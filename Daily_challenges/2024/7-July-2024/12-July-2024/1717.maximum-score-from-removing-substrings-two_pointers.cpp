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
        int n=s.size();
        int score=0;
        int w=0; // write index
        for(int r=0;r<n;++r){ // r: read index
            s[w++]=s[r];
            if(w>=2 && s[w-1]==sub[1] && s[w-2]==sub[0]){
                w-=2;
                score+=points;
            }
        }
        s=s.substr(0,w);

        return score;
    }

    int maximumGain(std::string s, int x, int y) {
        std::string sub1="ab",sub2="ba";
        if(y>x) std::swap(sub1,sub2),std::swap(x,y); 
        return simulate(s,sub1,x)+simulate(s,sub2,y);
    }
};
// @lc code=end

