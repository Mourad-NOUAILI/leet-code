/*
* Task: 2080. Range Frequency Queries
        https://leetcode.com/problems/range-frequency-queries/
* Technique: SQRT decomposition
* Prepocessing time complexity: O(n)
* Single query time complexity: O(√n)
* Overall code time complexity: O(n)+O(q√n)=O(q√n)
* Overall code space complexity: O(2n)
*/

#include<bits/stdc++.h>

typedef std::unordered_map<int,int> umii;

class RangeFreqQuery {
    public:
        umii* B=nullptr;
        std::vector<int> A;
        int m;
    public:
        RangeFreqQuery(std::vector<int>& arr) {
            A=arr;
            int n = arr.size();
            m = ceil(sqrt(n));
            B=new umii[m];
            for (int i = 0 ; i < n ; ++i) B[i/m][A[i]]++;
            
        }

        int query(int left, int right, int value) {
            int ans=0;
            while(left <= right){
                if (left%m==0 && left+m<=right){
                    ans+=B[left/m][value];
                    left+=m;
                }
                else if (A[left++]==value) ans++;
            }
            return ans;
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