class Solution {
public:
    int numberOfChild(int n, int k) {
        int i=0;
        int dir=1;
        while(k>0){
            if(i+dir>=0 && i+dir<=n-1){
                i+=dir;
                k--;
            }
            else dir*=-1;
        }
        return i;
    }
     
};



class Solution {
public:
    int numberOfChild(int n, int k) {
        int complete_rounds=k/(n-1);
        int remain_rounds=k%(n-1);

        /*
            If complete rounds is even, we go left to complete the remaining rounds starting from 1
            Otherwise, we go right to complete the remaining rounds starting from n-1
        */

        
        return complete_rounds%2==0?remain_rounds:n-1-remain_rounds;
    }
     
};



