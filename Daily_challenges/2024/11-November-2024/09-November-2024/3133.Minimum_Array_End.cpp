/*
    Consecutive ORing
    Time complexity: O(n)
    Space complexity=o(1)
*/
class Solution {
    public:
        long long minEnd(int n, int x){
            // First number is equal to x
            long long y=x;

            // For the next n-1 numbers: number are incresing
            // without changing the set bits.
            for(int i=1;i<n;++i) y=(y+1)|x;

            return y;
        }
};

/*
    Bits interleaving
    Time complexity: O(64)=O(1)
    Space complexity=o(1)
*/
typedef long long ll;
class Solution {
    public:
        ll minEnd(int n, int x){
            // Need the n-1 to interleave with x
            n--;

            // First number is equal to x
            // change x to long long
            ll y=x;     

            int i=0; // run over x
            int j=0; // run over n-1
            while(i<64){
                // In x: If the bit is set don't change it
                if(y&(1ll<<i)){
                    i++; // Go next bit
                    continue;
                }
                // if the i-th bit is not set in x, change it with the j-th set bit in n-1
                if(n&(1ll<<j)) y|=(1ll<<i);

                i++;
                j++;
            }
            return y;
        }
};