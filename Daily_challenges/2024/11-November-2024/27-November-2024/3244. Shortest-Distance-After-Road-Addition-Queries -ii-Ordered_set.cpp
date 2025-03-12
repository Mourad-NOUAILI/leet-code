/*
    Ordered set
    Time complexity: O(nlogn+Q.n.logn)
    Space complexity: O(n)
*/

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution{
    public:
        std::vector<int> shortestDistanceAfterQueries(int n,vvi & queries){
            std::set<int> s;
            for(int i=0;i<n;++i) s.insert(i);
            vi ans;
            for(auto& query: queries){
                int u=query[0];
                int v=query[1];
                auto u_it=s.lower_bound(u+1);
                auto v_it=s.upper_bound(v-1);
                if(*v_it>=*u_it) s.erase(u_it,v_it);
                ans.push_back(s.size()-1);
            }
            return ans;
        }
};