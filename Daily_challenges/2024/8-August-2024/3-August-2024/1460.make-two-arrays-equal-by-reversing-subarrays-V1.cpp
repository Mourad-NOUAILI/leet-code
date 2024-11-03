/*
 * @lc app=leetcode id=1460 lang=cpp
 *
 * [1460] Make Two Arrays Equal by Reversing Subarrays
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(1000+1000+n+1000)=O(n)
    Space complexity: O(1000+1000)=O(1)
*/
class Solution {
public:
    bool canBeEqual(std::vector<int>& target, std::vector<int>& arr) {
        int n=arr.size();
        std::vector<int> count_arr(1001,0);
        std::vector<int> count_target(1001,0);
        for(int i=0;i<n;++i){
            count_arr[arr[i]]++;
            count_target[target[i]]++;
        }

      
        return count_arr==count_target;
    }
};
// @lc code=end

