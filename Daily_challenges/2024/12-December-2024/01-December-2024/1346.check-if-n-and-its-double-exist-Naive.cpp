/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
/*
    Naive approach
    Time complexity: O(n^2)
    Space complexity: O(1)
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
            for(int i=0;i<n-1;++i){
                for(int j=i+1;j<n;++j){
                    if(arr[i]==2*arr[j]) return true;
                    if(mod(arr[j],2)==0 && div(arr[j],2)==arr[i]) return true;
                }
            }
            return false;
        }
};
// @lc code=end

