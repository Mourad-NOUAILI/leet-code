/*
 * @lc app=leetcode id=2028 lang=cpp
 *
 * [2028] Find Missing Observations
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Brute force
    Time complexity: O(m+6^target+6^target)=O(6^target)
    Space complexity: O(target+6^target+6^target)
*/

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution {
    public:
        vvi all_sums(vi& arr,int target,int n,std::map<int,vvi>& memo){
            if(target==0) return {{}};
            if(target<0) return {};
            if(memo.find(target)!=memo.end()) return memo[target];
            vvi all;
            for(auto& e: arr){
                vvi ans=all_sums(arr,target-e,n,memo);
                for(auto& v: ans){
                    v.push_back(e);
                    all.push_back(v);
                }
            }
            return memo[target]=all;
        }

        vi missingRolls(vi& rolls,int mean,int n){
            int m=rolls.size();
            int rolls_sum=std::accumulate(rolls.begin(),rolls.end(),0);
            int missing_sum=mean*(m+n)-rolls_sum;

            if(missing_sum>6*n) return {};

            vi arr={1,2,3,4,5,6};

            std::map<int,vvi> memo;
            vvi all=all_sums(arr,missing_sum,n,memo);
           
            for(auto& v: all){
                if (v.size()==n) return v;
            }

            return {};
        }
};
// @lc code=end

