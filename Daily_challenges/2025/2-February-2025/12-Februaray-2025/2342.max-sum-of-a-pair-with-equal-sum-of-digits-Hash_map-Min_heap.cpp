/*
 * @lc app=leetcode id=2342 lang=cpp
 *
 * [2342] Max Sum of a Pair With Equal Sum of Digits
 */

// @lc code=start

/*
    Hash map + Min heap (keep to most the top two largest intgers)
    Time complexity: O(n(logm+log2+n)=O(nlogm+n)=O(nlogm)
    Space complexity: O(2logm)
    m: max number in the given array
*/
typedef std::vector<int> vi;
typedef std::pair<int,int> ii;
class Solution {
    public:
        // Function to compute the sum of digits of a positive intrger x 
        // Time complexity: O(logx)
        int sum_digits(int x){
            int s=0;
            while(x!=0){
                s+=x%10;
                x/=10;
            }
            return s;
        }

        int maximumSum(vi& nums){
            int n=nums.size();

            // Hash map to map the sum of digits with at most the top two largest numbers given that sum
            // Min heap to track the top two largest numbers
            std::unordered_map<int,std::priority_queue<int,vi,std::greater<int>>> sum_numbers;

            for(int i=0;i<n;++i){
                // Compute the sum of digits of nums[i]
                int s=sum_digits(nums[i]);

                // Map nums[i] with its sum of digit by pushing it into the min heap
                sum_numbers[s].push(nums[i]);

                // To keep only at most the two largest elements giving the sum of digits s
                while(sum_numbers[s].size()>2) sum_numbers[s].pop();
            }

            int ans=-1; // -1, if there are no two numbers that satisfy the conditions
            // Iterate over each sum of digits and get its min heap
            for(auto& [sum,min_heap]: sum_numbers){
                // If there is one element in the min heap, ignore that sum
                if(min_heap.size()<2) continue;

                // Otherwise, we are sue that there are two numbers that satisfy the conditions
                int s1=min_heap.top();
                min_heap.pop();
                int s2=min_heap.top();
                min_heap.pop();

                // Maximize the answer
                ans=std::max(ans,s1+s2); 
            }

            return ans;  
        }
};
// @lc code=end

