/*
 * Open List -> armazenar ordenadamente as possibilidades abertas de um nó, podendo abrir no máximo por 4 nó
 * Closed List -> armazenar todos os nós já visitados
 * Map -> concatenação das listas, para verificar a existência de uma possibilidade
 * 
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>

#define solution "00010203040506070809101112131415";

using namespace std::tr1;
//using namespace *** cost more

typedef struct 

typedef unordered_map <string, int> unoMap;
typedef priority_queue <int> prioQue;

int verifyError (int actualTable[]) {
  int error = 0;

  for (int i = 0; i < 15; i++)
    if (actualTable[i] != i + 1)
      error++;

  if (actualTable[i] != 0)
    error++;

  return error;
}

string intToString () {
  string s;

  for (int i = 0; i < 16; i++) {
    cin >> initialTable[i];
    if (initialTable[i] < 10)
      s += "0";
    s += to_string(initialTable[i]);
  }

  return s;
}


int heuristicOne () {
  int initialTable[16];
  int totalCost = 0,
      height = 0,
      heuristic = 0;
}

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
