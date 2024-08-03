/*
 * @lc app=leetcode id=1636 lang=cpp
 *
 * [1636] Sort Array by Increasing Frequency
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(n+m)
    Extra space complexity: O(n+m)
*/
class Solution {
    public:
        vector<int> relative_sort(vector<int>& arr1, vector<int>& arr2) {
            int mx=*std::max_element(arr1.begin(),arr1.end());
            std::vector<int> count(mx+1,0),count_remaining(mx+1,0);
            for(auto& v: arr1) {
                count[v]++;
                count_remaining[v]++;
            }

            for(auto&v: arr2) count_remaining[v]=0;

            int n=arr1.size();
            int m=arr2.size();

            count[arr2[0]]--;
            for(int i=1;i<m;++i) count[arr2[i]]+=count[arr2[i-1]];

            int x=count[arr2[m-1]];
            for(int i=0;i<=mx;++i){
                if(count_remaining[i]!=0){
                    count[i]+=x;
                    x=count[i];
                }
            }

            std::vector<int> ans(n);
            for(int i=n-1;i>=0;--i) ans[count[arr1[i]]--]=arr1[i];


            return ans;
        }

        std::vector<int> frequencySort(std::vector<int>& nums) {
            int n=nums.size();

            int mi=*std::min_element(nums.begin(),nums.end());

            if(mi<0) for(int i=0;i<n;++i) nums[i]+=abs(mi);

            int mx=*std::max_element(nums.begin(),nums.end());

            std::vector<int> nums_freq(mx+1,0);
            for(auto& val: nums) nums_freq[val]++;

            std::vector<std::pair<int,int>> freq_arr;
            for(int i=0;i<=mx;i++) {
                int f=nums_freq[i];
                if(f!=0) freq_arr.push_back({f,i});
            }

            // Perform count sort on the frequency array freq_arr
            auto p=*std::max_element(freq_arr.begin(),freq_arr.end());
            int mxf=p.first;

            std::vector<int> freq(mxf+1,0);
            for(auto& p: freq_arr) freq[p.first]++;


            freq[0]--;
            for(int i=1;i<=mxf;++i) freq[i]+=freq[i-1];

            int m=freq_arr.size();
            std::vector<std::pair<int,int>> sorted_freq_arr(m);
            for(int i=0;i<m;++i) {
                sorted_freq_arr[freq[freq_arr[i].first]--]=freq_arr[i];
            }

            std::vector<int> ref_arr;
            for(auto& p: sorted_freq_arr){
                ref_arr.push_back(p.second);
            }
            
            vector<int> ans=relative_sort(nums,ref_arr);

            if(mi<0) for(int i=0;i<n;++i)ans[i]-=abs(mi);
            
            return ans;

        }
};
// @lc code=end

