#include<bits/stdc++.h>

class Solution {
public:
    /*
        Greedy: TLE
        Time complexity: O(n^2)
        Extra space complexity: O(1)
    */
    int minOperations_naive(std::vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                for(int j=i;j<n;++j){
                    nums[j]=!nums[j];
                }
                ans++;
            }
        }
        return ans;
    }

    /*
        Time complexity: O(n)
        Extra space complexity: O(1)
    */
    int minOperations1(std::vector<int>& nums) {
        int ans=0;
        for(auto& val: nums){
            //if(val==1&&ans%2==1 || val==0&&ans%2==0)
            if( val^(ans%2)==0 ) ans++;
        }
        return ans;
    }

      /*
        Time complexity: O(n)
        Extra space complexity: O(1)
    */
    int minOperations2(std::vector<int>& nums) {
        int ans=0;
        int flag=1;
        for(auto& val: nums){
            if(val!=flag){
                ans++;
                flag=!flag;
            }
        }
        return ans;
    }
};