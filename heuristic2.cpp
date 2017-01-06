#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <set>
#include <array>
#include <cmath>

#define solution "00010203040506070809101112131415";

using namespace std;
//using namespace *** costs more

typedef unordered_map <string, int> uMap;
typedef priority_queue <int, vector<int>, greater<int>> pQueue;
typedef multiset <int> mSet;
typedef array <int, 16> arrayOfTable;

int main () {
  arrayOfTable actualTable = {16, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  // 11, 12, 13, 9, 10, 1, 2, 16, 14, 15, 6, 7, 3, 4, 5, 8
  // 5, 1, 2, 3, 16, 6, 7, 4, 9, 10, 11, 12, 13, 14, 8, 15
  // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0, 15
  int error = 0,
	  reference = actualTable[0];

  for (int i = 1; i < 16; i++) {
    cout << "i = " << i << " reference = " << reference << endl;
    cout << "error = " << error << endl;
    if (++reference != actualTable[i]) {
	  if (reference < 16) 
        error++;
      reference = actualTable[i];
    }
  }

  cout << "numero de erro: " << error << endl;
}
