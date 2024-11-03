/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Sorting
    q: number of add queries
    n: size of stream
    Time complexity: O(n+qnlogn)=O(qnlogn)
    Space complexity:O(n+logn)
*/
class KthLargest{
    public:
        std::vector<int> A;
        int k;
    public:
        KthLargest(int k, vector<int>& nums) {
            this->k=k;
            A=nums;
        }
        
        int add(int val) {
            A.push_back(val);
            std::sort(A.begin(),A.end());
            return A[A.size()-k];
        }
    };

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

