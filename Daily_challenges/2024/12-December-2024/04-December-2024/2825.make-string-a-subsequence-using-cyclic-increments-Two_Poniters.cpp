/*
 * @lc app=leetcode id=2825 lang=cpp
 *
 * [2825] Make String a Subsequence Using Cyclic Increments
 */

// @lc code=start
/*
    Two pointers
    Time compelxity: O(n)
    Space compelxity: O(1)
*/
class Solution {
public:
    bool canMakeSubsequence(std::string str1, std::string str2) {
        int n=str1.size();
        int m=str2.size();
        int i=0; // Pointer on str1
        int j=0; // Pointer on str2
        while(i<n && j<m){
            if(str1[i]==str2[j] || ((((str1[i]-'a')+1)%26)+'a')==str2[j]) i++,j++;
            else i++;
        }
        return j==m;
    }
};
// @lc code=end

