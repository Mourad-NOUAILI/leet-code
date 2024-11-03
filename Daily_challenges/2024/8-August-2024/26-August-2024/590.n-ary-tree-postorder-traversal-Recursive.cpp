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
    Recursive DFS
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
            if (!root) return {};
            for(auto& child: root->children){
                postorder(child);
            }
            ans.push_back(root->val);
            return ans;
        }
};
// @lc code=end

