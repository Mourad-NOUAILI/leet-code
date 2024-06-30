/*
 * @lc app=leetcode id=1404 lang=cpp
 *
 * [1404] Number of Steps to Reduce a Number in Binary Representation to One
 */

// @lc code=start
#include<bits/stdc++.h>
class Solution {
    public:
        // Time complexity: O(1)
        bool is_odd(std::string& s){return s[s.size()-1]=='1';}

        // Time complexity: O(1)
        void divide_by_2(std::string& s){
            s.pop_back();
        }
        
        // Time complexity: O(|s|)
        void add_one(std::string& s){
            bool all_done=false;
            for(int i=s.size()-1;i>=0;+--i){
                if(s[i]=='0'){
                    s[i]='1';
                    all_done=true;
                    break;
                }
                s[i]='0';
            }
            if(!all_done) s.insert(0,"1");
        }

        /*
            Version #1: Modify the input string
            Overall time complexity: O(ans*|s|)
            Extra space complexity: O(1)
        */
        int numSteps(std::string s) {
            if(s=="1") return 0;
            int ans=0;
            while(s!="1"){
                if(is_odd(s)) add_one(s);
                else divide_by_2(s);
                ans++;
            }
            return ans;
        }
};
// @lc code=end

