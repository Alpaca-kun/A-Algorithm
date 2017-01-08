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
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;
//using namespace *** costs more

typedef array <int, 16> arrayOfTable;
arrayOfTable solution = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

struct node {
  arrayOfTable key;
  int f;
  int g;
  int h;
  node *parent;
};

typedef unordered_map <arrayOfTable, node> uMap; //<chave, referencia>
typedef priority_queue <node> pQueue;
typedef multiset <int> mSet;

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

int heuristicFour (arrayOfTable actualTable) {
  int h1 = heuristicOne(actualTable),
      h2 = heuristicTwo(actualTable),
      h3 = heuristicThree(actualTable);

  //multiplicar algum peso as heuristicas
  return h1 + h2 + h3;
}

int heuristicFive (arrayOfTable actualTable) {
  int h1 = heuristicOne(actualTable),
      h2 = heuristicTwo(actualTable),
      h3 = heuristicThree(actualTable);

  return max(max(h1, h2), h3);
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

int discoverVacuumPostion (arrayOfTable actualTable) {
  int i = 0;
  
  while (actualTable[i] != 16) 
    i++;

  return i;
}

int aStar (arrayOfTable initialTable) {
  int height = 0;

  pQueue openList;
  uMap closedList, concatenateList;

  node parentNode;
  node childNode[4];
  node auxNode;

  openList.push(parentNode{initialTable, 0, 0, 0, NULL});

  while(!openList.empty()) {
    // liberar o primeiro elemento do opened list
    parentNode = openList.top();
    openList.pop();

    int numberOfChild = 0;
    int movablePiece = discoverVacuumPostion(auxNode.key);

    for (int i = 1; i <= 4; i += 3) {
      if (movablePiece - i > -1) {  
        childNode[numberOfChild] = auxNode;
        swap(childNode[numberOfChild].key[movablePiece], childNode[numberOfChild].key[movablePiece - i]);
        numberOfChild++;
      }

      if (movablePiece + i < 16) {  
        childNode[numberOfChild] = auxNode;
        swap(childNode[numberOfChild].key[movablePiece], childNode[numberOfChild].key[movablePiece + i]);
        numberOfChild++;
      }
    }

    for (int i = 0; i < numberOfChild; i++)
      childNode[numberOfChild].parent->auxNode;
      
    for (int i = 0; i < numberOfChild; i++) {
      if (childNode[numberOfChild].key == solution)
        break;

      childNode[numberOfChild].g = parentNode.g + 1; // 1 is the distance between the father and child
      childNode[numberOfChild].h = heuristicFive(childNode[numberOfChild].key);
      childNode[numberOfChild].f = childNode[numberOfChild].g + childNode[numberOfChild].h;

      if (!openList.empty())
        for (int i = 0; i < openList.size(); i++) {
          if (childNode[numberOfChild].key == openList[i])
        }
    }


    closedList.push();
    concatenateList.push();
    openList.pop();
  }
}

/*-------int main--------*/
int main () {
   arrayOfTable initialTable;

  for (int i = 0; i < 16; i++) {
    cin >> initialTable[i];
    if (initialTable[i] == 0)
      initialTable[i] = 16;
  }
}
