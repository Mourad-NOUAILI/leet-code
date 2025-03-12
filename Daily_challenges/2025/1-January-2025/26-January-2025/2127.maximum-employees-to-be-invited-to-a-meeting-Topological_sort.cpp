/*
 * @lc app=leetcode id=2127 lang=cpp
 *
 * [2127] Maximum Employees to Be Invited to a Meeting
 */

// @lc code=start
typedef std::vector<int> vi;

/*
    Topological sort
    Time complexity: O(6n)=O(n)
    Space complexity: O(3n)
*/
class Solution {
    public:
        // Cycle detection
        void find_cycles(vi& favorite,vi& indegree,vi& depth,int n){
            // Compute the indegree of each node
            for(int node=0;node<n;++node) indegree[favorite[node]]++;

            // Put all degree with in degree==0 in a FIFO queue
            std::queue<int> q;
            for(int node=0;node<n;++node){
                if(indegree[node]==0) q.push(node);
            }

            // Eliminate non-cycle node and compute the depth of each node
            while(!q.empty()){
                int cur_node=q.front();
                q.pop();
                int next_node=favorite[cur_node];
                depth[next_node]=std::max(depth[next_node],depth[cur_node]+1);
                if(--indegree[next_node]==0) q.push(next_node);
            }
        }

        // Longest length and final answer
        int get_longest_length_and_final_answer(vi& favorite,vi& indegree,vi& depth,int n){
            int cycle_gt_2=0,cycle_eq_2_and_path=0;
            for(int node=0;node<n;++node){
                // Just focus on node with non zero in degree
                if(indegree[node]==0) continue;

                // First node in the current cycle with non zero in degree
                int cur=node;
                int cycle_len=0; // Length of current cycle
                while(indegree[cur]!=0){
                    indegree[cur]=0; // Mark current node as visited
                    cycle_len++;
                    cur=favorite[cur]; // Go to next node
                }

                // If the current cycle length is greater than 2
                // than, take the maximum length of all cycles which
                //their length greater than 2
                if(cycle_len>2) cycle_gt_2=std::max(cycle_gt_2,cycle_len);
                // If the current cycle length is equal to 2
                // take the the length of two paths (depth[node]+depth[favorite[node]])
                // Cumulate all the lengths.
                else cycle_eq_2_and_path+=depth[node]+depth[favorite[node]];
            }

            // Final answer
            return std::max(cycle_gt_2,cycle_eq_2_and_path);
        }

        int maximumInvitations(vi& favorite){
            int n=favorite.size();
            vi indegree(n,0),depth(n,1);
            find_cycles(favorite,indegree,depth,n);
            return get_longest_length_and_final_answer(favorite,indegree,depth,n);
        }
};
// @lc code=end

