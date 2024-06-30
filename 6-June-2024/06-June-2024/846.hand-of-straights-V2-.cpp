/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */

// @lc code=start
#include<bits/stdc++.h>

class Solution {
public:
    /*
        Time complexity: O(nlogn+n)
        Extra time complexity: O(n)
    */
    bool isNStraightHand(vector<int>& hand, int groupSize){
        if(hand.size()%groupSize!=0) return false;
        map<int,int> freq;
        for(auto& e: hand) freq[e]++;

        for(auto& [v,f]: freq){
            if(f==0) continue;
            while(f--){
                for(int i=1;i<groupSize;++i){
                    if(freq[v+i]==0)return false;
                    freq[v+i]--;
                }
            }
        }
        return true;
    }
};
// @lc code=end

/*
    [4,5,1,0,2,3,2,3,0,1,4,5]\n6\n

*/