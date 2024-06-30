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
        Time complexity: O(nlogn)+O(n)+O(2n^2*groupSize)
        Extra time complexity: O(n)
    */
    bool isNStraightHand(vector<int>& hand, int groupSize){
        sort(hand.begin(),hand.end());

        deque<int> dq(hand.begin(),hand.end());

        while(!dq.empty()){
            int cur=dq.front();
            dq.pop_front();
            for(int i=1;i<groupSize;++i){
                auto it=std::find(dq.begin(),dq.end(),cur+i); //O(n)
                if(it==dq.end()) return false;
                dq.erase(it); // O(n)
            }
        }
        return true;
    }
};
// @lc code=end

/*
    [4,5,1,0,2,3,2,3,0,1,4,5]\n6\n

*/