/*
    Time complexity: O(Q.n)
    Space complexity: O(n)
*/

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;


class Solution{
    public:
        std::vector<int> shortestDistanceAfterQueries(int n,vvi & queries){
            vi cities(n, 0), ans;
            for(int i=0;i<n-1;++i) cities[i]=i+1;
            int  dist=n-1;
            for(auto &query: queries){
                int u=query[0];
                int v=query[1];
                if (cities[u]!=INT_MIN){
                    for(int i=cities[u];i<v;++i){
                        if (cities[i]!=INT_MIN){
                            cities[i]=INT_MIN;
                            dist--;
                        }
                    }
                    cities[u]=v;
                }
                ans.push_back(dist);
            }
            return ans;
        }
};