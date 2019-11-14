#include <iostream>
using namespace std;



bool is_prime(int x){
  if (x <= 1)
    return false;
  for (int i = 2; i < x; i++)
    if (x%i == 0)
        return false;
   return true;
}

int main() {

  for (int i = 0; i < 15; i++) {
    if (is_prime(i)) {
      cout << i << '\n';
    }
  }



  return 0;
}
