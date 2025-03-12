/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
/*
    Hierholzer's Algorithm to find an Eulerian path:
        1-build graph,
        2-perform a POSTORDER DFS from starting node "JFK",
        3-reverse the result

        Time compelxity: O(n+V+n)=O(V+n)
        Space compelxity: O((V+n)+V)=O(V+n)

*/
class Solution {
    private:
        std::unordered_map<std::string,std::vector<std::string>> graph;
        std::vector<std::string> ans;
    public:
        void build_graph(std::vector<std::vector<std::string>>& tickets){
            for(auto& ticket: tickets){
                std::string u=ticket[0];
                std::string v=ticket[1];
                graph[u].push_back(v);
            }

            for (auto& [_, destinations] : graph) {
                std::sort(destinations.rbegin(), destinations.rend());
            }
        }

    
        void dfs(std::string u){
            while(!graph[u].empty()){
                std::string v=graph[u].back();
                graph[u].pop_back();
                dfs(v);
            }
            ans.push_back(u);
        }

        std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets){
            build_graph(tickets);
            dfs("JFK");
            std::reverse(ans.begin(), ans.end());
            return ans;
        }
};
// @lc code=end

