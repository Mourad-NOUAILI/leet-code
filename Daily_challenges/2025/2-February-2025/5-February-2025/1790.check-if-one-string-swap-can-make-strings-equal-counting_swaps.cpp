/*
    swap counting
    Time complexity: O(n)
    Space compelxity: O(1)
*/
class Solution {
    public:
        bool areAlmostEqual(std::string& s1, std::string& s2) {
            int n=s1.size();

            // Count number of swaps on original strings
            // If we found two different letters on same postion, means we need a swap
            // means for 1 swap, we count 2 (for 1 swap, we have 2 pairs of different letters at same index)
            int count_pairs=0;

            // If there is one swap, save the positions
            int first_index=0,second_index=0;
            for(int i=0;i<n;++i){
                if(s1[i]!=s2[i]){
                    count_pairs++;
                    // If #pairs of different letters at same position is more than 2, return false
                    if(count_pairs>2) return false;

                    // Otherwise, If we found the first pair, save the first index 
                    if(count_pairs==1) first_index=i;
                    // Otheerwise, count_pairs==2, we found the second pair, save the second index
                    else second_index=i;
                }       
            }

            // To make a swap, the letter of string s1 at the first index, should be equal to the letter of string s2 at the second index
            // and the letter of string s1 at the second index, should be equal to the letter of string s2 at the first index
            return s1[first_index]==s2[second_index] && s1[second_index]==s2[first_index];
        }
};