/*
 * @lc app=leetcode id=2981 lang=cpp
 *
 * [2981] Find Longest Special Substring That Occurs Thrice I
 */

// @lc code=start

/*
    Optimal: Single pass: Space optimization
    AC on part I, AC on part II
    Time complexity:O(n)
    Space complexity: O(1)
*/
class Solution {
public:
    int& min(int& a, int& b, int& c) {
        return a < (b < c ? b : c) ? a : b < c ? b : c;
    }
    int maximumLength(string s) {
        int substringLength = 0, ans = -1;
        char previousCharacter;
        vector<vector<int>> substringLengths(26, vector<int>(3, -1));
        for (char character : s) {
            if (character == previousCharacter) {
                substringLength++;
            } else {
                substringLength = 1;
                previousCharacter = character;
            }
            // Replace the minimum frequency with the current length, if it is
            // greater.
            int& minLength = min(substringLengths[character - 'a'][0],
                                 substringLengths[character - 'a'][1],
                                 substringLengths[character - 'a'][2]);
            if (substringLength > minLength) minLength = substringLength;
        }

        // Find the character with the maximum value of its minimum frequency.
        for (char character = 'a'; character <= 'z'; character++)
            ans = max(ans, min(substringLengths[character - 'a'][0],
                               substringLengths[character - 'a'][1],
                               substringLengths[character - 'a'][2]));
        return ans;
    }
};
// @lc code=end

