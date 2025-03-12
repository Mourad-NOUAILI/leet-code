/*
 * @lc app=leetcode id=1792 lang=cpp
 *
 * [1792] Maximum Average Pass Ratio
 */

// @lc code=start
/*
    Brute force
    Time complexity: O(n+m*n)=O(m.n)
    Space complexity: O(n)
    n: #classes
    m: #extra students
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<double> vd;
class Solution {
    public:
        double maxAverageRatio(vvi& classes,int extraStudents){
            int n=classes.size();

            // Compute initial students
            vd ratios;
            for(auto& c: classes){
                int pass=c[0];
                int total=c[1];
                ratios.push_back(pass*1.0/total*1.0);
            }

            // While we have extra brillant students
            while(extraStudents--){
                // Determine the class that will more contibute on the average pass ratio
                int which_class=0;
                double mx_contribution=DBL_MIN;
                for(int i=0;i<n;++i){
                    vi c=classes[i];
                    int pass=c[0]+1;
                    int total=c[1]+1;
                    double ratio=(pass*1.0)/(total*1.0);
                    double delta=ratio-ratios[i];
                    if(delta>mx_contribution){
                        mx_contribution=delta;
                        which_class=i;
                    }
                }

                // Update data of that class (pass,total and ratio)
                classes[which_class][0]++;
                classes[which_class][1]++;
                ratios[which_class]+=mx_contribution;
            }
            
            double ans=std::accumulate(ratios.begin(),ratios.end(),0.0)/n*1.0;

            return ans;
        }
};
// @lc code=end

