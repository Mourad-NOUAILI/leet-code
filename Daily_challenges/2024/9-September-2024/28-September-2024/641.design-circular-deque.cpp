/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 */

// @lc code=start
/*
    Double linked list
    Time & space complexity:
    all functions are O(1)
*/
class MyCircularDeque{
    public:
        // Create double linked list node
        class Node{
            public:
                int val;
                Node* next;
                Node* prev;
            public:
                Node(int val,Node* next,Node* prev):val(val),next(next),prev(prev){}
        };
        // head and tail
        Node* head=nullptr;
        Node* tail=nullptr;

        // Actual size
        int _size;

        // max size
        int _capacity;
    public:
        MyCircularDeque(int k) {
            _size=0;
            _capacity=k;
        }
        
        bool insertFront(int value) {
            if(isFull()) return false;
            if(!head) head=tail=new Node(value,nullptr,nullptr);
            else{
                Node* new_node=new Node(value,head,nullptr);
                head->prev=new_node;
                head=new_node;
            }
            _size++;
            return true;
        }
        
        bool insertLast(int value) {
            if(isFull()) return false;
            if(!tail) head=tail=new Node(value,nullptr,nullptr);
            else{
                Node* new_node=new Node(value,nullptr,tail);
                tail->next=new_node;
                tail=new_node;
            }
            _size++;
            return true;
        }
        
        bool deleteFront() {
            if(isEmpty()) return false;
            Node* tmp=head;
            if(_size>1){
                head=head->next;
                head->prev=nullptr;
                tmp->next=nullptr;
            }
            else head=tail=nullptr;
            delete tmp;
            _size--;
            return true;
        }
        
        bool deleteLast() {
            if(isEmpty()) return false;
            Node* tmp=tail;
            if(_size>1){
                tail=tail->prev;
                tail->next=nullptr;
                tmp->prev=nullptr;
            }
            else head=tail=nullptr;
            delete tmp;
            _size--;
            return true;
        }
        
        int getFront() {
            if(isEmpty()) return -1;
            return head->val;
        }
        
        int getRear() {
            if(isEmpty()) return -1;
            return tail->val;
        }
        
        bool isEmpty() {
            return _size==0;
        }
        
        bool isFull() {
            return _size==_capacity;
        }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

