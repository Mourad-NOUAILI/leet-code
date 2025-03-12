/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    monotonic increasing stack
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution {
    public:
        int maxChunksToSorted(std::vector<int>& arr){
            int n=arr.size();
            
            std::stack<int> st;

            for (int i=0;i<n;i++) {
                // Case 1: Current element is larger, starts a new chunk
                if (st.empty() || arr[i]>st.top()) st.push(arr[i]);
                else {
                    // Case 2: Merge chunks
                    int mx=st.top();
                    while (!st.empty() && arr[i]<st.top()) st.pop();
                    st.push(mx);
                }
            }
            return st.size();
        }
};
// @lc code=end

int main(){
    Solution sol=Solution();
    std::vector<int> arr={2,-1,0,5,8,6};
    std::cout<<sol.maxChunksToSorted(arr)<<'\n';
    return 0;
}