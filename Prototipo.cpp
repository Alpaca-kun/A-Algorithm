/*
 * Open List: armazenar ordenadamente as possibilidades abertas de um nó, podendo abrir no máximo por 4 nó -> Usar Priority Queue
 * Closed List: armazenar todos os nós já visitados -> usar Unordered Map
 * Map: concatenação das listas, para verificar a existência de uma possibilidade. Caso houver uma possibilidade, desconsiderar e pular
 * 
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <set>
#include <array>
#include <cmath>
#include <utility>

using namespace std;
//using namespace *** costs more

typedef unordered_map <string, int> uMap;
typedef priority_queue <int, vector<int>, greater<int>> pQueue;
typedef multiset <int> mSet;
typedef array <int, 16> arrayOfTable;

arrayOfTable solution = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

bool verifySolution (arrayOfTable actualTable) {
  if (solution == actualTable) 
    return true;
  else 
    return false;
}

int heuristicOne (arrayOfTable actualTable) {
  int error = 0;

  for (int i = 0; i < 16; i++)
    if (actualTable[i] != i + 1)
      error++;

  return error;
}

int heuristicTwo (arrayOfTable actualTable) {
  int error = 0,
      reference = actualTable[0];

  for (int i = 1; i < 16; i++) {
    if (++reference != actualTable[i]) {
      if (reference < 16)
        error++;
      reference = actualTable[i];
    }
  }

  return error;
}

int heuristicThree (arrayOfTable actualTable) {
  int error = 0,
      xMove, yMove;

  for (int i = 0; i < 16; i++) { 
    if (actualTable[i] != i + 1) {
      yMove = abs(((actualTable[i] - 1) / 4) - (i / 4)) ; 
      // quantos mov. requere-se para chegar na pos. y adequada
      xMove = abs(((actualTable[i] - 1) % 4) - (i % 4)) ; 
      // quantos mov. requere-se para chegar na pos. x adequada
      error += (yMove + xMove);
    }
    else 
      continue;
  }

  return error;
}

string intToString (arrayOfTable actualTable) {
  string s;

  for (int i = 0; i < 16; i++) {
    cin >> actualTable[i];
    if (actualTable[i] < 10)
      s += "0";
    s += to_string(actualTable[i]);
  }

  return s;
}

//Talvez nw precisa declarar uma funcao so para isso ;D
void swapSquare (arrayOfTable actualTable, int originalPostion, int destinyPostion) {
  swap(actualTable[originalPostion], actualTable[destinyPostion]);
}

int main () {
   arrayOfTable initialTable;

  for (int i = 0; i < 16; i++) {
    cin >> initialTable[i];
    if (initialTable[i] == 0)
      initialTable[i] = 16;
  }
}
