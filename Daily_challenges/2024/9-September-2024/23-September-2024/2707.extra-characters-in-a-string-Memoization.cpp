
#include<bits/stdc++.h>

/*
    Recusrion + DP: memoization
    Time complexity: O(n^2 * m)
    Space complexity: O(n)
    n: size of the given string s
    m: size of the given dictionary
*/
class Solution {
public:
    int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
        int n=s.size();
        std::unordered_map<std::string,int>memo;

        auto solve=[&](std::string s,auto& self)->int{
            if(memo.find(s)!=memo.end()) return memo[s];
            if(s=="") return 0;
            
            int ans=INT_MAX;
            for(auto& w: dictionary){
                // if w is a prefix of s
                if(s.substr(0,w.size())==w){
                     std::string suff = s.substr(w.size());
                        ans=std::min(ans,self(suff,self));
                }
            }

            // Skip current character
            ans=std::min(ans,1+self(s.substr(1,s.size()-1),self));

            return memo[s]=ans;
        };
            
        return solve(s,solve);
    }
};
