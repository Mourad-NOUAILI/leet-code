/*
 * @lc app=leetcode id=1028 lang=cpp
 *
 * [1028] Recover a Tree From Preorder Traversal
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

/*
    Preorder: Without processing the traversal string
    Time compelxity: O(2n)
    Space compelxity: O(3n)
    n: #nodes
*/
typedef std::vector<int> vi;
class Solution {
    public:
        // Process on the travsersal string
        // We get an array values contains node values, and depths, where depths[i]
        // contains the depths of values[i]
        // traversal="1-401--349---90--88"
        // values=  {   88, 90, 349,    401,    1}
        // depths   {    2,  3,   2,      1,    0}
        void process_input(std::string& traversal,vi& values,vi& depths){
            traversal="-"+traversal;
            int m=traversal.size();
            int s=m-1,e=m-1;
            while(s>0){
                while(s>0 && traversal[s]!='-') s--;

                values.push_back(std::stoi(traversal.substr(s+1,e)));

                int depth=0;
                while(s>0 && traversal[s]=='-'){
                    s--;
                    depth++;
                }

                depths.push_back(depth);

                e=s;
            }
        }

        
TreeNode* recoverFromPreorder(std::string traversal){
            // process node values and depths each in separate arrays
            vi values,depths;
            process_input(traversal,values,depths);

            int n=values.size();
            int i=n-1; // Root is at the end of the values array

            // Recursive function to recover array from values and depths array in preoder traversal
            // Because nodes appear before their children in preorder,
            // we can sequentially assign them to their parents without needing to look ahead or
	        // backtrack significantly.
            auto recover_tree=[&](TreeNode*& cur_node, int cur_depth,auto& self)->void{
                // i<0: If we are at the end of the values or
                // depths[i]!=cur_depth: The node at i does not belong to the current subtree
 	     // rooted by cur_node.
                // This ensures that we only create nodes that belong to the expected depth.
                if(i<0 || depths[i]!=cur_depth) return;

                // If the node belongs to the current subtree

                cur_node=new TreeNode(values[i]); // Create the current node

                i--; // Move to the next node in preorder sequence
                
                // Start by creating the left subtree if the next node in preorder sequence has a depth
                // greater than the current node by 1
                if(i>=0 && depths[i]==cur_depth+1) self(cur_node->left,cur_depth+1,self);

                // Otherwise, Create the right subtree
                // or keep moving UP until finding the correct depth, and create the right subtree
                self(cur_node->right,cur_depth+1,self);
                
            };
            
            TreeNode* root=nullptr;
            recover_tree(root,0,recover_tree);
            return root;
        }
};
// @lc code=end

