/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Time complexity: O(nlogn)
    Extra space complexity: O(n)
*/
class Solution {
    public:
        class MinHeap{
            public:
                std::vector<int> A;
            public:
                // Time complexity: O(1)
                bool is_empty(){return A.size()==0;}

                // Time complexity: O(1)
                int get_index_of_mininum_child(int i,int n){
                    if(2*i+2<n){
                        if(A[2*i+1]<A[2*i+2]) return 2*i+1;
                        return 2*i+2;  
                    }
                    if(2*i+1<n) return 2*i+1;

    
                    return -1; // leaf node reached
                }

                void heapify(int i,int n){
                    int min_id=get_index_of_mininum_child(i,n);
                    while(min_id!=-1 && A[min_id]<A[i]){
                        std::swap(A[i],A[min_id]);
                        i=min_id;
                        min_id=get_index_of_mininum_child(i,n);
                    }
                }

        };
    public:
        std::vector<int> sortArray(std::vector<int>& nums){
            MinHeap min_heap=MinHeap();

            min_heap.A=nums;

            int n=nums.size();

            for(int i=n/2-1;i>=0;i--) min_heap.heapify(i,n);
            
            for(int i=n-1;i>=0;i--) {
               std::swap(min_heap.A[0],min_heap.A[i]);
                min_heap.heapify(0,i);
            }

            for(int i=n-1;i>=0;--i) nums[n-i-1]=min_heap.A[i];
            return nums;
        }
};
// @lc code=end

