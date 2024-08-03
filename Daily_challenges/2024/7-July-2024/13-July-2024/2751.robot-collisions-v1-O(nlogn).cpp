/*
 * @lc app=leetcode id=2751 lang=cpp
 *
 * [2751] Robot Collisions
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
      public:
        class Robot{
            public:
                int index;
                int position;
                int health;
                char direction;
            public:
                Robot(int position,int health,char direction,int index): position(position),health(health),direction(direction),index(index){}
        };
    public:
        std::vector<int> survivedRobotsHealths(std::vector<int>& positions, std::vector<int>& healths, std::string directions){
            int n=positions.size();
            std::vector<Robot> robots;
            for(int i=0;i<n;++i){
               robots.push_back(Robot(positions[i],healths[i],directions[i],i));
            }

            std::sort(robots.begin(),robots.end(),[](const Robot& r1,const Robot& r2){return r1.position<r2.position;});

          
            std::stack<Robot> st;
            std::vector<Robot> tmp_ans;
            
            for(auto& robot: robots){
                    if(robot.direction=='R') st.push(robot);
                    else{
                        bool add_to_ans=true;
                        while(!st.empty()){
                            if(robot.health==st.top().health){
                                st.pop();
                                add_to_ans=false;
                                break;
                            } 
                            else if(robot.health<st.top().health) {
                                st.top().health--;
                                add_to_ans=false;
                                break;
                            }
                            else {
                                st.pop();
                                robot.health--;
                            }
                        }
                        if(add_to_ans) tmp_ans.push_back(robot);
                    }
            }

       
            while(!st.empty()){
                tmp_ans.push_back(st.top());
                st.pop();
            }

            std::sort(tmp_ans.begin(),tmp_ans.end(),[](const Robot& r1, const Robot& r2){return r1.index<r2.index;});
            
            std::vector<int> ans;
            for(auto& robot: tmp_ans){
                 ans.push_back(robot.health);
            }
            
            return ans;

        }
};
// @lc code=end

