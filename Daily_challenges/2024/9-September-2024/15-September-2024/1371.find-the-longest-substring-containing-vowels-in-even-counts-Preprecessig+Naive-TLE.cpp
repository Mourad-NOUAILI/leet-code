/*
 * @lc app=leetcode id=1371 lang=cpp
 *
 * [1371] Find the Longest Substring Containing Vowels in Even Counts
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    Preprecessing + Brute force - TLE
    Time complexity: O(5n+n+n^2)=O(n^2)
    Space complexity: O(5n)=O(n)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution {
    public:
        int findTheLongestSubstring(std::string s) {
            int n=s.size();
            
            vvi pre(5,vi(n+1));
            for(int i=1;i<=n;++i){
                pre[0][i]=pre[0][i-1]+int(s[i-1]=='a');
                pre[1][i]=pre[1][i-1]+int(s[i-1]=='e');
                pre[2][i]=pre[2][i-1]+int(s[i-1]=='i');
                pre[3][i]=pre[3][i-1]+int(s[i-1]=='o');
                pre[4][i]=pre[4][i-1]+int(s[i-1]=='u');       
            }

            int ans=0;
            for(int left=0;left<n;++left){
                for(int right=left;right<n;++right){
                    int sum_a=pre[0][right+1]-pre[0][left];
                    int sum_e=pre[1][right+1]-pre[1][left];
                    int sum_i=pre[2][right+1]-pre[2][left];
                    int sum_o=pre[3][right+1]-pre[3][left];
                    int sum_u=pre[4][right+1]-pre[4][left];

                    if(sum_a%2==0&&sum_e%2==0&&sum_i%2==0&&sum_o%2==0&&sum_u%2==0) ans=std::max(ans,right-left+1);
                }
            }
            return ans;
        }
};
// @lc code=end

