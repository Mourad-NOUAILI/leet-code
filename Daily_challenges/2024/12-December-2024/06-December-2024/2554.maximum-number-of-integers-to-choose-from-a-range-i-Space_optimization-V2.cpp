/*
 * @lc app=leetcode id=2554 lang=cpp
 *
 * [2554] Maximum Number of Integers to Choose From a Range I
 */

// @lc code=start

/*
    Linear search (Space optmization V2: Two pointers)
    Time compelxity: O(2n+2max(n,m))
    Space complexity: O(logn)
*/
class Solution {
    public:
        int maxCount(std::vector<int>& banned, int n, int maxSum){
            std::sort(banned.begin(),banned.end());
            for(auto& e: banned) std::cout<<e<<' ';
            
            // Perform a linear search by starting with the smallest element first
            // To ensure that we are taking as many elements as possible before the maxSum
            // would be exhausted.
            int m=banned.size();
            int sum=0,ans=0;
            int i=0;
            for(int number=1;number<=n;++number){
                bool flag=false; // To check if the current element is banned
               
                // If a banned element is repeated
                while(i<m && number==banned[i]) flag=true,i++;

                // If cuurent number is not banned
                if(!flag){  
                    sum+=number;
                    if(sum<=maxSum) ans++;
                }
            }
            return ans;
        }
};
// @lc code=end

