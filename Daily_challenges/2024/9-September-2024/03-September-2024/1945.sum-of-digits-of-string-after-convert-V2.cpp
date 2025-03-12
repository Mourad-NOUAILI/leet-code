/*
 * @lc app=leetcode id=1945 lang=cpp
 *
 * [1945] Sum of Digits of String After Convert
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Math
    Time complexity: O(n)
    Space commplexity: O(1)
*/
class Solution {
    public:
        int getLucky(std::string s,int k){
            int ans=0;
            for(char& c: s){
                int x=c-'a'+1;
                ans+=x/10+x%10;
            }

            if(k==1) return ans;
            else if(k==2){
                if(ans<10) return ans;
                else if(ans<100) return ans/10+ans%10;
                else if(ans<1000) return ans%10+ans/100+ans/10%10;
                else return ans%10+ans/1000+ans/100%10+ans%100/10;
            }
        
            return ans%9==0?9:ans%9;
        }
};
// @lc code=end

