#include "basic.h"
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
vector<vector<int>> adj;
int maxn = 0;

int bfs(int start) {
  queue<int> q;
  visited[start] = 1;
  q.push(start);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int next : adj[cur]) {
      if (visited[next])
        continue;
      visited[next] = visited[cur] + 1;
      if (maxn < visited[cur] + 1)
        maxn = visited[cur] + 1;
      q.push(next);
    }
  }
  return 1;
}

int solution(int n, vector<vector<int>> edge) {
  adj.resize(n + 1);
  visited.resize(n + 1, 0);
  for (auto row : edge) {
    int a = row[0];
    int b = row[1];
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  bfs(1);
  int cnt=0;
  for(auto i : visited){
    if(i==maxn) cnt++;
  }
  return cnt;
}

int main() {
  int n = 6;
  vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3},
                              {1, 2}, {2, 4}, {5, 2}};

  solution(n, edge);
}
