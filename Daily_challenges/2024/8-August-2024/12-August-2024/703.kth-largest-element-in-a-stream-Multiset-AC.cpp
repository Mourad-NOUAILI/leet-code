/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Multiset
    q: number of add queries
    n: size of stream
    Time complexity: O(n+q(logn+k))=O(q(logn+k))
    Space complexity:O(n)
*/
class KthLargest{
    public:
        std::multiset<int> s;
        int k;
    public:
        KthLargest(int k, vector<int>& nums) {
            this->k=k;
            for(auto& e: nums) s.insert(e);
        }
        
        int add(int val) {
            s.insert(val);
            auto it=s.end();
            for(int i=1;i<=k;++i) it--;

            return *it;
        }
    };
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

