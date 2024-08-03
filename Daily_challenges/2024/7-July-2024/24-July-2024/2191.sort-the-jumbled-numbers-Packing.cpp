/*
 * @lc app=leetcode id=2191 lang=cpp
 *
 * [2191] Sort the Jumbled Numbers
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Packing/Unpacking:
    Pack (nums[i]=nums[i]mapped nums[i])
    Sort based on mapped nums[i]
    Unpack nums[i]
    
    Time complexity: O(nlog10(n)+n+nlogn+n)=O(nlogn)
    Extra time compelxity: O(n+logn)
*/

class Solution {
    public:
        int map_number(int number,std::vector<int>& mapping){
            int new_number=0,mul=1;
            do{
                int r=number%10;
                number/=10;
                new_number+=(mapping[r]*mul);
                mul*=10;
            }while(number!=0);
            return new_number;
        }
        
        std::vector<int> sortJumbled(std::vector<int>& mapping, std::vector<int>& nums){
            int n=nums.size();
            std::vector<uint64_t> nums_tmp(n);
            for(int i=0;i<n;++i){
                int x=map_number(nums[i],mapping);
                nums_tmp[i]=((uint64_t(nums[i]))<<34)|((uint64_t(x)));
            }

            std::sort(nums_tmp.begin(),nums_tmp.end(),[&](uint64_t a,uint64_t b){
                return (a&17179869183)<(b&17179869183);
            });
            
            for(int i=0;i<n;++i) nums[i]=int(nums_tmp[i]>>34);

            return nums;
        }
};
// @lc code=end

