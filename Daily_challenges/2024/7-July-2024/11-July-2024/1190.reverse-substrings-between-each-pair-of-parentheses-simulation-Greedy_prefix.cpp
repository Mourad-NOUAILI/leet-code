/*
 * @lc app=leetcode id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(nm), m is # of valid barckets
    Extra space complexity: O(n)
*/
class Solution {
    public:
        int first_position(std::vector<int>& pre, int start_pos, int val){
            int n=pre.size();
            for(int i=start_pos;i<n;++i){
                if (pre[i]==val) return i;
            }
            return n-1;
        }
        void reverse(std::string& s,int start_pos,int end_pos){
            int i=start_pos;
            int j=end_pos;
            while(i<j) {
                std::swap(s[i],s[j]);
                i++;
                j--;
            }
        }

        void clean(std::string& s){
            std::string tmp;
            for(auto& c: s){
                if(isalpha(c)) tmp.push_back(c);
            }
            s=tmp;
        }

        string reverseParentheses(string s) {
            int n=s.size();
            std::vector<int> pre(n,-1);
            int level=0;
            for(int i=0;i<n;++i){
                if (s[i]=='('){
                    level++;
                    pre[i]=level;
                }
                else if(s[i]==')'){
                    level--;
                    pre[i]=level;
                }
            }
            
            int mx=0;
            while(mx != -1){
                auto itx=std::max_element(pre.begin(),pre.end());
                int px=std::distance(pre.begin(),itx);
                mx=*itx;
    
                if(mx!=-1){
                    int fp=first_position(pre,px,mx-1);
                    reverse(s,px,fp);
                    pre[px]=-1;
                    pre[fp]=-1;
                }
            }

            clean(s);

            return s;
        }
   
};
// @lc code=end

