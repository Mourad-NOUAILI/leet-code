/*
    Prefix sums+two pointers
    Time compelxity: O(2n)
    Space compelxity: O(6n)

*/

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution {
    public:
        ll countOfSubstrings(std::string word, int k) {
            auto is_vowel=[&](char letter)->bool{
                return letter=='a' || letter=='e' || letter=='i'|| letter=='o' || letter=='u';
            };


            int n=word.size();

            //  vowels ('a', 'e', 'i', 'o', and 'u')
            vvi prefixes(6,vi(n+1,0));

            for(int i=1;i<=n;++i){
                char letter=word[i-1];
                
                prefixes[0][i]=prefixes[0][i-1]+(letter=='a');
                prefixes[1][i]=prefixes[1][i-1]+(letter=='e');
                prefixes[2][i]=prefixes[2][i-1]+(letter=='i');
                prefixes[3][i]=prefixes[3][i-1]+(letter=='o');
                prefixes[4][i]=prefixes[4][i-1]+(letter=='u');
                prefixes[5][i]=prefixes[5][i-1]+(!is_vowel(letter));
            }

            auto is_possible=[&](int l,int r,int k)->bool{
                return prefixes[0][r+1]-prefixes[0][l]>=1 &&
                    prefixes[1][r+1]-prefixes[1][l]>=1 &&
                    prefixes[2][r+1]-prefixes[2][l]>=1 &&
                    prefixes[3][r+1]-prefixes[3][l]>=1 &&
                    prefixes[4][r+1]-prefixes[4][l]>=1 &&
                    prefixes[5][r+1]-prefixes[5][l]>=k; 
            };

            auto at_least=[&](int k)->ll{
                ll ans=0;
                int l=0;
                for(int r=0;r<n;++r){
                    while(is_possible(l,r,k)){
                        ans+=n-r;
                        l++;
                    }
                }
                return ans;
            };

            return at_least(k)-at_least(k+1);
        }
};


// "axouieaxxzzeeepppuoiiieeuuiaazzaaaaxxcvdhdhdhdhaaidididid" ,  7

// "axouieaxx" , 3