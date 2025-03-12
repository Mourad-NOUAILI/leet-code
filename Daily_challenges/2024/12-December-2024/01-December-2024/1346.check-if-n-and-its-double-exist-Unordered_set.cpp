/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
/*
    Unordered set
    Time complexity: Θ(n),O(n^2)
    Space complexity: O(n)
*/
class Solution {
    public:
        int mod(int a,int b){
            return ((a%b)+b)%b;
        }
        int div(int a,int b){
            return (a-mod(a,b))/b;
        }
        bool checkIfExist(std::vector<int>& arr) {
            int n=arr.size();
            std::unordered_set<int> seen;
            for(auto& e: arr){
                if(seen.find(e)!=seen.end()) return true;
                seen.insert(2*e);
                if(mod(e,2)==0) seen.insert(div(e,2));
            }
            return false;
        }
};
// @lc code=end

