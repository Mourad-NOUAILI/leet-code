/*
 * @lc app=leetcode id=2458 lang=cpp
 *
 * [2458] Height of Binary Tree After Subtree Removal Queries
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include<bits/stdc++.h>
/*
    DFS+prefix max+suffix max
    Time complexity: O(n+q)
    Space complexity: O(5n)
    n: number of nodes in the tree
*/

typedef std::vector<int> vi;
class Solution {
    public:
        vi treeQueries(TreeNode* root, vi& queries){
            vi heights;
            std::unordered_map<int,int> node_index,sub_tree_size;
            int index=0;

            /*
                preorder traversal to map each node to its index(0 to n-1),
                and to compute the height of each node.

                postorder traversal to compute each node size

                Time complexity: O(n)
                Space complexity: O(n)
                n: number of nodes in the tree
            */
            auto dfs=[&](TreeNode* node,int height,auto& self)->int{
                if(!node) return 0;

                node_index[node->val]=index++;
                heights.push_back(height);

                int left=self(node->left,height+1,self);
                int right=self(node->right,height+1,self);

                int total=left+right+1;
                sub_tree_size[node->val]=total;

                return total;
            };

            dfs(root,0,dfs);

            int n=heights.size();

            /*
                prefix_max_height[i] stores the maximum height from the root up to the i-th node in the DFS traversal order.
                This array allows us to quickly find the maximum height among nodes visited before a specified node in the DFS traversal.

                suffix_max_height[i] stores the maximum height from the i-th node in the DFS traversal up to the last node.
                This array lets us find the maximum height among nodes visited after a specified node in the DFS traversal.

            */
            vi prefix_max_height(n),suffix_max_height(n);
            prefix_max_height[0]=heights[0];
            suffix_max_height[n-1]=heights[n-1];
            for(int i=1;i<n;++i){
                prefix_max_height[i]=std::max(prefix_max_height[i-1],heights[i]);
            }
            for(int i=n-2;i>=0;--i){
                suffix_max_height[i]=std::max(suffix_max_height[i+1],heights[i]);
            }

            /*
                By precomputing these arrays, for each query we can exclude the subtree rooted
                 at the node in question and quickly look up the maximum heights to the left and right of this subtree.
            */
            vi ans;
            for(auto& node: queries){
                int i=node_index[node]-1;
                int j=i+sub_tree_size[node]+1;
                int max_height=prefix_max_height[i];
                if(j<n) max_height=std::max(max_height,suffix_max_height[j]);
                ans.push_back(max_height);
            }

            return ans;
        }
};
// @lc code=end

