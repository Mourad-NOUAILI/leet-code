/*
 * @lc app=leetcode id=1945 lang=cpp
 *
 * [1945] Sum of Digits of String After Convert
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Straight forward simulation
    Time complexity: O(n+kn)=O(kn)
    Space commplexity: O(1)
*/
class Solution {
    public:
        int getLucky(string s, int k) {
            std::string number = "";
            for (char &c: s) {
                number+=std::to_string(c-'a'+1);
            }
            
            while (k--){
                int temp = 0;
                for (char x: number) {
                    temp+=x-'0';
                }
                number=std::to_string(temp);
            }
            return stoi(number);
        }
};
// @lc code=end

