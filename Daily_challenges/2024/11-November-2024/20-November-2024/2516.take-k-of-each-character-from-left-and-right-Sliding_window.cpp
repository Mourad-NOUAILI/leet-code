/*
 * @lc app=leetcode id=2516 lang=cpp
 *
 * [2516] Take K of Each Character From Left and Right
 */

// @lc code=start
/*
    Sliding window
    Time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
    public:
        int takeCharacters(std::string s, int k) {
            int n=s.size();
            
            if (k==0) return 0;

            // Count all 'a's , 'b' and 'c's
            long long a=0,b=0,c=0;
            for(auto& letter: s){
                a+=int(letter=='a');
                b+=int(letter=='b');
                c+=int(letter=='c');
            }

            if(a<k || b<k || c<k) return -1;
            
            int ans=INT_MAX;

            // Starting from the beginning, we'de like the window be
            // big as possible, such that the count of 'a's , 'b' and 'c's >= k
            // in the remaining characters.
            int l=0;
            for (int r=0;r<n;++r){
                //...and update the number of 'a's , 'b' and 'c's
                // in the remaining characters
                // The count of 'a's , 'b' and 'c's could be reduced
                // when we extend the window
                a-=int(s[r]=='a');
                b-=int(s[r]=='b');
                c-=int(s[r]=='c');

                // Count of 'a's , 'b' and 'c's not valid
                // in remaining characters
                // The count of 'a's , 'b' and 'c's could raise
                // when we shrink the window
                while(a<k || b<k || c<k){
                    a+=int(s[l]=='a');
                    b+=int(s[l]=='b');
                    c+=int(s[l]=='c');
                    l++;
                }
                // Minimize the number of charactrs in remaining portions
                // Which is the number of characters to remove such that
                // the count of 'a's , 'b' and 'c's >=k
                ans=std::min(ans,n-(r-l+1));
            }
            return ans;
        }
};
// @lc code=end

