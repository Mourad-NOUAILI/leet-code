/*
 * @lc app=leetcode id=2554 lang=cpp
 *
 * [2554] Maximum Number of Integers to Choose From a Range I
 */

// @lc code=start

/*
    Linear search (Space optmization V1: Binary search)
    Time compelxity: O(2n+2max(n,m))
    Space complexity: O(logn)
*/
class Solution {
    public:
        int maxCount(std::vector<int>& banned, int n, int maxSum){
            std::sort(banned.begin(),banned.end());
            
            // In order to optimize the space, we perform a binary search on the 
            // number, to check if it is banned or not. 
            auto is_banned=[&](int x)->bool{
                int lo=0,hi=banned.size()-1;
                while(lo<=hi){
                    int mid=(lo+hi)>>1;
                    if(banned[mid]==x) return true;
                    if(banned[mid]>x) hi=mid-1;
                    else lo=mid+1;
                }
                return false;
            };

            // Perform a linear search by starting with the smallest element first
            // To ensure that we are taking as many elements as possible before the maxSum
            // would be exhausted.
            int sum=0,ans=0;
            for(int number=1;number<=n;++number){
                if(!is_banned(number)) {
                    sum+=number;
                    if(sum<=maxSum) ans++;
                }
            }
            return ans;
        }
};
// @lc code=end

