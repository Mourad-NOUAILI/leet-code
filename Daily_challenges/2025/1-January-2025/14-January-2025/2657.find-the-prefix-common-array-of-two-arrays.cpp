/*
 * @lc app=leetcode id=2657 lang=cpp
 *
 * [2657] Find the Prefix Common Array of Two Arrays
 */

// @lc code=start

/*
    Counting: track encountered elements so far
    Time compelxity: O(n)
    Space complexity: O(n)
*/
class Solution {
    public:
        std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B){
            int n=A.size();
            std::vector<int> seen(n+1,0);
            std::vector<int> ans(n);
            ans[0]=int(A[0]==B[0]);
            seen[A[0]]=seen[B[0]]=1;
            for(int i=1;i<n;++i){                
                ans[i]=ans[i-1]+seen[A[i]]+seen[B[i]]+(A[i]==B[i]);
                seen[A[i]]=1;
                seen[B[i]]=1;
            }
            return ans;
        }
};

// @lc code=end

