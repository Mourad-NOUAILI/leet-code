/*
    Max heap
    Time complexity: O(n+nlogn+klogn)=(n+(n+k)logn)
    Space complexity: O(n) 
*/
class Solution {
    public:
        long long pickGifts(std::vector<int>& gifts, int k) {
            long long ans=std::accumulate(gifts.begin(),gifts.end(),0*1ll); // O(n)
            
            std::priority_queue<int,std::vector<int>> max_heap; 
            for(auto& g: gifts) max_heap.push(g); //O(nlogn)
            
            // O(klogn)
            while(k--){
                int g=max_heap.top();
                max_heap.pop();
                ans-=g*1ll;
                g=floor(sqrt(g));
                ans+=g*1ll;
                max_heap.push(g);
            }
            return ans;
        }
};