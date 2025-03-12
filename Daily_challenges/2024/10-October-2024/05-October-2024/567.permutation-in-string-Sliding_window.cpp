/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    Counting Sliding window 
    Time complexity: O(26+m+26+m+m+26+n*(26+26))=O(n+m)
    space complexity: O(26+26+m)=O(m)
*/

class Solution {
    public:
        bool checkInclusion(std::string s1,std::string s2){
            int n=s2.size();
            int m=s1.size();

            if(n<m) return false;

            std::vector<int> freq1(26,0);
            for(auto& c: s1) freq1[c-'a']++;

            // Create window
            std::vector<int> window(26,0);
            std::string sub=s2.substr(0,m);
            for(auto& c: sub) window[c-'a']++;
            
            if(window==freq1) return true;

            // Slide the window
            for(int i=1;i<=n-m;++i){
                for(int j=0;j<26;++j){
                    window[j]-=int((s2[i-1]-'a')==j);
                    window[j]+=int((s2[i+m-1]-'a')==j);
                }
                if(window==freq1) return true;
            }
            return false;
        }
};
// @lc code=end

