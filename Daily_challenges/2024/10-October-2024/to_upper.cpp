#include<bits/stdc++.h>

void to_upper_case(std::string& s){
    int n=s.size();
    for(int i=0;i<n;++i){
        if(s[i]>='a'&&s[i]<='z') s[i]=(int(s[i]) ^ 32);
    }
}

int main(){
    int t;
    std::cin>>t;
    while(t--){
        std::string s;
        std::cin>>s;
        to_upper_case(s);
        std::cout<<s<<'\n';
    }
}