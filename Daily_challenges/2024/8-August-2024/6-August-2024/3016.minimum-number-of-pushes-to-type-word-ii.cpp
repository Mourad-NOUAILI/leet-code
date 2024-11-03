/*
 * @lc app=leetcode id=3016 lang=cpp
 *
 * [3016] Minimum Number of Pushes to Type Word II
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    n: word's length
    Time complexity: O(n+26log26+26)=O(n)
    Space complexity: O(26+26)=O(1)
*/

class Solution {
public:
    int minimumPushes(std::string word) {
        int freq[26]={0};
        for(auto& c: word) freq[c-'a']++;

        std::priority_queue<int> max_heap;
        for(int i=0;i<26;++i){
            if(freq[i]!=0) max_heap.push(freq[i]);
        }

        int key=1,ans=0,mul=1;
        while(!max_heap.empty()){
            int f=max_heap.top();
            max_heap.pop();

            ans+=mul*f;

            if(key%8==0) mul++;
            
            key++;
        }

        return ans;

    }
};
// @lc code=end

