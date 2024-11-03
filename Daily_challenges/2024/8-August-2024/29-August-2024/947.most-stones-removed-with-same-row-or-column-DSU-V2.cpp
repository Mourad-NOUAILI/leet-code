/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    DSU
    Time compelxity: O(n.α(_N)+n._N)
    Space complexity: O(3._N)=O(_N)
        where:  α is the inverse Ackermann function
                n: number of stones
                _N=maximum row value+maximum column value+2
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class DSU{
    public:
        vi parent;
        vi group;
    public:
        DSU(int n){
            group.resize(n,1);
            parent.resize(n);
            std::iota(parent.begin(),parent.end(),0);
        }
        int find(int p){
            if(p==parent[p]) return p;
            return parent[p]=find(parent[p]);
        }
        void unify(int p,int q){
            int parent_p=find(p);
            int parent_q=find(q);
            if(parent_p==parent_q) return;
            if(group[parent_p]<group[parent_q]){
                group[parent_q]+=group[parent_p];
                group[parent_p]=1;
                parent[parent_p]=parent_q;
            }
            else{
                group[parent_p]+=group[parent_q];
                group[parent_q]=1;
                parent[parent_q]=parent_p;
            }
        }
};

class Solution {
    public:
        int n;
    public:
        int removeStones(vvi& stones){
            n=stones.size();
            
            vi max_row_arr=*std::max_element(stones.begin(),stones.end(),[](vi& a1,vi& a2){return a1[0]<a2[0];});
            int max_row=max_row_arr[0];
            
            vi max_col_arr=*std::max_element(stones.begin(),stones.end(),[](vi& a1,vi& a2){return a1[1]<a2[1];});
            int max_col=max_col_arr[1];
            
            int _N=max_row+1+max_col+1;

            DSU dsu=DSU(_N);
        
            for(int i=0;i<n;++i){
                int row=stones[i][0];
                int col=stones[i][1]+max_row+1;
                dsu.unify(row,col);
            }

            int cnt_components=0;
            for(auto&g: dsu.group) cnt_components+=g>1;

            return n-cnt_components;
        }
};
// @lc code=end

