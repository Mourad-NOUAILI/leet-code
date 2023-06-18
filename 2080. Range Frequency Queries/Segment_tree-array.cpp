/*
* Task: 2080. Range Frequency Queries
        https://leetcode.com/problems/range-frequency-queries/
* Technique: Segment tree
* Prepocessing time complexity: O(m)
* Single query time complexity: O(log m)
* Overall code time complexity: O(m)+O(q log m)=O(q log m)
* Overall code space complexity: O(m)
* m: number of nodes in the segment tree
*/

#include<bits/stdc++.h>

typedef std::unordered_map<int,int> umii;

class RangeFreqQuery {
    public:
        umii* seg=nullptr;
        int n = 0;

    public:
        umii merge(umii m1,umii m2){
            for(auto e: m2) m1[e.first]+=e.second;
            return m1;
        }

        void build (std::vector<int> & A, int s, int e, int p){
            if (s==e) {
                seg[p][A[s]]=1;
                return;
            }
            int mid=(s+e)>>1;
            build(A,s,mid,2*p+1);
            build(A,mid+1,e,2*p+2);

            seg[p] = merge(seg[2*p+1],seg[2*p+2]);
        
        }
        
        RangeFreqQuery(std::vector<int>& arr) {
            n=arr.size();
            int k=ceil(log2(n));
            int m=2*(1<<k)-1;
            seg=new umii[m];
            build(arr,0,n-1,0);
        }

        int my_query(int s, int e, int p, int l, int r, int v){
            if (l>e || r<s) return 0;
            if (l<=s && r>=e) return seg[p][v];
            int mid = (s+e)>>1;
            return my_query(s,mid,2*p+1,l,r,v)+my_query(mid+1,e,2*p+2,l,r,v);
        }
        int query(int left, int right, int value) {
            return my_query(0,n-1,0,left,right,value);
        }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

int main(){
    int n,q;
    std::cin >> n >> q;

    std::vector<int> arr;
    for (int i = 0 ; i < n ; ++i){
        int x;
        std::cin>>x;
        arr.push_back(x);
    }

    RangeFreqQuery* obj = new RangeFreqQuery(arr);

    for (int i = 0 ; i < q ; ++i){
        int left,right,value;
        std::cin >> left >> right >> value;

        int ans = obj->query(left,right,value);

        std::cout << ans << '\n';
    }

    return 0;
}