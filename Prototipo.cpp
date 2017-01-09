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
  double totalCost;
  double costByNode;
  double heuristic;
  node *parent;
};

//hash function for array of int
namespace std {
  template <>
  struct hash<arrayOfTable> {
    size_t operator()(const arrayOfTable& array) const {
      size_t hc = array.size();
      for (int i = 0; i < array.size(); i++)
        hc = hc*314159 + array[i];
    }
  };

  template<>
  struct less<node> {
    bool operator()(const node& list, const node& list2) const {
      return list.totalCost > list2.totalCost;
    }
  };
}

typedef unordered_map <arrayOfTable, node> uMap; //<chave, referencia>
typedef priority_queue <node> pQueue;
typedef multiset <arrayOfTable> mSet;

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

int discoverVacuumPostion (arrayOfTable actualTable) {
  int i = 0;
  
  while (actualTable[i] != 16) 
    i++;

  return i;
}

int aStar (arrayOfTable initialTable) {
  pQueue openList;
  uMap closedList;
  mSet puzzlePatterns;

  node parentNode{initialTable, 0, 0, 0, NULL};
  node childNode[4];

  openList.push(parentNode);

  while(!openList.empty()) {
    uMap::iterator matchKey;

    do {
      parentNode = openList.top();
      openList.pop();
      matchKey = closedList.find(parentNode.key);
    } while (!(matchKey == closedList.end())); // tirei a condicao auto matchKey... do loop e da condicao do while

    closedList.emplace(parentNode.key, parentNode); 

    int numberOfChild = 0;
    int positionOfSpace = discoverVacuumPostion(parentNode.key);
    int xPos = positionOfSpace % 4,
        yPos = positionOfSpace / 4;

    if (yPos != 0) {
      childNode[numberOfChild] = parentNode;
      swap(childNode[numberOfChild].key[positionOfSpace], childNode[numberOfChild].key[positionOfSpace - 4]);
      numberOfChild++;
    }

    if (yPos != 3) {
      childNode[numberOfChild] = parentNode;
      swap(childNode[numberOfChild].key[positionOfSpace], childNode[numberOfChild].key[positionOfSpace + 4]);
      numberOfChild++;
    }

    if (xPos != 0) {
      childNode[numberOfChild] = parentNode;
      swap(childNode[numberOfChild].key[positionOfSpace], childNode[numberOfChild].key[positionOfSpace - 1]);
      numberOfChild++;
    }

    if (xPos != 3) {
      childNode[numberOfChild] = parentNode;
      swap(childNode[numberOfChild].key[positionOfSpace], childNode[numberOfChild].key[positionOfSpace + 1]);
      numberOfChild++;
    }

    for (int i = 0; i < numberOfChild; i++) 
      childNode[i].parent = &(matchKey->second);
  
    for (int i = 0; i < numberOfChild; i++) {
      if (childNode[i].key == solution)
          return childNode[i].totalCost;

      //Change the heuristic functions by demand
      childNode[i].heuristic = heuristicThree(childNode[i].key);
      childNode[i].costByNode = childNode[i].parent->costByNode + 1; // 1 is the height cost
      childNode[i].totalCost = childNode[i].heuristic + childNode[i].costByNode;

      matchKey = closedList.find(childNode[i].key);
      if (!(matchKey == closedList.end()) && (childNode[i].totalCost > matchKey->second.totalCost))
        continue;
      else
        openList.push(childNode[i]);
    }
  }
}


/*-------int main--------*/
int main () {
  arrayOfTable initialTable;
  int result = 0;

  for (int i = 0; i < 16; i++) {
    cin >> initialTable[i];
    if (initialTable[i] == 0)
      initialTable[i] = 16;
  }
  
  result = aStar(initialTable);
  cout << "Resultado: " << result << endl;
}
