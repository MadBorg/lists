#include<iostream>

using namespace std;

struct Node{

  Node *next;
  int value;

  Node(int n){
    value = n;
  }

};

class CircularLinkedlist{

private:
  int size;
  Node *head;



public:

  CircularLinkedlist(){

  head = nullptr;
  size = 0;
}


CircularLinkedlist(int c){

  head = nullptr;
  size = 0;
  for (int i = 0; i <= c; i++) {
    append(i);
  }
}

int& operator[](int data){
  if (data < = 0) {
    throw out_of_range();
  }
  if (data > size) {
    data = data - size;
  }
  Node* tmp = head;
  for (int i = 0; i < data; i++) {
    tmp = tmp->next;
  }
  return tmp->value;
}

void append(int value) {
    size++;
    if (head == nullptr) {
        head = new Node(value);
    } else {
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = new Node(value);
    }
}
void print() {
    Node *current = head;

    cout << "[";
    while (current != nullptr) {
        cout << current->value;
        current = current->next;
        if (current != nullptr) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}
vector<int> josephus_sequence(int k){

}
int last_man_standing(n, k){

}

};
