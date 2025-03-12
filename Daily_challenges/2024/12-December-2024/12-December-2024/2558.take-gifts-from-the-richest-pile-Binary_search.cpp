/*
    Binary search
    Time complexity: O(nlogn+k(logn+n)+n)
    Space complexity: O(1) 
*/
class Solution {
    public:
        long long pickGifts(std::vector<int>& gifts, int k) {
            //std::vector<int> sorted_gifts=gifts;
            std::sort(gifts.begin(),gifts.end()); // O(nlogn)
            
            //O(k(logn+n))
            while(k--){
                int g=gifts.back();
                gifts.pop_back();
                g=floor(sqrt(g));
                std::vector<int>::iterator pos=std::upper_bound(gifts.begin(),gifts.end(),g);
                gifts.emplace(pos,g);
            }

            // O(n)
            long long ans=std::accumulate(gifts.begin(),gifts.end(),0*1ll);
            
            return ans;
        }
};