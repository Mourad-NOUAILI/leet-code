/*
 * @lc app=leetcode id=2593 lang=cpp
 *
 * [2593] Find Score of an Array After Marking All Elements
 */

// @lc code=start
/*
    Min heap
    Time complexity: O(n+nlogn+n)=O(nlogn)
    Space complexity: O(n+n)=O(n)
*/
typedef std::vector<int> vi;
typedef std::pair<int,int> ii;
typedef std::vector<ii> vii;

class Solution{
    public:
        long long findScore(vi& nums) {
            int n=nums.size();

            // Create an array to mark the indices
            // marked[i]==1, means index i is marked
            // marked[i]==0, means index i is not marked
            //Time complexity: O(n)
            //Space complexity: O(n)
            vi marked(n,0); 

            // Create a min heap of pairs{nums[i],index}
            //Time complexity: O(n log n)
            //Space complexity: O(n)
            std::priority_queue<ii,vii,std::greater<ii>> min_heap;
            for(int i=0;i<n;++i) min_heap.push({nums[i],i});

            long long score=0;
            //Time complexity: O(n)
            //Space complexity: O(1)
            while(!min_heap.empty()){
                // Searching for the unmarked minimum
                // If the value at the top on the min heap (the minimum value) is marked,
                // we can not use it, so we should pop it and pass to the next minimum
                while(!min_heap.empty() && marked[min_heap.top().second]) min_heap.pop();

                // If min heap still have elements, means that the minimum at the top is
                // not marked
                if(!min_heap.empty()){
                    auto[v,i]=min_heap.top(); // Get its value and index
                    
                    min_heap.pop(); // pop it or marked it(marked[i]=1), if not it will be reused
                    
                    score+=v*1ll; // add the value of the unmarked minimum to the score
                    
                    // Mark its adjacent values
                    if(i+1<n) marked[i+1]=1;
                    if(i-1>=0) marked[i-1]=1;
                }
            }

            return score;
        }
};
// @lc code=end

