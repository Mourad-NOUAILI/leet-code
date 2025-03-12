/*
    Counting: Frequency array
    Time compelxity: O(n+26)=O(n)
    Space complexity: O(1)
*/

class Solution {
public:
    int minimumLength(std::string s) {
        int freq[26]={0};

        for(auto& c: s) freq[c-'a']++;

        int ans=0;

        for(int i=0;i<26;++i){
            if(freq[i]>0){
                ans+=freq[i]%2?1:2;
            }
        }
        
        return ans;
    }
};