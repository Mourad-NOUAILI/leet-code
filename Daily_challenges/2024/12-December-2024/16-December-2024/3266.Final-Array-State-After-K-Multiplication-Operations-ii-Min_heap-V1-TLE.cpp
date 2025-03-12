/*
    Min heap (TLE)
    Time complexity: O((n+k)logn)
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

        vi getFinalState(vi& nums, int k, int multiplier) {
            int n=nums.size();

            // Find the minimum value x in nums.
            // If there are multiple occurrences of the minimum value,
            // select the one that appears first.
            auto compare = [](lli left, lli right) {
                if(left.first==right.first) return left.second > right.second;
                else return left.first>right.first;
            };

            std::priority_queue<lli,vlli,decltype(compare)> min_heap(compare);
        
            for(int i=0;i<n;++i) min_heap.push({nums[i]*1ll,i});

            while(k--){
                auto[mi,pos_min]=min_heap.top();
                min_heap.pop();
                ll x=mul(nums[pos_min]*1ll,multiplier*1ll);
                min_heap.push({x,pos_min});
                nums[pos_min]=int(x);
            }
          
            return nums;
        }
};