class Solution {
public:
    static int scoreOfString(string& s) {
        adjacent_difference(s.begin(), s.end(), s.begin());
        
        //sum the absolute values of the differences, starting from the second element
        return accumulate(s.begin()+1, s.end(), 0, [](int x, int y){
            return x+abs(y);
        });
    }
};


class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        int n=s.size();
        for(int i=0;i<n-1;++i) sum+=abs((s[i]-'a')-(s[i+1]-'a'));
        return sum;
    }
};
