/*
    Sorting+swap counting
    Time complexity: O(2nlogn+n)
    Space compelxity: O(2n)
*/
class Solution{
    public:
        bool areAlmostEqual(std::string& s1, std::string& s2) {
            int n=s1.size();

            // Save originals strings
            std::string s11=s1,s22=s2;

            // Sort both saved strings
            std::sort(s11.begin(),s11.end());
            std::sort(s22.begin(),s22.end());

            // If there are not eqaul return false
            if(s11!=s22) return false;
            
            // Otherwise, count number of swaps on original strings
            // If we found two different letters on same postion, means we need a swap
            // means for 1 swap, we count 2 (for 1 swap, we have 2 pairs of different letters at same index)
            int count_pairs=0;
            for(int i=0;i<n;++i){
                count_pairs+=(s1[i]!=s2[i]);
                
                // If #pairs of different letters at same position is more than 2, return false
                if(count_pairs>2) return false; 
            }

            return true;
        }
};