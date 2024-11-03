/*
 * @lc app=leetcode id=1460 lang=cpp
 *
 * [1460] Make Two Arrays Equal by Reversing Subarrays
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(1000+1000+n+n+1000)=O(n)
    Space complexity: O(1000+1000)=O(1)
*/
class Solution {
public:
    bool canBeEqual(std::vector<int>& target, std::vector<int>& arr) {
        int n=arr.size();
        std::vector<int> count(1001,0);
        std::vector<int> should_be(1001,0);
        for(int i=0;i<n;++i){
            count[arr[i]]++;
            should_be[arr[i]]=count[arr[i]]*2;
        }

        for(int i=0;i<n;++i){
            count[target[i]]++;
        }

        for(int i=0;i<=1000;++i){
            if(count[i]!=should_be[i]) return false;
        }

        return true;

    }
};
// @lc code=end

