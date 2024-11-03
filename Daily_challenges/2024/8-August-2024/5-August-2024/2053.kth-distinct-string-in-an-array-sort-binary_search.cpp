/*
 * @lc app=leetcode id=2053 lang=cpp
 *
 * [2053] Kth Distinct String in an Array
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    sorting+Binary search
    Time complexity: O(nlogn)
    Space complexity: O(n+logn)
*/
class Solution {
public:
    static string kthDistinct(vector<string>& arr, int k) {
        const int n=arr.size();
        vector<string> sorted(arr.begin(), arr.end());
        sort(sorted.begin(), sorted.end());

        for(string& s: arr){
            int i=lower_bound(sorted.begin(), sorted.end(), s)-sorted.begin();
            if (i==n-1 ||sorted[i]!=sorted[i+1]) k--;
            if (k==0) return s;
        }
        return "";  
    }
};
// @lc code=end

