/*
    Sliding window
    Time complexity: O(n)
    Space complexity: O(1)
*/
typedef std::vector<int> vi;
class Solution {
    public:
        vi resultsArray(vi& nums, int k){
            int n=nums.size();
            
            // Check if all integer are consecutive in a given range
            // Time complexity: O(n)
            // Space complexity: O(1)
            auto is_consecutive=[&](int left,int right)->bool{
                for(int i=left;i<right;++i){
                    if(nums[i+1]-nums[i]!=1) return false;
                }
                return true;
            };

            vi ans; // Store final answer
            
            // Create a window of size k
            int win=0;
            for(int i=0;i<k;++i) win+=nums[i];

            // If the integers are NOT consecutive, add -1 to the answer 
            if(!is_consecutive(0,k-1)) ans.push_back(-1);
            // Otherwise add the last element of the window to the answer
            else ans.push_back(nums[k-1]);

            
            // Slide the window
            int i=0;
            while(i<n-k){
                // Slide the window to the right
                win-=nums[i];
                win+=nums[i+k];
                
                // Check if the elements of the new window are consecutive 
                bool is_consecutive_win=k==1 || nums[i+k]-nums[i+k-1]==1;

                i++;

                int a=nums[i]; // First element in the window
                int b=nums[i+k-1]; // Last element in the window
                
                // If the integers are consecutive, so mathematically
                // the sum should be a+(a+1)+(a+2)+...+b 
                long long sum=(b*1ll*(b+1)*1ll/2)-((a-1)*1ll*a*1ll/2);
                // If the window's does not fit the mathematical sum
                // or the integer are NOT consecutive
                // means elements are NOT consecutive and NOT sorted in ascending order
                // Add -1 to the answer
                if(win!=sum || !is_consecutive_win) ans.push_back(-1);
                // Otherwise add the last element of the window to the answer
                else ans.push_back(nums[i+k-1]);
            }
            return ans;         
        }
    };