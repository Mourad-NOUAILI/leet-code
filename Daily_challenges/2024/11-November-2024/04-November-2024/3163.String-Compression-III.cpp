#include<bits/stdc++.h>

/*
    Two pointers
    Time Complexity: O(n)
    Space complexity: O(1)
*/

class Solution {
    public:
        std::string compressedString(std::string word) {
            int n=word.size();

            std::string ans;
            int i=0,j=0;
            while(i<n){
                if(word[i]==word[j]) j++;
                else{
                    int len=j-i;
                    if(len<=9){
                        ans.push_back(len+'0');
                        ans.push_back(word[i]);
                    }
                    else{
                        int count=len/9;
                        for(int k=1;k<=count;++k){
                            ans.push_back('9');
                            ans.push_back(word[i]);
                        }
                        if(len%9!=0){
                            ans.push_back((len%9)+'0');
                            ans.push_back(word[i]);
                        }
                    }
                    i=j;
                }
            }
            return ans;
        }
};


/*
    one pointer 
    Time Complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        std::string compressedString(std::string word) {
            int n=word.size();

            std::string ans;
            int i=0;
            while(i<n){
                int count=0;
                char cur=word[i];
                while(i<n && count<9 && word[i]==cur){
                    count++;
                    i++;
                }
                ans.push_back(count+'0');
                ans.push_back(cur);
            }
            return ans;
        }
};