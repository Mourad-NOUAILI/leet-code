/*
 * @lc app=leetcode id=1352 lang=cpp
 *
 * [1352] Product of the Last K Numbers
 */

// @lc code=start

/*
    Prefix product
    Overall time complexity: O(n+m)
    Overall space complexity: O(2n)
    n: #add queries
    m: #getProduct queries
*/
typedef unsigned long long ll;
typedef std::vector<ll> vll;

class ProductOfNumbers{
    private:
        vll prefix_zeros,prefix_prod;
    public:
        // Time complexity: O(1)
        // Space complexity: O(1)
        ProductOfNumbers(){
            prefix_zeros.push_back(0);
            prefix_prod.push_back(1);
        }

        // Time complexity: O(1)
        // Space complexity: O(2n)
        void add(int num){
            ll prev_prod=prefix_prod.back();
            ll prev_zeros=prefix_zeros.back();
            if(num==0){
                prefix_prod.push_back(1);
                prefix_zeros.push_back(prev_zeros+1);
            }
            else{
                prefix_prod.push_back(prev_prod*num*1ll);
                prefix_zeros.push_back(prev_zeros);
            }
        }

        // Time complexity: O(1)
        // Space complexity: O(1)
        int getProduct(int k){
            int left=prefix_prod.size()-k-1;
            int right=prefix_prod.size()-1;
            return (int)(prefix_zeros[right]-prefix_zeros[left]!=0?0:prefix_prod[right]/prefix_prod[left]);
        }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end

