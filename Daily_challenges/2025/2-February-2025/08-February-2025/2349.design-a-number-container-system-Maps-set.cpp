/*
 * @lc app=leetcode id=2349 lang=cpp
 *
 * [2349] Design a Number Container System
 */

// @lc code=start
/*
    Hash maps+ordered set
    Time complexity:
    ***change(int,int): O(logn)
    ***find(int): O(1)
    ***overall: O(q.logn), q:#queries
    Overall space complexity: O(n)
*/
class NumberContainers {
    private:
        std::unordered_map<int,std::set<int>> number_indexes;
        std::unordered_map<int,int> index_number;

    public:
        NumberContainers() {
            
        }
        // O(logn)
        void change(int index, int number) {
            if(index_number.find(index)!=index_number.end()){
                int old_number=index_number[index];
                auto it=number_indexes[old_number].find(index);
                if(it!=number_indexes[old_number].end()) number_indexes[old_number].erase(it);
            }
            index_number[index]=number;
            number_indexes[number].insert(index);
        }
        // O(1)
        int find(int number) {
            return !number_indexes[number].empty()?*number_indexes[number].begin():-1;
        }
};


/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
// @lc code=end

