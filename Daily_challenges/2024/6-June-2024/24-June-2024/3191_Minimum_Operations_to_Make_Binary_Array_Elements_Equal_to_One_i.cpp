#include<bits/stdc++.h>

class Solution {
public:
    /*
        Greedy: AC
        Time complexity: O(n)
        Extra space complexity: O(1)
    */
    int minOperations(std::vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(i+2>=n) return -1;
                ans++;
                nums[i]=1;
                nums[i+1]=!nums[i+1];
                nums[i+2]=!nums[i+2];
            }
        }
        return ans;
    }
};