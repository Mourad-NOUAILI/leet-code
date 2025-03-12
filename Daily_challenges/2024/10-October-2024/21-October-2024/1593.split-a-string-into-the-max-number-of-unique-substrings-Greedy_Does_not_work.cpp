/*
 * @lc app=leetcode id=1593 lang=cpp
 *
 * [1593] Split a String Into the Max Number of Unique Substrings
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Greedy: Doesn't work
    Counter example: "wwwzfvedwfvhsww"
*/
class Solution {
    public:
        int maxUniqueSplit(std::string s){
            int n=s.size();
            std::string sub="";
            int i=0;
            std::unordered_map<std::string,bool> list;
            while(i<n){
                sub+=s[i];
                if(list.find(sub)==list.end()) list[sub]=true,i++;
                else{
                    int j=i+1;
                    while(j<n && list.find(sub)!=list.end()){
                        sub+=s[j];
                        j++;
                    }
                    list[sub]=true;
                    i=j;
                }
                sub="";
            }
            //for(auto& [sub,v]: list) std::cout<<sub<<'\n';

            return list.size();
        }
};
// @lc code=end

