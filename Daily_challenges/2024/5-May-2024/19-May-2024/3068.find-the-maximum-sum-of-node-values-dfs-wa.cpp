/*
 * @lc app=leetcode id=3068 lang=cpp
 *
 * [3068] Find the Maximum Sum of Node Values
 */

// @lc code=start
#include<bits/stdc++.h>
typedef long long ll;
class Solution {
    public:
        std::vector<int>* tree=nullptr;
        std::vector<bool> visited;
        std::vector<int> values;
        std::vector<int> count_xored_values;
        int k;
        ll ans=0;
    public:
        /*ll maximumValueSum(std::vector<int>& nums, int k, std::vector<std::vector<int>>& edges){
            ll sum=0,count=0,min_diff=INT_MAX;
            for(auto& val: nums){
                ll xor_val=(val^k)*1ll;
                if(xor_val>val){
                    sum+=xor_val;
                    count++;
                    min_diff=std::min(min_diff,xor_val-val);
                }
                else{
                    sum+=val;
                    min_diff=std::min(min_diff,val-xor_val);
                }
            }
            if(count%2==0) return sum;
            return sum-min_diff;
        }*/

        void build_tree(int n, std::vector<std::vector<int>>& edges){
            tree=new std::vector<int>[n];
            for(auto p: edges){
                tree[p[0]].push_back(p[1]);
                tree[p[1]].push_back(p[0]);
            }
        }
        ll dfs(int node){
            if(visited[node]) return 0;
            visited[node]=true;
            ll count=0;
            int min_diff=INT_MAX;
            for(auto& child: tree[node]){
                count+=dfs(child)+(((values[node]^k)>values[node]));
                //std::cout<<values[child]<<'/'<<res<<'\n';
                //count_xored_values[child]=res;
                //count+=res;
            }
            int val=values[node];
            int xored_val=(val^k);
            int mx=std::max(val,xored_val);
            min_diff=std::min(min_diff,abs(val-xored_val));
            //int mx=std::max(val,xored_val);
            //count+=mx==xored_val;
            std::cout<<val<<'/'<<xored_val<<'/'<<count<<'\n';
            ans+=(count%2==0)?mx:mx-min_diff;
            return count;
        }
        ll maximumValueSum(std::vector<int>& nums, int k, std::vector<std::vector<int>>& edges){
            int n=nums.size();
            build_tree(n,edges);
            visited.resize(n,false);
            count_xored_values.resize(n);
            for(auto &val: nums) values.push_back(val);
            this->k=k;
            return dfs(0);

            /*for(int i=0;i<n;++i){
                std::cout<<values[i]<<'/'<<count_xored_values[i]<<'\n';
            }*/
            //return ans;
        }
};
// @lc code=end


// [3,5,4,10,2]\n6\n[[0,1],[0,2],[1,3],[1,4]]\n
// ==> 28

// [2,3]\n7\n[[0,1]]\n
// ==> 9

// [7,7,7,7,7,7]\n3\n[[0,1],[0,2],[0,3],[0,4],[0,5]]\n
//==> 42

// [7,0,1,50,7,333]\n3\n[[0,1],[0,2],[0,3],[0,4],[0,5]]\n
// ==> 402