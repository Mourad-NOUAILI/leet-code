/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 */

// @lc code=start
#include<bits/stdc++.h>
/*
    Time complexity: O(m^2+mlogm+n)
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
            int n=formula.size();
            
            std::vector<std::string> formula_array;

            // O(n)
            store_in_array(formula,formula_array);

            std::stack<std::pair<std::string,int>> st;

            int m=formula_array.size();
            int i=0;
            //O(m^2)
            while(i<m){
                std::string e=formula_array[i];
                if(e=="(") {
                    st.push({"(",0});
                    i++;
                }
                else if(e!=")" && isupper(e[0])){
                    st.push({e,stoi(formula_array[i+1])});
                    i+=2;
                }
                else if(e==")"){ // O(m)
                    int w=stoi(formula_array[i+1]);
                    std::vector<std::pair<std::string,int>> tmp;
                    while(!st.empty() && st.top().first !="("){
                        st.top().second*=w;
                        tmp.push_back(st.top());
                        st.pop();
                    }
                    if(!st.empty()) st.pop();
                    for(auto& e: tmp) st.push(e);
                    i+=2;
                }
            }

            // Compute the frequency of each atom: O(mlogm)
            std::map<std::string,int> count;
            while(!st.empty()){
                count[st.top().first]+=st.top().second;
                st.pop();
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

