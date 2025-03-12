/*
 * @lc app=leetcode id=2406 lang=cpp
 *
 * [2406] Divide Intervals Into Minimum Number of Groups
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Brute force
    Time complexity: O(nlogn+n^2)=O(n^2)
    Space complexity: O(n)
*/
class Solution {
    public:
        int minGroups(std::vector<std::vector<int>>& intervals){
            int n=intervals.size();

            std::sort(intervals.begin(),intervals.end());

            std::vector<int> groups;

            for(auto& interval: intervals){
                int left=interval[0];
                int right=interval[1];
                int j=0;
                while(j<groups.size()&&groups[j]>=left) j++;
                if(j<groups.size()) groups[j]=right;
                else groups.push_back(right);
            }
            return groups.size();
        }
};
// @lc code=end

