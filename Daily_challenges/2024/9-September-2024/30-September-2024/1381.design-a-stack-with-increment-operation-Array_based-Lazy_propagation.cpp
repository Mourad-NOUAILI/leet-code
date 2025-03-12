/*
 * @lc app=leetcode id=1381 lang=cpp
 *
 * [1381] Design a Stack With Increment Operation
 */

// @lc code=start
#include<bits/stdc++.h>

/*
    Array based approach + Lazy propagation
    Time complexity: O(1) , overall Time complexity: O(m)
    Space complexity: O(2n)
    n: size of the array
    m: number of calls of `increment` function
*/
class CustomStack{
    public:
        std::vector<int> st,inc;
        int _capacity;
    public:
        // O(1)
        CustomStack(int maxSize){
            _capacity=maxSize;
        }
        
        // O(1)
        void push(int x){
            if(st.size()<_capacity){
                st.push_back(x);
                inc.push_back(0);
            }
        }
        
        // O(1)
        int pop(){
            if(st.empty()) return -1;
            int i=st.size()-1;
            if(i>0) inc[i-1]+=inc[i]; // Lazy propagation
            int x=st[i]+inc[i];
            st.pop_back();
            inc.pop_back();
            return x;
        }

        // O(1) 
        void increment(int k, int val){
          int i=std::min(k,(int)st.size())-1;
          if(i>=0) inc[i]+=val;
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

