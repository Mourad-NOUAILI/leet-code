/*
 * @lc app=leetcode id=1371 lang=cpp
 *
 * [1371] Find the Longest Substring Containing Vowels in Even Counts
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    Brute force - TLE
    Time complexity: O(n^2 *(26+n+26)) = O(n^3+2*26.n^2)=O(n^3)
    Space complexity: O(26)=O(1)
*/
class Solution {
    public:
        int findTheLongestSubstring(std::string s) {
            int n=s.size();
            int ans=0;
            for(int left=0;left<n;++left){
                for(int right=left;right<n;++right){
                    std::vector<int> freq(26,0);
                    for(int i=left;i<=right;++i){
                        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') freq[s[i]-'a']++;
                    }

                    int sum=0;
                    for(int i=0;i<26;++i){
                        freq[i]%=2;
                        sum+=freq[i];
                    }

                    if(sum==0) ans=std::max(ans,right-left+1);
                }
            }
            return ans;
        }
};
// @lc code=end

