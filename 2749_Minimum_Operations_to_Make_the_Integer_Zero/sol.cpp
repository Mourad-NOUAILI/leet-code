#include<bits/stdc++.h>

class Solution {
    public:
        int makeTheIntegerZero(int num1, int num2) {
            if (num1 < num2) return -1;
            for (int k=1;k<=1000;++k){
                long long s = (num1-k*1ll*num2);

                int x = __builtin_popcountll(s);

                if (k>=x && k<=s) return k;
            }
            return -1;
        }
};


int main(){
    int n1,n2;
    std::cin>>n1>>n2;
    Solution* solution = new Solution();
    int ans = solution->makeTheIntegerZero(n1,n2);
    std::cout << ans << '\n';

    return 0;
}