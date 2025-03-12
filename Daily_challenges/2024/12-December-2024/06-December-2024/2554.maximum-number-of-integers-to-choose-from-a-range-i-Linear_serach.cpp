/*
 * @lc app=leetcode id=2554 lang=cpp
 *
 * [2554] Maximum Number of Integers to Choose From a Range I
 */

// @lc code=start

/*
    Linear search
    Time compelxity: O(2n+2max(n,m))
    Space complexity: O(max(n,m))
*/
class Solution {
    public:
        int maxCount(std::vector<int>& banned, int n, int maxSum){
            // Find the maximum banned element
            int m=*std::max_element(banned.begin(),banned.end());

            // Maximize the size of the lookup array
            m=std::max(m,n);

            // Create the lookup array for each banned element 
            std::vector<bool> lookup_banned(m+1,false);
            for(auto& e: lookup_banned) ban[e]=true;

            // Perform a linear search by starting with the smallest element first
            // To ensure that we are taking as many elements as possible before the maxSum
            // would be exhausted.
            int sum=0,ans=0;
            for(int number=1;number<=n;++number){
                if(!lookup_banned[number]) {
                    sum+=number;
                    if(sum<=maxSum) ans++;
                }
            }
            return ans;
        }
};
// @lc code=end

