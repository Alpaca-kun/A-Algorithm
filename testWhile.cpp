#include <iostream>

using namespace std;

int main () {
  int a[] = {3, 5, 6, 7, 0, 1};
  int i = 0;
  
  while (a[i] != 0) 
    i++;

  cout << "valor de i: " << i << endl;
}
