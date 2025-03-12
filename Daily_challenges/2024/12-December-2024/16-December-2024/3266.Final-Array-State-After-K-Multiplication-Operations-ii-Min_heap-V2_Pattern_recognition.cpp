/*
    Pattern recognition
    Min heap (AC)
    Time complexity: O(nlogn+log_2(k)+log_m(mx)+log_10(n))
    Space complexity: O(n)
*/

typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::pair<ll,int> lli;
typedef std::vector<lli> vlli; 

class Solution{
    private:
        const int MOD=1e9+7;
    public:
        ll mul(ll a,ll b){
            a%=MOD;
            b%=MOD;
            return(a*b)*1ll%MOD;
        }

        // power binary exponentiation
        ll power(ll a,ll b) {
            ll res=1;
            while (b>0) {
                if (b%2==1) res=mul(res,a);
                a=mul(a,a);
                b/=2;
            }
            return res;
        }

        vi getFinalState(vi& nums, int k, int multiplier) {
            if(multiplier==1) return nums;

            int n=nums.size();

            auto compare = [](lli left, lli right) {
                if(left.first==right.first) return left.second > right.second;
                else return left.first>right.first;
            };
            std::priority_queue<lli,vlli,decltype(compare)> min_heap(compare);

            for(int i=0;i<n;++i) min_heap.push({nums[i]*1ll,i}); // O(nlogn)

            int mx=*std::max_element(nums.begin(),nums.end()); // O(n)

            // O(log_m(mx)+log_10(n))
            while(k>0 && mx>=multiplier*min_heap.top().first){
                auto[mi,pos_min]=min_heap.top();
                min_heap.pop();
                ll x=mul(mi,multiplier*1ll);
                min_heap.push({x,pos_min});
                k--;
            }

            // Count the total number of repeated operations 
            ll count=k/n;

            // Count the number of remaining operations
            ll rem=k%n;

            // compute the power factor of repeated operations
            // multiplier^count
            ll pf_rep_ops=power(multiplier*1ll,count); // O(log_2(k))

            // compute the power factor of the reamining operations
            // multiplier^(count+1)
            ll pf_rem_ops=power(multiplier * 1ll, count + 1); // O(log_2(k))

            // O(n)
            while(!min_heap.empty()){
                auto[mi,pos_min]=min_heap.top();
                min_heap.pop();

                // if there are remaining operations, start by multiplying the
                // minimum by the power factor of the reamining operations
                // Once there is no remaining operations, multiply the minimum by
                // the power factor of repeated operations.
                nums[pos_min]=int(mul(mi,rem-->0?pf_rem_ops:pf_rep_ops));
            }

            return nums;
        }
};