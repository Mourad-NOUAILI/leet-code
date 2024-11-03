/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    DSU
    Time compelxity: O(n^2.α(n)+n)
    Space complexity: O(n+n+n)=O(n)
        where:  α is the inverse Ackermann function
                n: number of stones
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
            
            DSU dsu=DSU(n);

            for(int i=0;i<n-1;++i){
                vi posi=stones[i];
                int xi=posi[0];
                int yi=posi[1];
                for(int j=i+1;j<n;++j){
                    vi posj=stones[j];
                    int xj=posj[0];
                    int yj=posj[1];

                    if(xi==xj || yi==yj) dsu.unify(i,j);
                }
            }

            int ans=0;
            for(auto& g: dsu.group) ans+=(g-1);

            return ans;
        }
};
// @lc code=end

