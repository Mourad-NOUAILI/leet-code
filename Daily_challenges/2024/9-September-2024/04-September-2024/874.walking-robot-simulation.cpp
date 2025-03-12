/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 */

// @lc code=start

#include<bits/stdc++.h>
/*
    Straight forward Simulation
    Time complexity: O(mlogm+n*ci*logm)
    n*(c0+c1+c2+...+)=nD
    O(mlogm+n*D*logm)
    Space complexity: O(m+8)=O(m)
    where:
        n: size of commands table
        ci: commands[i], where 0<=i<n
        m: size of obstacles tables
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int,int> ii;


class Solution {
    public:
        int modulo(int a,int b){
            return ((a%b)+b)%b;
        }
        int robotSim(vi& commands, vvi& obstacles){
            std::set<ii> obstacles_set;
            for(auto& ob: obstacles) obstacles_set.insert({ob[0],ob[1]});

            vvi directions={{0,1},{1,0},{0,-1},{-1,0}};

            int x=0,y=0,dir=0,ans=0;
            for(auto& c: commands){
                if(c==-1) dir=modulo(dir+1,4);
                else if(c==-2) dir=modulo(dir-1,4);
                else{
                    int dx=directions[dir][0];
                    int dy=directions[dir][1];
                    int i=1;
                    while(i<=c && obstacles_set.find({x+dx,y+dy})==obstacles_set.end()){
                            x+=dx;
                            y+=dy;
                            i++;
                    }
                }
                ans=std::max(ans,x*x+y*y);
            }
            return ans;
        }
    };
// @lc code=end

