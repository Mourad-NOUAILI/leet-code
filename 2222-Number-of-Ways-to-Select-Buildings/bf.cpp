class Solution {
public:
    // Time complexity: O(n^3)
    // Space complexity: O(1)
    long long numberOfWays(string s) {
        long long n = s.size();
        long long ans = 0;
        for(long long i = 0 ; i < n-2 ; ++i){
            for(long long j = i+1 ; j < n-1 ; ++j){
                for(long long k = j+1 ; k < n ; ++k){
                    string x;
                    x += s[i];
                    x += s[j];
                    x += s[k];
                    if (x == "010" || x == "101") ans++;
                }
            }
        }
        return ans;
    }
};
