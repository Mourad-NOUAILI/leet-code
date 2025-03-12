/*
 * @lc app=leetcode id=2182 lang=cpp
 *
 * [2182] Construct String With Repeat Limit
 */

// @lc code=start
/*
    map+Max heap
    Time complexity: O(n(logn+logk))
    Space complexity: O(2k)
    n: Length of s
    k: Number of unique characters in s
    if s consists of lowercase English letters, then k=26
*/
class Solution {
    public:
        std::string repeatLimitedString(std::string s, int repeatLimit) {
            std::map<char,int> freq;
            for(auto& c: s) freq[c]++;

            std::priority_queue<char> max_heap;
            for (auto& [c,_]: freq) max_heap.push(c);
                
            std::string ans;
            while(!max_heap.empty()){
                char c=max_heap.top();
                max_heap.pop();

                int f=freq[c];

                int count=std::min(f,repeatLimit);
                for(int i=1;i<=count;i++) ans.push_back(c);

                freq[c]-=count;                

                if(freq[c]>0 && !max_heap.empty()){
                    char next_c=max_heap.top();
                    max_heap.pop();

                    ans.push_back(next_c);
                    freq[next_c]--;

                    if(freq[next_c]>0)  max_heap.push(next_c);

                    max_heap.push(c);
                }
            }
            return ans;
        }
};
// @lc code=end

