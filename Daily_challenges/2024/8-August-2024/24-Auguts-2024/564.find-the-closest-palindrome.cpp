/*
 * @lc app=leetcode id=564 lang=cpp
 *
 * [564] Find the Closest Palindrome
 */

// @lc code=start

#include<bits/stdc++.h>

/*
    Math
    Time complexity: O(logm)
    Space complexity: O(5+5+5)=O(1)
    where: m is the number of digits of n
*/

typedef long long ll;
typedef std::vector<ll> vl; 

class Solution {
    public:
        ll get_palindrome(ll left_half,bool is_even){
            ll pal=left_half;
            if(!is_even) left_half/=10;
            while(left_half>0){
                pal=pal*10+left_half%10;
                left_half/=10;
            }
            return pal;
        }

        std::string nearestPalindromic(std::string n) {
            ll number=std::stoll(n);

            int m=n.size();

            std::string sub=n.substr(0,(m+1)/2);
            ll left_half=std::stoll(sub);

            ll pal1=get_palindrome(left_half-1,m%2==0);
            ll pal2=get_palindrome(left_half,m%2==0);
            ll pal3=get_palindrome(left_half+1,m%2==0);
            ll pal4=std::pow(10,m-1)-1;;
            ll pal5=std::pow(10,m)+1;;

            vl palindromes;
            if(pal1!=number) palindromes.push_back(pal1);
            if(pal2!=number) palindromes.push_back(pal2);
            if(pal3!=number) palindromes.push_back(pal3);
            if(pal4!=number) palindromes.push_back(pal4);
            if(pal5!=number) palindromes.push_back(pal5);

            vl diffs;
            for(auto&p: palindromes){
                diffs.push_back(abs(p-number));
            }

            for(auto&p: diffs) std::cout<<p<<'\n';

            ll min_diff=*std::min_element(diffs.begin(),diffs.end());

            vl mins;
            for(int i=0;i<diffs.size();++i){
                if(diffs[i]==min_diff) mins.push_back(palindromes[i]); 
            }

            ll min_pal=*std::min_element(mins.begin(),mins.end());

            std::string ans=std::to_string(min_pal);

            return ans;
        }
};
// @lc code=end

