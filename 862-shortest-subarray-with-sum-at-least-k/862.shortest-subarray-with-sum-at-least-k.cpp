/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 */

// @lc code=start
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        /*int n = nums.size();
        int INF = numeric_limits<int>::max();
        int ans = INF;
        long long s = 0;
        priority_queue< pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>> > PQ;
        for (int i = 0 ; i < n ; ++i){
            s += nums[i];
            if (s >= k) ans = min(ans,i+1);
            while(!PQ.empty() && s-PQ.top().first >= k){
                auto p = PQ.top();
                PQ.pop();
                ans = min(ans,i-p.second);
            }
            PQ.push({s,i});
        }
        return (ans != INF)?ans:-1;*/

        int n = nums.size();
        vector<long long> PS(n+1,0);
        for(int i = 1 ; i < n+1 ; ++i)
            PS[i] = PS[i-1] + nums[i-1];

        deque<int> DQ;

        int INF = numeric_limits<int>::max();

        int ans = INF;

        for (int i = 0 ; i < n+1 ; ++i){
            while (!DQ.empty() && PS[i]-PS[DQ.front()] >= k){
                ans = min(ans, i - DQ.front());
                DQ.pop_front();
            }

            while (!DQ.empty() && PS[i] < PS[DQ.back()]){
                DQ.pop_back();
            }

            DQ.push_back(i);
        }
        return (ans != INF) ? ans : -1;
    }
};
// @lc code=end

// [1]\n1\n --> 1
// [2,-1,2]\n3\n --> 3
// [1,2]\n4\n --> -1
// [1,2,2,1,3,0,1,2]\n3\n --> 1
// [1,2,0,1,3,0,1,2]\n4\n --> 2
// [17,85,93,-45,-2]\n150\n --> 2
// [-28,81,-20,28,-29]\n89\n --> 3