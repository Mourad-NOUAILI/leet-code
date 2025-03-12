/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    substring and count
    Time complexity: O(26+m+n(m+26+26))=O(nm)
    space complexity: O(26+n*(m+26))=O(nm)
*/

class Solution {
    public:
        bool checkInclusion(std::string s1,std::string s2){
            int n=s2.size();
            int m=s1.size();

            if(n<m) return false;

            std::vector<int> freq1(26,0);
            for(auto& c: s1) freq1[c-'a']++;

            for(int i=0;i<=n-m;++i){
                std::string sub=s2.substr(i,m);
                std::vector<int> freq(26,0);
                for(auto& c: sub) freq[c-'a']++;
                if(freq==freq1) return true;
            }
            return false;
        }
};
// @lc code=end

