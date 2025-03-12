/*
 * @lc app=leetcode id=2940 lang=cpp
 *
 * [2940] Find Building Where Alice and Bob Can Meet
 */

// @lc code=start

/*
    Naive
    Time complexity: O(Q.n)
    Space complexity: O(1)
    n: number of buildings
    Q: number of queries
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
    public:
        vi leftmostBuildingQueries(vi& heights,vvi& queries){
            int n=heights.size();

            // Linear search to find position `pos` of the first element
            // greater then `h` and starting from position `r`
            // Time complexity: O(n)
            // Space table: O(1)
            auto first_greater=[&](int h,int p)->int{
                for(int i=p+1;i<n;++i){
                    if(heights[i]>h) return i;
                }
                return -1;
            };

            vi ans;
            // For each query
            for(auto& q: queries){
                int l=q[0],r=q[1];
                // if l>r, swap them to ensure that l is always less or equal to r
                if(l>r) std::swap(l,r);

                // If Alice and Bob are in the same building or
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

