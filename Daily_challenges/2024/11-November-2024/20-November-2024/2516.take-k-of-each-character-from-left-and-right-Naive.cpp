/*
 * @lc app=leetcode id=2516 lang=cpp
 *
 * [2516] Take K of Each Character From Left and Right
 */

// @lc code=start

/*
    Naive
    Time complexity: O(n^2)
    Space complexity: O(1)
*/
typedef std::pair<int,char> ic;
typedef std::vector<ic> vic;
typedef std::vector<int> vi;

class Solution {
    public:
       
        int takeCharacters(std::string s, int k){
            int n=s.size();

            if (k==0) return 0;

            long long a=0,b=0,c=0;
            for(auto& letter: s){
                a+=int(letter=='a');
                b+=int(letter=='b');
                c+=int(letter=='c');
            }

            if(a<k || b<k || c<k) return -1;
            
            
            int ans=INT_MAX;
            long long al=0,bl=0,cl=0;

            // For each substring from 0 to l
            for(int l=0;l<n;++l){
                // compute the count of 'a's , 'b's and 'c's in the substring s[0..l]
                al+=int(s[l]=='a'); // number of 'a's
                bl+=int(s[l]=='b'); // number of 'b's
                cl+=int(s[l]=='c'); // number of 'c's

                // Perform a linear search in the remaining subarray for the
                // remaining number of 'a's , 'b's and 'c's
                // Starting by the last index...
                int r=n-1;

                long long ar=0,br=0,cr=0;

                // ...extend the window to the left, until the count of 'a's , 'b's and 'c's
                // each one, became >=k
                // Take the farthest index from the right side
                // substring s[r..n-1] found
                while(r>l && (al+ar<k || bl+br<k || cl+cr<k)){
                    ar+=int(s[r]=='a');
                    br+=int(s[r]=='b');
                    cr+=int(s[r]=='c');
                    r--;
                }

                // Minmize the answer:
                // If count of 'a's , 'b's and 'c's in the substring s[0..l] are greater or
                // equal to k, just take the length of the substring s[0..l], which is l+1
                if(al>=k && bl>=k && cl>=k) ans=std::min(ans,l+1);

                // If count of 'a's , 'b's and 'c's in the substring s[r..n-1] are greater or
                // equal to k, just take the length of the substring s[r..n-1], which is n-r-1
                if(ar>=k && br>=k && cr>=k) ans=std::min(ans,n-r-1);

                // If count of 'a's , 'b's and 'c's in both substrings s[0..l] and s[r..n-1] are greater or
                // equal to k, just take the length both of them, which is (l+1)+(n-r-1)
                if(al+ar>=k && bl+br>=k && cl+cr>=k) ans=std::min(ans,(l+1)+(n-r-1));
            }
            return ans;
        }
};
// @lc code=end

