/*
* Task: 2080. Range Frequency Queries
        https://leetcode.com/problems/range-frequency-queries/
* Technique: Dynamic programming: Get all answers
* Prepocessing time complexity: O(n²)
* Single query time complexity: O(1)
* Whole code time complexity: O(n²)+O(q)=o(n²)
* Whole code space complexity: O(2n^3)
*/



#include<bits/stdc++.h>

typedef std::unordered_map<int,int> umii;

class RangeFreqQuery {
    public:
        std::vector<std::vector<umii>> M;
    public:
        RangeFreqQuery(std::vector<int>& arr) {
            umii counts;
            for(auto e: arr) counts[e]=0;
            int n = arr.size();
            for (int i = 0 ; i < n ; ++i){
                std::vector<umii> row;
                for(int j = 0 ; j < n+1 ; ++j){
                    row.push_back(counts);
                }
                M.push_back(row);
            }

           for (int i = 0 ; i < n ; ++i){
                for(int j = i+1 ; j < n+1 ; ++j){
                    M[i][j]=M[i][j-1];
                    M[i][j][arr[j-1]] = M[i][j-1][arr[j-1]]+1;
                }
            }
        }

        int query(int left, int right, int value) {
            return M[left][right+1][value];
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