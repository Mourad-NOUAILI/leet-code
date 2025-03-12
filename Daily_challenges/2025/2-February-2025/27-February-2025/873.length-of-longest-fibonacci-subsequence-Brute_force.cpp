/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */

// @lc code=start
/*
    Brute force+Binary search
    Time complexity: O(n^2logn)
    Space complexity:O(1)
*/
class Solution {
public:
    int lenLongestFibSubseq(std::vector<int>& arr) {
        int n=arr.size();
        if(n<3) return 0;

        int ans=0;
        // For each Fi(F_{i-1}) and Fj(F_{i-2})
        for(int i=0;i<n-2;++i){
            for(int j=i+1;j<n-1;++j){
                int len=2; // Default len

                // Determine the next Fibinacci term Fi 
                int f0=arr[i];
                int f1=arr[j];
                int f=f0+f1;

                // Search it in the array
                int k=std::lower_bound(arr.begin()+2,arr.end(),f)-arr.begin();

                // While it exists 
                while(k<n && arr[k]==f){
                    len++; // Increment the length by 1

                    // Pass to the next triplet
                    f0=f1;
                    f1=f;
                    f=f0+f;
                    k=std::lower_bound(arr.begin()+k,arr.end(),f)-arr.begin();       
                }


                ans=std::max(ans,len);
            }
        }
        return ans>2?ans:0;
    }
};
// @lc code=end

