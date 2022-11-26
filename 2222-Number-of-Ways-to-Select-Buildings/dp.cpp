class Solution {
public:
    long long f(string s, string p, long long n){
        vector<vector<long long>> M(4,vector<long long>(n+1,0));
        for (long long i = 0 ; i <= n ; ++i) M[0][i] = 1;
        for(int i = 1 ; i <= 3 ; ++i){
            for(long long j = 1 ; j <= n ; ++j){
                if (j >= i) {
                    if (p[i-1] != s[j-1]) M[i][j] = M[i][j-1];
                    else M[i][j] = M[i-1][j]+M[i][j-1];
                }
            }
        }
        return M[3][n];
    }
    
   
    
    long long numberOfWays(string s) {
        long long n = s.size();
        return f(s,"101",n) + f(s,"010",n);
    }
}
