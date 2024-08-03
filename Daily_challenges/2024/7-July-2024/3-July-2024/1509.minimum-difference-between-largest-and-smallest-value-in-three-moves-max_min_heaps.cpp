/*
 * @lc app=leetcode id=1509 lang=cpp
 *
 * [1509] Minimum Difference Between Largest and Smallest Value in Three Moves
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Max, min heaps
    Time complexity: O(n log 4)=O(n)
    Extra space complexity: O(8)=O(1)
*/
class Solution {
    public:
        int minDifference(std::vector<int>& nums) {
            int n=nums.size();
            if(n<=4) return 0;
            
            std::priority_queue<int> min_heap;
            std::priority_queue<int,std::vector<int>,greater<int>> max_heap;

            for(auto& e: nums){
                max_heap.push(e); // O(log 4)
                min_heap.push(e); // O(log 4)

                if(max_heap.size()>4) max_heap.pop();
                if(min_heap.size()>4) min_heap.pop();
            }

            std::vector<int> A(8);
            int i=0;
            int j=7;
            while(!min_heap.empty()){
                A[i]=min_heap.top();
                A[j]=max_heap.top();
                i++;
                j--;
                min_heap.pop();
                max_heap.pop();
            }

            for(auto& e: A) std::cout<<e<<' ';

            return std::min({A[4]-A[0],
                            A[5]-A[1],
                            A[6]-A[2],
                            A[7]-A[3]
                        }); 
        }
};
// @lc code=end

