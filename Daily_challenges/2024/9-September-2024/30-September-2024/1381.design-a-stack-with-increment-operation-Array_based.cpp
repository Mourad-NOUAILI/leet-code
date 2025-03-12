/*
 * @lc app=leetcode id=1381 lang=cpp
 *
 * [1381] Design a Stack With Increment Operation
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Array based approach
    Time complexity: O(n) , overall Time complexity: O(mn)
    Space complexity: O(n)
    n: size of the array
    m: number of calls of `increment` function
*/
class CustomStack{
    public:
        std::vector<int> st;
        int _capacity;
    public:
        // O(1)
        CustomStack(int maxSize){
            _capacity=maxSize;
        }

        // O(1)
        void push(int x) {
            if(st.size()<_capacity) st.push_back(x);
        }

        // O(1)
        int pop(){
            if(st.empty()) return -1;
            int x=st[st.size()-1];
            st.pop_back();
            return x;
        }

        // O(n)
        void increment(int k, int val) {
            for(int i=0;i<std::min(k,(int)st.size());++i) st[i]+=val;
        }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// @lc code=end

