/*
 * @lc app=leetcode id=2182 lang=cpp
 *
 * [2182] Construct String With Repeat Limit
 */

// @lc code=start
/*
    Two pointers
    Time complexity: O(n+n.k)=O(nk)
    Space complexity: O(k)
    n: Length of s
    k: Number of unique characters in s
    if s consists of lowercase English letters, then k=26
*/
class Solution {
    public:
        std::string repeatLimitedString(std::string s, int repeatLimit) {
            std::vector<int> freq(26,0);

            for(auto& c: s) freq[c-'a']++;

            std::string ans;

            // Start at the end, to ensure that ensure that the answer is
            // in lexicographically non-increasing order.
            int r=25;  

            
            while(r>=0){
                // Look for largest (rightmost) character
                while(r>=0 && freq[r]==0) r--;
                if(r<0) break; // If the there is no character, no need to continue

                // Count the number of character to use
                // If the frequency of the rightmost character is greater than repeatLimit, then take repeatLimit characters
                // If the frequency of the rightmost character is less or equal than repeatLimit, then take them all
                int count=std::min(freq[r],repeatLimit);

                freq[r]-=count; // Reduce the number of the used characters
                
                // Add the taking characters to the answer
                for(int i=1;i<=count;i++) ans.push_back(r+'a');

                // If all occurences of the rightmost character are consumed, then pass the thne next righmost charcater
                if(freq[r]==0) continue; 

                // Otherwise, look for the first character at the left of the righmost character
                int l=r-1;
                while(l>=0 && freq[l]==0) l--;
                if(l<0) break; // If the there no character, no need to continue

                // If there is a character, add it (one occurence) to the answer
                ans.push_back(l+'a');

                freq[l]--; // Update its frequency      
            }
            return ans;
        }
};
// @lc code=end

