#include<bits/stdc++.h>

/*
    Greedy
    Time complexity: O(m)
    Space complexity: O(1)
*/
class Solution {
    public:
        int maxDistance(std::vector<std::vector<int>>& arrays) {
            int m=arrays.size();
            
            int mx=arrays[0].back(),mi=arrays[0][0];
            int ans=0;
            for(int i=1;i<m;++i){
                auto& arr=arrays[i];
                ans=std::max({ans,arr.back()-mi,mx-arr[0]});
                mi=std::min(mi,arr[0]);
                mx=std::max(mx,arr.back());
            }

            return ans;
        }
};

int main(){
    Solution s=Solution();

    std::vector<std::vector<int>> arrays={{1},{2}};

    int ans=s.maxDistance(arrays);

    std::cout<<ans<<'\n';

    return 0;
}