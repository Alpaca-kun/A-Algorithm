#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef priority_queue <int, vector<int>, greater<int>> invertedQueue;

int main () {
  invertedQueue q;
  int aux;

  for (int i = 0; i < 10; i++) {
    cin >> aux;
    q.push(aux);
  }
  
  while (!q.empty()) {
    cout << q.top() << " ";
    q.pop();
  }
}
