#include <exception>
#include <iostream>
#include <vector>
#include <assert.h>     /* assert */

using namespace std;

struct Node{
    int value;
    Node* next;
    Node* previous;

    Node(int v){ // v
        value = v;
    }
    Node(int v, Node* p, Node* n){ // v, p, n
        value = v;
        previous = p;
        next = n;
    }
};

class CircLinkedList{
// -- private
private:
// data
    Node* head;
    // Node* tail; head->previous = tail;
    int size;
// get
    Node* get_tail(){
        return head->previous;
    }
    Node* get_head(){
        return head;
    }
// set
    void set_head_next(Node* n){ // head->next = n
        get_head()->next = n;
    }
    void set_head_previous(Node* p){
        get_head()->previous = p;
    }
    void set_tail_next(Node* n){ // head->previous->next = n | tail->next = n
        get_tail()->next = n;
    }
    void set_tail_previous(Node* p){
        get_tail()->previous = p;
    }
// modifiers
    void first_node(int val){
        Node* new_node = new Node(val, nullptr, nullptr);
        head = new_node;
        set_head_previous(head); // head->previous = head
        set_head_next(head); // tail->next = head
    }
    void push_back(int val){
        Node* new_node;
        if (head == nullptr){ // list is empty
           first_node(val); // add first node.
        } else {
            new_node = new Node(val, get_tail(), get_head());
            set_tail_next(new_node); // tial->next = new_node
            set_head_previous(new_node); // head->previous = new_node
        }
        // cout << "new_node, val, p, n: " << new_node <<", "<< new_node->value <<", "<< new_node->previous <<", "<< new_node->next <<endl
        size++;
    }
// methods
// -- public
public:
// constructor
    CircLinkedList(){
        head = nullptr;
        size = 0;
    }
    CircLinkedList(int n){
        head = nullptr;
        size = 0;
        for (int i = 1; i<=n; i++){
            append(i);
        }
    }
    CircLinkedList(vector<int> values){
        head = nullptr;
        size = 0;
        for (int value : values){
            append(value);
        }
    }

// destructor
// getters
    int get(int index){
        return get_node(index)->value;
    }
    Node* get_node(int index){ // get val from index
        if (head == nullptr){ // if list is empty
            throw range_error("IndexError: empty list! (get_node)");
        }
        int step = index % size;
        if (step < 0){
            step = length()+step;
        }
        Node* current = head;
        if (step <= length()/2){
            for (int i = 0; i<step; i++){ // forward
                current = current->next;
            }
        } else {
            for (int i = length(); i>step; i--){ // backwards
                current = current->previous;
            }
        }
        return current;
    }

// operators
    int operator[](int index){
        // int& val = get(index);
        return get(index);
    }

// properties
    int length(){
        return size;
    }

// modifiers
    void append(int val){
        push_back(val);
    }
    void remove(int index){
        Node* current = get_node(index);
        remove(current);
    }
    void remove(Node* current){
        Node* before = current->previous;
        Node* after = current->next;
        after->previous = before;
        before->next = after;
        if (current == head){
            head = current->next;
        }
        size--;
        // delete current;
    }
    int pop(){
        Node* tail = get_tail();
        return pop(tail);
    }
    int pop(int index){
        Node* current = get_node(index);
        return pop(current);

    }
    int pop(Node* current){
        int val = current->value;
        remove(current);
        return val;
    }

// methods
    void print(){
        Node* current = head;
        cout << "[";
        for (int i = 0; i<length()-1; i++){ // for i in range(len(self))
            cout << current->value << ", ";
            current = current->next;
        }
        cout << current->value << ", ...]" << endl;

    }
    void walk(int n){
        Node* current = get_head();
        cout << "[";
        for (int i = 0; i<(length()*n); i++){
            cout << current->value << ", ";
            current = current->next;
        }
        cout << "]" << endl;

    }
    vector<int> josephus_sequence(int k){
        Node* current = head;
        Node* after;
        vector<int> removed;

        while (length() > 0){
            for(int i = 1; i<k; i++){
                current = current->next;
            }
            removed.push_back(current->value);
            after = current->next;
            remove(current);
            current = after;

        } 
        return removed;
    }
};

int last_man_standing(int n, int k){
    CircLinkedList list_men(n);
    vector<int> kill_order = list_men.josephus_sequence(k);
    return kill_order.back();
}


int main(){
// init
    cout << endl;
    CircLinkedList list;


// checking append and print
    cout << "checking append and print: " << endl;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.walk(3);
    // list.print();
    cout << endl;


// checking operator[](int)
    cout << "checking operator[](int): " << endl;
    for (int i = 10; i>=-10; i--){
        cout << "list[" << i << "]: " << list[i] << endl;
    }
    list.print();
    cout << endl;


// cheking josephus_sequence(int k)
    int n_t= 68;
    int k_t = 7;
    CircLinkedList j_list(n_t);
    vector<int> j_vector = j_list.josephus_sequence(k_t);
    for (int val : j_vector){
        cout << val << ", ";
    }
    cout << endl;

// 4g
    int n = 68;
    int k = 7;
    int last_man = last_man_standing(n,k);
    cout << "last man standing (n: " << n << ", k: " << k << "): " << last_man << endl;



// cheking remove(int)
    cout << "remove(int), 0, -1 " << endl;
    list.print();
    list.remove(0);
    list.remove(list.length()-1);
    list.print();
    list.walk(3);
    cout << endl;




// // checking insert(int val, int index)
//     cout << "insert(int val, int index): " << endl;
//     list.insert(10,0);
//     list.insert(20,3);
//     list.insert(30, -1);
//     list.print();
//     cout << endl;

    
// checking pop and pop(int index)
    cout << "pop: " << endl;
    list.append(10);
    list.append(20);
    list.print();
    list.pop();
    list.print();
    cout << "pop(int): (1)" << endl;
    list.pop(1);
    list.print();
    cout << endl;

    return 0;
    
}
