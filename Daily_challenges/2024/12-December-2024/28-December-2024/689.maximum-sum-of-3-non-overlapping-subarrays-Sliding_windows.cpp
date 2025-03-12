/*
 * @lc app=leetcode id=689 lang=cpp
 *
 * [689] Maximum win of 3 Non-Overlapping Subarrays
 */

// @lc code=start

/*
    Sliding window
    Time compelxity: O(2n)
    Space compelxity: O(1)
*/

typedef std::vector<int> vi;

class Solution{
    public:
        vi maxSumOfThreeSubarrays(vi& nums, int k){
            int n=nums.size();

            // Initialize the three windows
            //1-Compute the sums of element of each window
            int win1=0,win2=0,win3=0;
            for (int i=0;i<k;i++){
                win1+=nums[i];
                win2+=nums[i+k];
                win3+=nums[i+2*k];
            }

            // 2- Initialize the max sums of each window
            int max_win1=win1; // sum of the first subarray
            int max_win2=win1+win2; // sum of the first subarray combined with the second
            int max_win3=win1+win2+win3; // sum of the combination of first, second, and third subarray

            //3- Initialize the starting indexes
            // First subarray starts at 0
            int ans1=0;

            // Combination of the first subarray and the second
            // First subarray starts at 0, and the  second at k
            vi ans2={0,k};

            // Combination of first, second, and third subarray
            // First subarray starts at 0, the  second at k, and the third at 2k
            vi ans3={0,k,2*k};

            //3- Slide the three windows to the left
            for (int i=1;i<=n-3*k;++i){
                // Update the current sum of the first subarray
                win1-=nums[i-1];
                win1+=nums[i+k-1];

                // Update the current sum of the second subarray
                win2-=nums[i+k-1];
                win2+=nums[i+2*k-1];

                // Update the current sum of the third subarray
                win3-=nums[i+2*k-1];
                win3+=nums[i+3*k-1];

                // If the current sum of the first subarray is less than best sum seen so far
                if (win1>max_win1){
                    max_win1=win1; // Upate the best its sum
                    ans1=i; // Update its starting index
                }

                // If current sum of the second subarray combined with the best sum of the first subarray
                // is greater than the best sum of the combination of first subarray and second subarray  
                if (win2+max_win1>max_win2){
                    // Update the  best sum of the combination of first subarray and second subarray
                    max_win2 = win2 + max_win1;

                    // Update  the best starting indices of the combination of first subarray and second subarray
                    ans2={ans1,i+k}; 
                }
                
                // If current sum of the third subarray combined with the best sum of the combination of the first subarray and
                // the second subarray, is greater than the best sum of the third subarray seen so far
                if (win3+max_win2>max_win3){
                    // Update the  best sum of the combination of first subarray, second subarray, and third subarray
                    max_win3=win3+max_win2;

                    // Update  the best starting indices of the combination of first subarray, second subarray and third subarray
                    ans3={ans2[0],ans2[1],i+2*k}; // 
                }
            }
            return ans3;
        }
};
// @lc code=end

