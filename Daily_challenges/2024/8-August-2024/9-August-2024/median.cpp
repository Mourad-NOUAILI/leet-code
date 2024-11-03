#include<bits/stdc++.h>

int main(){
    int median=0;
    for(int c=1;c<=9;++c){
        std::cout << "Testing median...";
        int s=0;
        for(int i=1;i<=9;++i){
            if(i!=c) s+=i;
        }
        std::cout<<s/8.0<<'\n';
        if(static_cast<double>(s/8.0)-s/8==0.0) median=c;
    }
    std::cout<<"Median="<<median<<'\n';
    return 0;
}