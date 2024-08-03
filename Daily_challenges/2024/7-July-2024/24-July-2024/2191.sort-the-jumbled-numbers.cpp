/*
 * @lc app=leetcode id=2191 lang=cpp
 *
 * [2191] Sort the Jumbled Numbers
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Map each nums[i] with its index in a new array: nums_with_indices[i]={nums{i},i}
    Map each nums[i] using the mapping array in a new array: nums_after_mapping
    Sort nums_with_indices based on nums_after_mapping
    Restore nums[i] from nums_with_indices
    
    Time complexity: O(nlog10(n)+n+nlogn+n)=O(nlogn)
    Extra time compelxity: O(n+2n+logn)
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
            std::vector<int> nums_after_mapping(n);
            for(int i=0;i<n;++i){
                nums_after_mapping[i]=map_number(nums[i],mapping);
            }

            std::vector<std::pair<int,int>> nums_with_indices;
            for(int i=0;i<n;++i){
                nums_with_indices.push_back({nums[i],i});
            }

            std::sort(nums_with_indices.begin(),nums_with_indices.end(),[&](std::pair<int,int> a, std::pair<int,int> b){return nums_after_mapping[a.second]<nums_after_mapping[b.second];});
            
            for(int i=0;i<n;++i) nums[i]=nums_with_indices[i].first;

            return nums;
        }
};
// @lc code=end

