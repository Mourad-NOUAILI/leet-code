/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    k pointers
    min heap to get the min
    Time complexity: O(nlogk)
    Space complexity: O(k)
    n: total number of elements in all k lists
*/

typedef std::tuple<int, int, int> iii; // min_val,index of list, index of min_val

class Solution {
    public:
        std::vector<int> smallestRange(std::vector<std::vector<int>>& nums){
            int k=nums.size();

            int left=INT_MAX,right=INT_MIN;

            std::priority_queue<iii,std::vector<iii>,std::greater<iii>> min_heap;
            
            for(int i=0;i<k;++i){
                auto v=nums[i];
                left=std::min(left,v[0]);
                right=std::max(right,v[0]);
                min_heap.push({v[0],i,0});
            }

            std::vector<int> ans={left,right};
         
            while(!min_heap.empty()){
                auto [mi,list_idx,mi_idx]=min_heap.top();
                min_heap.pop();

                mi_idx++;

                if(mi_idx<nums[list_idx].size()){
                    min_heap.push({nums[list_idx][mi_idx],list_idx,mi_idx});
                    left=std::get<0>(min_heap.top());
                    right=std::max(right,nums[list_idx][mi_idx]);      
                }
                else break;

                if(right-left<ans[1]-ans[0]) ans={left,right};
                
            }

            return ans;
        }
};
// @lc code=end

