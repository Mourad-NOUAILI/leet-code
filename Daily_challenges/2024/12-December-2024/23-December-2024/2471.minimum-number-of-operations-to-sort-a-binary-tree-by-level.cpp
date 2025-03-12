/*
 * @lc app=leetcode id=2471 lang=cpp
 *
 * [2471] Minimum Number of Operations to Sort a Binary Tree by Level
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
    BFS (level traversal)+Minimum number of swaps required to sort an array
    n: #nodes in the whole binary tree
    m: #node of each level, in worst case, we can have a complete binary tree,
    so the last level will contain n/2 nodes, means m=n/2
    Time complexity: O(n+mlogm)=O(n+ n/2 log n/2)=O(nlogn)
    Space complexity: O(n+m+logm)=O(n+n/2+log n/2)=O(n+n+logn)=O(n)
*/
class Solution {
    public:
        int minimumOperations(TreeNode* root) {

                // Function to compute the minimum number of swaps required to sort an array
                // Time complexity: O(m)
                // Space complexity: O(m+logm)
                auto minimum_swaps_to_sort=[&](std::vector<int>& arr)->int{
                    int m=arr.size();
                    
                    std::vector<std::pair<int,int>> arr_index;
                    for(int i=0;i<m;++i) arr_index.push_back({arr[i],i});

                    std::sort(arr_index.begin(),arr_index.end());

                    std::vector<bool> visited(m,false);
                    
                    int min_swaps=0;

                    for(int i=0;i<m;++i){
                        // already swapped and corrected or
                        // already present at correct pos
                        if(visited[i] || arr_index[i].second==i) continue;

                        // find out the number of  node in
                        // this cycle and add in `min_swaps`
                        int cycle_size=0;
                        int j=i;
                        while(!visited[j]){
                            visited[j]=true;

                            // move to next node
                            j=arr_index[j].second;

                            cycle_size++;
                        }

                        // Update answer by adding current cycle.
                        min_swaps+=cycle_size>0?cycle_size-1:0;
                    }

                    return min_swaps;

                };

                int ans=0;
                auto level_traversal=[&](TreeNode* root)->void{
                    if (!root) return;
                    std::queue<TreeNode*> q;
                    q.push(root);
                    
                    while(!q.empty()){
                        int cur_subtree_size=q.size();
                        std::vector<int> level_values;
                        while(cur_subtree_size--){
                            TreeNode* cur_node=q.front();
                            q.pop();

                            level_values.push_back(cur_node->val);
                    
                            if(cur_node->left) q.push(cur_node->left);
                            if(cur_node->right) q.push(cur_node->right);
                        }
                        
                        // At each level, determine the minimum number of swaps required to sort an array
                        ans+=minimum_swaps_to_sort(level_values);
                    }
                };

                level_traversal(root);

                return ans;
        }
};
// @lc code=end

