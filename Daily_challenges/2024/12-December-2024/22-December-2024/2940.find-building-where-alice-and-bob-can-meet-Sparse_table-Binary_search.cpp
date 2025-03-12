/*
 * @lc app=leetcode id=2940 lang=cpp
 *
 * [2940] Find Building Where Alice and Bob Can Meet
 */

// @lc code=start
/*
    Sparse table+Binary search
    Time complexity: O((n+q)logn)
    Space complexity: O(nlogn)

*/

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int,int> ii;
typedef std::vector<ii> vii;
typedef std::vector<vii> vvii;

class Solution {
    public:
        // Build the sparse table
        // Time complexity: O(nlogn)
        // Space table: O(nlogn)
        void build(vi& A,int n,vvii& st){
            for(int i=0;i<n;++i) st[i][0]={A[i],i};
            
            for(int j=1;(1<<j)<=n;++j){
                for(int i=0;i+(1<<j)-1<n;++i){
                    st[i][j]=(st[i][j-1].first>st[i+(1<<(j-1))][j-1].first)
                        ?st[i][j-1]
                        :st[i+(1<<(j-1))][j-1];
                }
            }
        }

        // Get the index of the maximum in range [l,r]
        // Time complexity: O(1)
        // Space table: O(1)
        int RMQ(vvii& st,int l,int r){
            int len = r-l+1;
            int k = log2(len);
            int p = r+1-(1<<k);
            return (st[l][k]>st[p][k])?st[l][k].second:st[p][k].second; 
        }

        vi leftmostBuildingQueries(vi& heights,vvi& queries){
            int n=heights.size();

            // Build sparse table
            int m=log2(n)+1;
            vvii st(n,vii(m));
            build(heights,n,st);

            // Binary search to find position `pos` of the first element
            // greater then `h` and starting from position `r`
            // Time complexity: O(logn)
            // Space table: O(1)
            auto first_greater=[&](int h,int p)->int{
                int lo=p,hi=n-1,pos=-1;
                while(lo<=hi){
                    int mid=(lo+hi)>>1;
                    int i=RMQ(st,lo,mid);
                    if(heights[i]>h){
                        pos=mid;
                        hi=mid-1;
                    }
                    else lo=mid+1;
                }
                return pos;
            };

           
            vi ans;
            // For each query
            for(auto& q: queries){
                int l=q[0],r=q[1];

                // if l>r, swap them to ensure that l is always less or equal to r
                if(l>r) std::swap(l,r);

                // If Alice and Bob are on same building or
                // If Alice is in a building less heigher than Bob's building
                // then Alice could jump to Bob's building.
                if(l==r || heights[l]<heights[r]) ans.push_back(r);

                // Otherwise
                else{
                    // Starting from Bob's position (r), find the first greater building
                    // heigher than Alice's building
                    int pos=first_greater(heights[l],r);

                    ans.push_back(pos);  
                }                
            }

            return ans;
        }
};
// @lc code=end

