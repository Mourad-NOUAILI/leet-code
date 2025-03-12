/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Prefix xor array
    Time complexity: O(n+n+Q)=O(n+Q)
    Space complexity: O(n)
    n: size of the array
    Q: number of queries
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution {
public:
    vi xorQueries(vi& arr, vvi& queries){
        int n=arr.size();
        vi pre(n+1,0);
        for(int i=0;i<n;++i) pre[i+1]=pre[i]^arr[i];
        
        vi ans;
        for(auto& q: queries){
            int left=q[0];
            int right=q[1];
            ans.push_back(pre[right+1]^pre[left]);
        }
        return ans;
    }
};
// @lc code=end

