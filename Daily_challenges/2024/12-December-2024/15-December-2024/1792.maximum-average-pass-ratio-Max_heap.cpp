/*
 * @lc app=leetcode id=1792 lang=cpp
 *
 * [1792] Maximum Average Pass Ratio
 */

// @lc code=start
/*
    max heap
    Time complexity: O(n+mlogn)=O(mlogn)
    Space complexity: O(n)
    n: #classes
    m: #extra students
*/
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<double> vd;
typedef std::pair<double,int> di;
typedef std::vector<di> vdi;

class Solution {
    public:
        double maxAverageRatio(vvi& classes,int extraStudents){
            int n=classes.size();
            vd ratios;
            std::priority_queue<di,vdi> max_heap;
            for(int i=0;i<n;++i){
                int pass=classes[i][0];
                int total=classes[i][1];
                double ratio=pass*1.0/total*1.0;
                ratios.push_back(ratio);

                // Compute all contributions as if we add one extra student to all classes
                double new_ratio=(pass+1)*1.0/(total+1)*1.0;
                max_heap.push({new_ratio-ratio,i});
            }

            while(extraStudents--){
                // Get the class with maximum contribution
                auto[mx_contribution,which_class]=max_heap.top();
                max_heap.pop();

                // Update data of that class (pass,total and ratio)
                classes[which_class][0]++;
                classes[which_class][1]++;                
                ratios[which_class]+=mx_contribution;

                // Compute the new contibution of that class
                int pass=classes[which_class][0];
                int total=classes[which_class][1];
                double new_ratio=(pass+1)*1.0/(total+1)*1.0;

                // Update the max hap, with the contribution one that class
                max_heap.push({new_ratio-ratios[which_class],which_class});
    
            }

            double ans=std::accumulate(ratios.begin(),ratios.end(),0.0)/n*1.0;

            return ans;
        }
};
// @lc code=end

