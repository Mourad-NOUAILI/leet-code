/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include<bits/stdc++.h>

/*
    Iterative DFS
    Time complexity: O(n)
    space complexity: O(n)
    n=#nodes in the N-ary tree
*/
typedef std::vector<int> vi; 
class Solution {
    public:
        vi ans;
    public:
        vi postorder(Node* root) {
           std::stack<Node*> st;
           st.push(root);
           while(!st.empty()){
                Node* cur=st.top();
                st.pop();
                if(cur){
                    ans.push_back(cur->val);
                    for(auto& child: cur->children) st.push(child);
                }
           }
           std::reverse(ans.begin(),ans.end());
           return ans;
        }
};
// @lc code=end

