/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Prefix max/Suffix min
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution {
    public:
        int maxChunksToSorted(std::vector<int>& arr){
            int n=arr.size();
            std::vector<int> pref_max(n,-1),suff_min(n);
            pref_max[0]=arr[0];
            for(int i=1;i<n;++i) pref_max[i]=std::max(pref_max[i-1],arr[i]);
            suff_min[n-1]=arr[n-1];
            for(int i=n-2;i>0;--i) suff_min[i]=std::min(suff_min[i+1],arr[i]);
            int ans=1;
            for(int i=1;i<n;++i) ans+=int(pref_max[i-1]<suff_min[i]);
            return ans;  
        }
};
// @lc code=end

int main(){
    Solution sol=Solution();
    std::vector<int> arr={2,0,3,5,6,5};
    std::cout<<sol.maxChunksToSorted(arr)<<'\n';
    return 0;
}