/*
 * @lc app=leetcode id=2698 lang=cpp
 *
 * [2698] Find the Punishment Number of an Integer
 */

// @lc code=start
/*
    Recursion: find all combinations of non-overlapping substrings
    // Time complexity: O(n8^(log_10 n))
    // Space complexity: O(log_10 n)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution{
    public:
        int punishmentNumber(int n){

            // Recursive function to get all possible partitions
            // Time complexity: O(8^(log_10 n))
            // Space complexity: O(2log_10 n+2)
            auto solve=[&](std::string& s,int index,int target,auto& self)->bool{
                if(index==s.size()) return target==0;
                int sum=0;
                for(int split=index;split<s.size();++split){
                    sum=sum*10+(s[split]-'0');
                    if(sum>target) return false;
                    if(self(s,split+1,target-sum,self)) return true;
                }
                return false;
            };

            int ans=0;
            for(int i=1;i<=n;++i){
                int sq=i*i;
                std::string sq_str=std::to_string(sq);
                // If a partition sum is equal to i, then and i*i to the answer
                if(solve(sq_str,0,i,solve)) ans+=sq;
            }

            return ans;
        }



};
// @lc code=end

