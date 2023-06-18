/*
* Task: 2080. Range Frequency Queries
        https://leetcode.com/problems/range-frequency-queries/
* Technique: Naive approach
* Prepocessing time complexity: O(n)
* Single query time complexity: O(n)
* Whole code time complexity: O(n)+O(qxn)=o(qxn)
* Whole code space complexity: O(n)+O(n)
*/

#include<bits/stdc++.h>

class RangeFreqQuery {
    public:
        std::vector<int> A;
    public:
        RangeFreqQuery(std::vector<int>& arr) {
            A=arr; // O(n)
        }

        int query(int left, int right, int value) {
            int ans=0;
            for (int i = left ; i <= right ; ++i) {
                if (A[i]==value) ans++;
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