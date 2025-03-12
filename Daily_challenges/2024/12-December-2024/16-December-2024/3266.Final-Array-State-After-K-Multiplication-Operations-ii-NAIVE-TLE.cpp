/*
    Naive (TLE)
    Time complexity: O(kn)
    Space complexity: O(n)
*/

typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;

class Solution{
    private:
        const int MOD=1e9+7;
    public:
        ll mul(ll a,ll b){
            a%=MOD;
            b%=MOD;
            return(a*b)*1ll%MOD;
        }
        
        vi getFinalState(vi& nums, int k, int multiplier) {
            int n=nums.size();

            auto find_min=[&](vl& A)->int{
                int mi=INT_MAX;
                int pos_min=-1;
                for(int i=0;i<n;++i){
                    if(A[i]<mi){
                        mi=A[i];
                        pos_min=i;
                    }
                };
                return pos_min; 
            };

            vl numsLL;
            for(auto& e: nums) numsLL.push_back(e*1ll);
            while(k--){
                int pos_min=find_min(numsLL);
                numsLL[pos_min]=mul(numsLL[pos_min]*1ll,multiplier*1ll);
            }
            
            vi ans;
            for(auto& e: numsLL) ans.push_back(int(e));
            return ans;
        }
};