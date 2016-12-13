#include <iostream>
#include <tr1/unordered_map>
#include <tr1/string>
#include <tr1/queue>

#define solution "00010203040506070809101112131415";

using namespace std;
using namespace tr1;
//using namespace *** cost more

typedef unordered_map <string, int> setOfLists;
typedef priority_queue <int> openList;


int main () {
  int initialTable[16];
  int heuristic = 0;
  string s;

  for (int i = 0; i < 16; i++) {
    cin >> initialTable[i];
    if (initialTable[i] < 10)
      s += "0";
    s += to_string(initialTable[i]);
  }

  

}
