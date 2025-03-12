/*
 * @lc app=leetcode id=2924 lang=cpp
 *
 * [2924] Find Champion II
 */

// @lc code=start
/*
    In degree count
    Time compelxity: O(n)
    Space compelxity: O(n)
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class Solution {
    public:
        int findChampion(int n,vvi& edges){
            vi indegree(n,0);
            for(auto& edge: edges){
                indegree[edge[1]]++;
            }
            
            int cnt=0;
            int ans;
            for(int node=0;node<n;++node){
                if(indegree[node]==0){
                    cnt++;
                    ans=node;
                }
            } 

           return cnt==1?ans:-1;
        }
};
// @lc code=end

