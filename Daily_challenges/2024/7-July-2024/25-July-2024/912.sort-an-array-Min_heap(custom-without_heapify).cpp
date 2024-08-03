/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Custom min heap (without heapify method)
    Time complexity: O(nlogn)
    Extra space complexity: O(n)
*/
class Solution {
    public:
        class MinHeap{
            public:
                std::vector<int> A;
            public:
                // Time complexity: O(logn)
                void push(int val){
                    A.push_back(val);
                    int i=A.size()-1;
                    while(i>0 && A[i]<A[(i-1)/2]){
                        std::swap(A[i],A[(i-1)/2]);
                        i=(i-1)/2;
                    }
                }

                // Time complexity: O(1)
                bool is_empty(){return A.size()==0;}

                // Time complexity: O(1)
                int get_index_of_mininum_child(int i){
                    if(2*i+2<A.size()){
                        if(A[2*i+1]<A[2*i+2]) return 2*i+1;
                        return 2*i+2;  
                    }
                    if(2*i+1<A.size()) return 2*i+1;

    
                    return -1; // Leaf node reached
                }

                // Time complexity: O(logn)
                void pop(){
                    if(is_empty()) return;
                    std::swap(A[0],A[A.size()-1]);
                    A.pop_back();

                    if(is_empty()) return;

                    int i=0;
                    int min_id=get_index_of_mininum_child(i);
                    while(min_id!=-1 && A[min_id]<A[i]){
                        std::swap(A[min_id],A[i]);
                        i=min_id;
                        min_id=get_index_of_mininum_child(i);
                    }
                }

                // Time complexity: O(1)
                int top(){
                    if(is_empty()) {
                        std::cout<<"Min heap is empty\n";
                        return INT_MAX;
                    }
                    return A[0];
                }
        };
    public:
        std::vector<int> sortArray(std::vector<int>& nums){
            MinHeap min_heap=MinHeap();
            // Time complexity: O(nlogn)
            for(auto& val: nums) min_heap.push(val);

            // Time complexity: O(nlogn)
            int i=0;
            while(!min_heap.is_empty()){
                nums[i++]=min_heap.top();
                min_heap.pop();
            }
            return nums;
        }
};
// @lc code=end

