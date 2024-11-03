/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Min heap
    q: number of add queries
    n: size of stream
    Time complexity: O(nlogk+qlogk)=O((n+k)logk)
    Space complexity:O(k)
*/
class KthLargest{
    public:
        std::priority_queue<int,std::vector<int>,std::greater<int>> min_heap;
        int k;
    public:
        KthLargest(int k, vector<int>& nums) {
            this->k=k;
            for(auto& e: nums) {
                if(min_heap.size()<k || e>min_heap.top()) min_heap.push(e);
                if(min_heap.size()>k) min_heap.pop();
                
            }
        }
        
        int add(int val) {
            min_heap.push(val);
            if(min_heap.size()>k) min_heap.pop();
            return min_heap.top();
        }
    };

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

