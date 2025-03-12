/*
 * @lc app=leetcode id=1415 lang=cpp
 *
 * [1415] The k-th Lexicographical String of All Happy Strings of Length n
 */

// @lc code=start
/*
    Math: Select and shrink the group of the k-th happy string
    Time complexity: O(n)
    Space complexity: O(1)
*/
class Solution {
    public:
        std::string getHappyString(int n, int k) {
            // Count total happy string in each group
            int group_count=1<<(n-1);

            // Count total number of happy strings
            int happy_count=3*group_count;

            // If k exceeds the total number of happy strings
            if(k>happy_count) return "";

            // Determine which group belongs the k-th happy string ('a','b' or 'c')
            int group=ceil(k*1.0/group_count*1.0);

            // Update k of the k-th happy string in the its group 
            k=k-(group-1)*group_count;

            std::string ans; // Generated happy string
            ans.push_back((group-1)+'a'); // We know, which group belong the k-th happy string

            // Map each group 'a','b' and 'c' with its two options
            std::vector<std::vector<char>> mapping={{'b','c'},{'a','c'},{'a','b'}};

            // Build the remaining answer letters, by going down in the tree and 
            // selecting the correspondent group of the k-th happy string
            for(int i=1;i<n;++i){
                group_count/=2;
                group=ceil(k*1.0/group_count*1.0);
                k=k-(group-1)*group_count;
                ans+=mapping[ans.back()-'a'][group-1];
            }
            
            return ans;
    
        }
};
// @lc code=end

