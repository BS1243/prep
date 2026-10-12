#include "../basic.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> visited;
vector<vector<int>> edges;

int bfs(int start, int n) {
  int size = 1;
  if (visited[start])
    return size;

  queue<int> q;
  visited[start] = 1;
  q.push(start);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      if (!visited[i] && edges[cur][i]) {
        visited[i] = 1;
        size++;
        q.push(i);
      }
    }
  }
  return size;
}

int solution(int n, vector<vector<int>> edge) {
  visited.resize(n, 0);
  edges = edge;
  int count = 0;

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      bfs(i, n);
      count++;
    }
  }
  return count;
}

int main() {
  vector<vector<int>> edge = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};

  cout << solution(3, edge);
}
