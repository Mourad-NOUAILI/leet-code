/*
    Hash map+erase non-existing colors
    Time complexity: O(m)
    Space complexity: O(n+m)
    n: #balls
    m: #colors
*/

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution{
    public:
        vi queryResults(int n, vvi& queries) {
            vi ans;

            // Track colored balls and compute the frequency of each color
            std::unordered_map<int,int> balls,color_freq;

            int distinct_colored_balls=0; // To track the distinct colors
            for(auto& query: queries){
                int ball=query[0];
                int color=query[1];

                //If the ball is colored before, reduce the frequency of its color
                if(balls[ball]){
                    color_freq[balls[ball]]--;
                    // If the color of the current ball does not exist any more, remove
                    // its color from the hash map
                    if(!color_freq[balls[ball]]) color_freq.erase(balls[ball]);
                }

                // Increment the frequency ph the color
                color_freq[color]++;

                // Color the ball
                balls[ball]=color;

                // Update the answer table
                ans.push_back(color_freq.size());
            }

            return ans;
        }
};