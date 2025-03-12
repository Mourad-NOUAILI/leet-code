/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
/*
    Sorting + Binary search
    Time complexity: O(n log n)
    Space complexity: O(1+sorting algo depends programming langage) =  C++: O(logn)
*/
class Solution {
    public:
        int my_binary_search(std::vector<int>& A,int x){
            int lo=0,hi=A.size()-1;
            while(lo<=hi){
                int mid=(lo+hi)>>1;
                if(A[mid]==x) return mid;
                if(A[mid]>x) hi=mid-1;
                else lo=mid+1;
            }
            return -1;
        }
        bool checkIfExist(std::vector<int>& arr) {
            int n=arr.size();
            std::sort(arr.begin(),arr.end());
            for(int i=0;i<n;++i){
                int j=my_binary_search(arr,2*arr[i]);
                if(j!=-1 && j!=i) return true;
            }
            return false;
        }
};
// @lc code=end

