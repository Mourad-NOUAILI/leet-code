/*
 * @lc app=leetcode id=1408 lang=cpp
 *
 * [1408] String Matching in an Array
 */

// @lc code=start
/*
    Rabin Karp (single works fo this problem)
    Time complexity: O(n^2*m)
    Space complexity: O(1)
    n: size of the words's list
    m: size of a word in the list of words 
*/

typedef long long ll;
class Solution {
    private:
        const ll MOD1=1e9+7;
        const ll MOD2=1e9+33;
        const int radix1=26;
        const int radix2=27;
    public:
        ll power(ll a,int b,ll mod){
            ll res=1;
            while (b>0){
                if (b&1) res=(res*a)%mod;
                a=(a*a)%mod;
                b/=2;
            }
            return res%mod;
        }

        ll hash(std::string& s,int m,int radix,bool is_mod1){
            ll mod=is_mod1?MOD1:MOD2;
            ll h=0,factor=1;
            for(int i=m-1;i>=0;--i){
                h+=((s[i]-'a')*factor)%mod;
                factor=(factor*radix)%mod;
            }
            return h%mod;
        }

        bool is_match(std::string& haystack,std::string& needle){            
            int n=haystack.size();
            int m=needle.size();

            if(needle=="" || n<m) return false;

            ll max_weight1=power(radix1,m,MOD1);
            //ll max_weight2=power(radix2,m,MOD2);

            ll needle_hash1=hash(needle,m,radix1,true);
            //ll needle_hash2=hash(needle,m,radix2,false);

            ll win_hash1=hash(haystack,m,radix1,true);
            //ll win_hash2=hash(haystack,m,radix2,false);

            for(int i=0;i<=n-m;++i){
                if(win_hash1==needle_hash1) return true;

                win_hash1=((((win_hash1*radix1)%MOD1-((haystack[i]-'a')*max_weight1)%MOD1+haystack[i+m]-'a')%MOD1)+MOD1)%MOD1;
                //win_hash2=((((win_hash2*radix2)%MOD2-((haystack[i]-'a')*max_weight2)%MOD2+haystack[i+m]-'a')%MOD2)+MOD2)%MOD2;
            }

            return false;
            
        }

        std::vector<std::string> stringMatching(std::vector<std::string>& words){
            int n=words.size();
            std::vector<std::string> ans;
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    if(i==j) continue;
                    if(is_match(words[j],words[i])){
                        ans.push_back(words[i]);
                        break;
                    }
                }
            }

            return ans;
        }
};
// @lc code=end

