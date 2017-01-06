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
  arrayOfTable actualTable = {5, 1, 2, 3, 16, 6, 7, 4, 9, 10, 11, 12, 13, 14, 8, 15};
  // 5 1 2 3 0 6 7 4 9 10 11 8   13  14 15 12
  // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0, 15
  int error = 0,
      xMove, yMove;

  for (int i = 0; i < 16; i++) { 
    if (actualTable[i] == 0)
      actualTable[i] = 16;

    if (actualTable[i] != i + 1) {
      yMove = abs(((actualTable[i] - 1) / 4) - (i / 4)) ; 
      // quantos mov. requere-se para chegar na pos. y adequada
      xMove = abs(((actualTable[i] - 1) % 4) - (i % 4)) ; 
      // quantos mov. requere-se para chegar na pos. x adequada
      error += (yMove + xMove);
    }
    else 
      continue;

    if (actualTable[i] == 16)
      actualTable[i] = 0;
  }


  cout << "numero de erro: " << error << endl;
}
