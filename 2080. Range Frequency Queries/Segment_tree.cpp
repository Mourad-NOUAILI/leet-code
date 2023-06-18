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

struct Node {
    umii data;
    Node* left;
    Node* right;

    Node(umii data): data(data),left(nullptr),right(nullptr){}
    Node(umii data,Node* left, Node* right): data(data),left(left),right(right){}
};

class RangeFreqQuery {
    public:
        Node* seg=nullptr;
        int n;
    public:
        umii merge(umii m1,umii m2){
            for(auto e: m2) m1[e.first]+=e.second;
            return m1;
        }
        
        Node* build(std::vector<int>& arr, int s, int e){
            if (s==e){
                umii tmp;
                tmp[arr[s]] = 1;
                return new Node(tmp);
            }
            int mid=(s+e)>>1;
            Node* left=build(arr,s,mid);
            Node* right=build(arr,mid+1,e);
            
           return new Node(merge(left->data,right->data),left,right);
        }

        RangeFreqQuery(std::vector<int>& arr) {
            n=arr.size();
            seg=build(arr,0,n-1);
        }

        int my_query(Node*& root, int s, int e, int l, int r, int v){
            if (l > e || r < s) return 0;
            if (l <= s && r >= e ) return root->data[v];
            int mid = (s+e)>>1;
            return my_query(root->left,s,mid,l,r,v)+my_query(root->right,mid+1,e,l,r,v);
        }

        int query(int left, int right, int value) {
        return my_query(seg,0,n-1,left,right,value);
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