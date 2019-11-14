#include <exception>
#include <iostream>
#include <vector>
#include <assert.h>     /* assert */

using namespace std;

struct Node{ // int val, Node* previous, Node* next
    int value;
    Node* next;
    Node* previous;
    // Node(){}
    Node(int x){ // start
        value = x;
        next = nullptr;
        previous = nullptr;
    }

    Node(int x, Node* p){
        value = x;
        previous = p;
        next = nullptr;
    }

    Node(int x, Node* p,  Node* n){
        value = x;
        next = n;
        previous = p;
    }
};

class LinkedList {
// -- private
  private:
// variables
    Node *head, *tail;
    int size = 0;
// get
    Node *get_node(int index){
        // in range
        if (index >= 0 and index < size){
            
            if (index > (size/2)){ // start from tail
                Node* current = tail;
                for (int i = size-1; i> index; i--){
                    current = current->previous;
                }
                return current;
            } else { // start from head
                Node* current = head;
                for (int i = 0; i < index; i++){
                    current = current->next;
                }
                return current;
            }
        // in -range
        } else if (index < 0 && -index < size){
            Node* current = tail;
            for (int i = size-1; i < -index; i--){
                current = current->previous;
            }
            return current;
        // else
        } else  {
            throw range_error("Index Error: Index out of range! (get_node)");
        }
    }
// modifiers
    // implemented since i have seen it in lecture and in examples from other places
    void push_front(int val){
        Node* new_node = new Node(val, nullptr, head);
        head->previous = new_node;
        head = new_node;
        size++;
    }
    void push_back(int val){
        Node* new_node = new Node(val, tail, nullptr);
        tail->next = new_node;
        tail = new_node;
        size++;
    }

    
// methods
    bool in_range(int index){
        if (abs(index) < size){
            return true;
        } else {
            return false;
        }
    }
// -- public
  public:
// constructor
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    LinkedList(vector<int> values){
        for (int value : values){
            append(value);
        }
    }
// destructor
    ~LinkedList(){ // del all
        Node *current, *next;
        
        current = head;
        while (current != nullptr){
            next = current->next;
            delete current;
            current = next;
            size = 0;
        }
    }
// properties
    int length(){
        return size;
    }
// operators
    int& operator[](int index){
        Node* current = get_node(index);
        return current->value;
    }
// modifiers
    void append(int x){ // adding val to end
        if (head == nullptr){ // first val
            Node* new_node = new Node(x);
            head = new_node;
            tail = new_node;
            size++;
        } else{
            push_back(x);
        }
        
    }
    void insert(int val, int index){
        if (index == 0){ // add to fron
            push_front(val);
            return;
        } else if (index == size-1 || index == -1){ // add to back
            push_back(val);
            return;
        }
        if (in_range(index)){ // in range of the list
            Node* previous = get_node(index-1);
            Node* tmp = previous->next;
            Node* new_node = new Node(val, previous, tmp);
            previous->next = new_node;
            tmp->previous = new_node;
            size++;
        } else { // error exception
            print();
            cout << "insert: val, index: " << val << ", " << index << endl;
            throw range_error("IndexError: Index out of range! (insert)");
            // return;
        }    
    }
    void remove(int index){
        if (in_range(index)){
            Node* current = get_node(index);
            if (current->previous == nullptr){ // if current == head, is head
                head = head->next;
                head->previous = nullptr;
            } else if (current->next == nullptr){ // if current == tail, is tail
                tail = tail->previous;
                tail->next = nullptr;
            } else { // is in range
                Node* prev = current->previous;
                Node* next = current->next;
                prev->next = next;
                next->previous = prev;
            }
            size--;
            // delete current;
        }
         else { // not in range
            throw range_error("IndexError (remove) ");
        }
    }
    int pop(){
        int x = tail->value;
        remove(-1);
        return x;
    }
    int pop(int index){
      if (!in_range(index)) {
        throw range_error("IndexError: Index out of range");
        }
    Node *tmp = get_node(index);
    int x = tmp->value;
    remove(index);
    return x;
    }

// methods
    void print(){
        cout << "size: " << size << endl;
        Node* current = head;
        cout << "[";
        while (current->next != nullptr){
            cout << current->value << ", ";
            current = current->next;
        }
        cout << current->value << "]" << endl;  
    
    }
};

int main(){
// init
    cout << endl;
    LinkedList list;

// checking append and print
    cout << "checking append and print: " << endl;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.print();
    cout << endl;

// checking operator[](int)
    cout << "checking operator[](int): " << endl;
    cout << "list[0]: " << list[0] << endl;
    cout << "list[2]: " << list[2] << endl;
    cout << "list[3]: " << list[3] << endl;
    cout << "list[-1]: " << list[-1] << endl;
    list.print();
    cout << endl;

// checking insert(int val, int index)
    cout << "insert(int val, int index): " << endl;
    list.insert(10,0);
    list.insert(20,3);
    list.insert(30, -1);
    list.print();
    cout << endl;

// cheking remove(int)
    cout << "remove(int), 0, -1 " << endl;
    list.remove(0);
    list.remove(-1);
    list.print();
    cout << endl;
    
// checking pop and pop(int index)
    cout << "pop: " << endl;
    list.pop();
    list.print();
    cout << "pop(int): " << endl;
    list.pop(1);
    list.print();
    cout << endl;

// checking LinkedList(vector<int>)
    cout << "LinkedList(vector<int>): " << endl;
    vector<int> vec = {100,200,300,400,500};
    LinkedList list_vector(vec);
    list_vector.print();
    return 0;
    
};