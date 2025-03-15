/*
    Prefix sums+two pointers+at last(k)-at last(k+1)
    Time compelxity: O(n)
    Space compelxity: O(1)

*/

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution {
    public:
        ll countOfSubstrings(std::string word, int k) {
            int n=word.size();

            auto is_vowel=[&](char letter)->bool{
                return letter=='a' || letter=='e' || letter=='i'|| letter=='o' || letter=='u';
            };
            
            // Funtion to check if we have, in range[l,r], at least one occurence of a vowel, and
            // at least k consonant.
            auto is_possible=[&](int& count_a,
                                    int& count_e,
                                    int& count_i,
                                    int& count_o,
                                    int& count_u,
                                    int& count_cons,
                                    int k)->bool{
                return count_a>=1 &&
                    count_e>=1 &&
                    count_i>=1 &&
                    count_o>=1 &&
                    count_u>=1 &&
                    count_cons>=k; 
            };

            // Funtion to check if we have, in the whole word, at least one occurence of a vowel, and
            // at least k consonant.
            auto at_least=[&](int k)->ll{
                ll ans=0;
                int l=0;
                int count_a=0,count_e=0,count_i=0,count_o=0,count_u=0,count_cons=0;
                for(int r=0;r<n;++r){
                    count_a+=(word[r]=='a');
                    count_e+=(word[r]=='e');
                    count_i+=(word[r]=='i');
                    count_o+=(word[r]=='o');
                    count_u+=(word[r]=='u');
                    count_cons+=(!is_vowel(word[r]));
                    while(is_possible(count_a,count_e,count_i,count_o,count_u,count_cons,k)){
                        count_a-=(word[l]=='a');
                        count_e-=(word[l]=='e');
                        count_i-=(word[l]=='i');
                        count_o-=(word[l]=='o');
                        count_u-=(word[l]=='u');
                        count_cons-=(!is_vowel(word[l]));
                        ans+=n-r;
                        l++;
                    }
                }
                return ans;
            };

            // Illustrated by Venn diagram
            return at_least(k)-at_least(k+1);
        }
};


// "axouieaxxzzeeepppuoiiieeuuiaazzaaaaxxcvdhdhdhdhaaidididid" ,  7

// "axouieaxx" , 3