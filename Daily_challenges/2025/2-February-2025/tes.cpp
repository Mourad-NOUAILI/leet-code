#include<bits/stdc++.h>

typedef unsigned long long ull;

class BigNumber{
    private:
        std::string big_number;
    public:
        BigNumber(std::string big_number){
            this->big_number=big_number;
        }
        std::pair<std::string,ull> div_mod(ull divisor){
            std::string tmp_div;
            ull mod=0;
            for(int i=0;i<big_number.size();++i){
                int digit=big_number[i]-'0';
                mod=mod*10+digit;
                int q=mod/divisor;
                tmp_div+=std::to_string(q);
                mod%=divisor;
            }
            //std::cout<<tmp_div<<'\n';
            std::string div;
            for (auto& digit: tmp_div){
                if(digit!='0') div+=digit;
            }

            return {div,mod};
        }
};

std::string prime_factorization(std::string& n){
    if(n=='1') return "1^1";

    std::map<std::string,int> freq;
    // stuck here
    for(ull i=2;i*i<=n;++i){
        while(n%i==0){
            freq[i]++;
            n/=i;
        }
    }

    if(n>1) freq[n]++;

    std::string ans;
    for(auto& [p,f]: freq) ans+=std::to_string(p)+"^"+std::to_string(f)+" ";
    ans.pop_back();
    return ans;
}

/*std::string prime_factorization_naive(int n){
    if(n==1) return "1";
    std::string ans;
    int i=2;
    while(i*i<=n && n!=1){
        while(n%i==0){
            ans.push_back(i+'0');
            ans.push_back('*');
            n/=i;
        }
        i++;
    }
    
    if(n>1) ans+=std::to_string(n)+'*';

    ans.pop_back();

    return ans;
}*/

int main(){
    std::string n;
    while(std::cin>>n){
        if(n!='0')  std::cout<<prime_factorization(n)<<'\n';
        else break;
    }

    return 0;
}