/*
    Hash map+Naive way to compute distinct colors
    Time complexity: O(m^2)
    Space complexity: O(n+m)
    n: #balls
    m: #colors
*/

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution{
    public:
        vi queryResults(int n, vvi& queries){
            vi ans;
            
            // Track colored balls and compute the frequency of each color
            std::unordered_map<int,int> balls,color_freq;

            // For each query
            for(auto& query: queries){
                int ball=query[0];
                int color=query[1];

                // If the ball is colored before, reduce the frequency of its color
                if(balls[ball]) color_freq[balls[ball]]--;

                // Color the ball
                balls[ball]=color;

                // Increment the frequency ph the color
                color_freq[color]++;

                // Iterate oven the colors and compute the colors with frequencies
                // different to 0. Means, the colors which still exsist
                int distinct_colored_balls=0;
                for(auto& [color,f]: color_freq) if(f>0) distinct_colored_balls++;

                // Update the answer table.
                ans.push_back(distinct_colored_balls);
            }

            return ans;
        }
};