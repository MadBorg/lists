#include <exception>
#include <iostream>
#include <vector>
#include <assert.h>     /* assert */

using namespace std;

class ArrayList {
   public:
    int size = 0;

   private:
    int* data;
    int capacity = 2;
    int growth = 2;

    int& get_size(){
        return size;
    }
    void resize() {
        capacity *= growth;
        int* tmp = new int[capacity];
        for (int i = 0; i < size; i++) {
            tmp[i] = data[i];
        }
        delete[] data;
        data = tmp;
    }

   public:
// constructor
    ArrayList() {
        data = new int[capacity];
    }
   // a vector constructor
    ArrayList(vector<int> my_vector){
      data = new int[capacity];
      for (int element : my_vector) {
        append(element);
      }
    }
// destructor
    ~ArrayList() {
        delete[] data;
    }
// get
    int& get(int i) {
        if ((i < size) && (i >= 0)) {
            return data[i];
        } else {
            throw out_of_range("Index out of range (get)");
        }
    }
// properties
    int length() {
      return size;
    }
// operators
    int& operator[](int i) {
        return get(i);
    }
// modifyers
    void append(int x) {
        if (size >= capacity) {
            resize();
        }
        data[size] = x;
        size++;
    }
    void insert(int val, int index){
        if (index < 0 || index > size) {
            throw out_of_range("IndexError");
        }
        size++;   
        for(int i = size-1; i > index; i--){
            data[i]= data[i-1];
        }
        data[index]=val;
    }
    void remove(int index){
        if (index >= 0 && index < size){
            for (int i=index; i<size-1; i++){
                data[i]= data[i+1];
            }
            pop();
        } else {
            throw out_of_range("Index out of range (insert)");
        }
    }
    int pop(int index){
      int x = data[index];

      if (index < 0 || index > size) {
        throw out_of_range("IndexError");
      }
      remove(index);
      return x;
  }

    int pop(){
        int x = data[size-1];
        size--;
        return x;
    }
// methods
    void print(){
        if (size == 0){
            cout << "[]" << endl;
        } else {
            cout << "[";
            for (int i=0; i < size-1; i++){
                cout << data[i]<< " , ";
            }
        cout << data[size-1] << "]" << endl;
        }
    }
    void shrink_to_fit(){
        int n = 2;
        int smaller;
        while (smaller < size){
            smaller = 2^n;
            n++;
        }
        
        // Copy
        ArrayList shrinked;
        for(int i=0; i<size; i++){
            shrinked.append(get(i));
        }
        // define new data, and fill it with data.
        // Paste
        size = 0;
        int* data = new int[smaller];
        for(int i=0; i<shrinked.get_size(); i++){
            append(shrinked[i]);
        }
    }
};

// tests
bool is_prime(int x){
  if (x <= 1)
    return false;
  for (int i = 2; i < x; i++)
    if (x%i == 0)
        return false;
   return true;
}

void test_array_list(){
    ArrayList list;
    for (int i = 1; list.length() < 50; i++){
        if (is_prime(i)){
            list.append(i);
        }
    }
    vector<int> test_vector{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    for (int i = 0; i<10; i++){
        int oberved_val = list.get(i);
        int test_val = test_vector[i];
        assert(oberved_val == test_val);
    }
}

void test_array_list_init_vector(){
    vector<int> in_vector{1,2,3,10};
    // cout << "here" << endl;
    ArrayList out_vector(in_vector);
    out_vector.append(1);
    for (int i=0; i<in_vector.size(); i++){
        int in_int = in_vector[i];
        int out_int = out_vector.get(i);
        // cout << in_int << ", " << out_int << endl;
        // assert(in_int == out_int);
    }

}

int main() {
    ArrayList list;
    cout << " init size 0" << endl;
    list.print(); // todo: 
    list.insert(10, 0);
    cout << "insert: " << endl;
    list.print();
    list.insert(11, 0);
    list.append(12);list.append(15);list.append(16);list.append(20);list.append(100);
    cout << " insert and append" << endl;
    list.print();
    list.remove(2);
    cout << "remove " << endl;
    list.print();
    return 0;
}
