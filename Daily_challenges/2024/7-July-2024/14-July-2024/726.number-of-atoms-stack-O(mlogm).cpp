/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(mlogm+n)
    Extra space complexity: O(2m+2m+2m+2m) (formula_array,stack,tmp array,count map)

    "H2O"
    "Mg(OH)2"
    "Mg(H2O)N"
    "K4(ON(SO3)2)2"
    "TpNO(OTp2(SO3)4(MgNo2)13)2"
*/
class Solution {
    public:
        void store_in_array(std::string& formula,std::vector<string>& result){
            int n=formula.size();
            int i=0,j=0;
            while(i<n){
                char c=formula[i];
                if(c==')') {
                    result.push_back(")");
                    if(!isdigit(formula[i+1])) result.push_back("1");
                    i++;
                }
                else if(c=='(') {
                    result.push_back("(");
                    i++;
                }
                else if(isupper(c)){
                    std::string atom="";
                    atom+=c;
                    for(j=i+1;j<n;++j){
                        c=formula[j];
                        if(!islower(c)) break;
                        atom+=c;
                    }
                    i=j;
                    result.push_back(atom);
                    if(!isdigit(formula[j])) result.push_back("1");
                }
                else if(isdigit(c)){
                    std::string number="";
                    number+=c;
                    for(j=i+1;j<n;++j){
                        c=formula[j];
                        if(!isdigit(c)) break;
                        number+=c;
                    }
                    i=j;
                    result.push_back(number);
                }
            }
        }

        std::string countOfAtoms(std::string formula) {
            std::vector<std::string> formula_array;

            // O(n)
            store_in_array(formula,formula_array);

            int m=formula_array.size();

            std::stack<int> multiplicators_st;
            std::vector<int> multiplicators_arr(m);
            int mul=1;

            // O(m)
            for(int i=m-1;i>=0;--i){
                std::string c=formula_array[i];
                if(c==")"){
                    int x=stoi(formula_array[i+1]);
                    multiplicators_st.push(x);
                    mul*=x;
                    multiplicators_arr[i+1]=mul;
                }
                else if(c=="("){
                    int x=multiplicators_st.top();
                    multiplicators_st.pop();
                    mul/=x;
                }
                multiplicators_arr[i]=mul;
            }

            // Compute the frequency of each atom: O(mlogm)
            std::map<std::string,int> count;
            for(int i=0;i<m-1;++i){
                std::string s=formula_array[i];
                int w=1;
                if(std::isdigit(formula_array[i+1][0])) w=stoi(formula_array[i+1]);
                int cnt=multiplicators_arr[i];
                if(std::isupper(s[0])) count[s]+=(w*cnt);
            }

            // Generate the answer 
            std::string ans="";
            for(auto p: count){
                ans+=p.second==1?p.first:(p.first+std::to_string(p.second));
            }
            return ans;
        }
};
// @lc code=end

