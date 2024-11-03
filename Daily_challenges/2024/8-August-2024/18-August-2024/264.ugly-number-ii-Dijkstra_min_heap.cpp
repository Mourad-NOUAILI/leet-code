/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Dijkstra Hamming problem: Min heap
    Time complexity: O(n*6logn)=O(nlogn) - AC
    Space complexity: O(3n)=O(n)
*/
class Solution {
    public:
        int nthUglyNumber(int n){
            std::priority_queue<long long,std::vector<long long>,std::greater<long long>> min_heap;
            min_heap.push(1);
            std::set<long long> visited;
                
            for (int i=0;i<n;i++) {
                int x=min_heap.top();
                min_heap.pop();
                
                if(i==n-1) return (int)x;

                if(visited.find((long long)x*2)==visited.end()){
                    min_heap.push((long long)x*2);
                    visited.insert((long long)x*2);
                }
                if(visited.find((long long)x*3)==visited.end()){
                    min_heap.push((long long)x*3);
                    visited.insert((long long)x*3);
                }
                if(visited.find((long long)x*5)==visited.end()){
                    min_heap.push((long long)x*5);
                    visited.insert((long long)x*5);
                }
            }

            return -1;
        }
};
// @lc code=end

