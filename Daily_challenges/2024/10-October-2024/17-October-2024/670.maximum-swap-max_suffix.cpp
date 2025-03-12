/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    Max suffixes
    Time complexity: O(n+n)=O(n)
    Space complexity: O(n+n)=O(n)
    n=log_10(num)
*/
class Solution {
    public:
        int maximumSwap(int num){
            std::string s=std::to_string(num);
            int n=s.size();

            // Preprocess all maximums from the right,
            // store the first encountered max (from the right) and its index (will be used for the swap) 
            std::vector<std::pair<char,int>> max_suffix(n);
            max_suffix[n-1]={s[n-1],n-1};
            for(int i=n-2;i>=0;--i){
                if(s[i]>max_suffix[i+1].first) max_suffix[i]={s[i],i};
                else max_suffix[i]=max_suffix[i+1];
            }

            // For every digit s[i]
            for(int i=0;i<n-1;++i){
                // If the current digit s[i] is less than the maximum,
                // perform the swap
                if(s[i]<max_suffix[i].first){
                    std::swap(s[i],s[max_suffix[i].second]);
                    return stoi(s);
                }
            }
            
            // If no swap is performed
            return stoi(s);
        }
};
// @lc code=end

