/*
    Naive (AC)
    Time complexity: O(kn)
    Space complexity: O(1)
*/

typedef std::vector<int> vi;
class Solution{
    public:
        vi getFinalState(vi& nums, int k, int multiplier) {
            int n=nums.size();

            auto find_min=[&](void)->int{
                int mi=INT_MAX;
                int pos_min=-1;
                for(int i=0;i<n;++i){
                    if(nums[i]<mi){
                        mi=nums[i];
                        pos_min=i;
                    }
                };
                return pos_min; 
            };

            while(k--){
                int pos_min=find_min();
                nums[pos_min]*=multiplier;
            }
            return nums;
        }
};